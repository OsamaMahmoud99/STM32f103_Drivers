/****************************************************************************************/
/* Author :  OsamaMahmoud                                                               */
/* Date   :  16/9/2020                                                                  */
/****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI1_voidInit(void)
{
	#if   SPI1_CLK_PHASE  == FIRST_CLOCK          // Read then Write
	CLR_BIT(SPI -> SPI_CR1 , CPHA);
	#elif SPI1_CLK_PHASE  == SECOND_CLOCK         // Write then Read
	SET_BIT(SPI -> SPI_CR1 , CPHA);
	#endif
	
	#if   SPI1_CLK_POLARITY == CK_TO_ZERO         //Rising
	CLR_BIT(SPI -> SPI_CR1 , CPOL);
	#elif SPI1_CLK_POLARITY == CK_TO_ONE          //Falling
	SET_BIT(SPI -> SPI_CR1 , CPOL);
	#endif
	
	
	#if    SPI1_MASTER_CONFIG  == MASTER
	SET_BIT(SPI -> SPI_CR1 , MSTR);
	#elif  SPI1_MASTER_CONFIG  == SLAVE 
	CLR_BIT(SPI -> SPI_CR1 , MSTR);
	#endif
	
	#if   SPI1_SOFTWARE_SLAVE == SSM_DISABLED
	CLR_BIT(SPI -> SPI_CR1 , SSM);
	#elif SPI1_SOFTWARE_SLAVE == SSM_ENABLED
	SET_BIT(SPI -> SPI_CR1 , SSM);
	#endif
	
	#if   SPI1_INTERNAL_SLAVE == EFFECT_SSM
	SET_BIT(SPI -> SPI_CR1 , SSI);
	#elif SPI1_INTERNAL_SLAVE == NOEFFECT_SSM
	CLR_BIT(SPI -> SPI_CR1 , SSI);
	#endif
	
	#if   SPI1_RECEIVE == RECEIVE_SEND
	CLR_BIT(SPI -> SPI_CR1 , RX_ONLY);
	#elif SPI1_RECEIVE == RECEIVE_ONLY
	SET_BIT(SPI -> SPI_CR1 , RX_ONLY);
	#endif
	
	#if   SPI1_DATA_FRAME == DATA_8BIT
	CLR_BIT(SPI -> SPI_CR1 , DFF);
	#elif SPI1_DATA_FRAME == DATA_16BIT
	SET_BIT(SPI -> SPI_CR1 , DFF);
	#endif
	
	SPI->SPI_CR1|= (SPI1_BAUDE_RATE <<3);
	
	#if   SPI1_FRAME_FORMAT == LSB
	SET_BIT(SPI -> SPI_CR1 , LSB_FIRST);
	#elif SPI1_FRAME_FORMAT == MSB
	CLR_BIT(SPI -> SPI_CR1 , LSB_FIRST);
	#endif
	
	
	CLR_BIT(SPI -> SPI_CR1 , CRC_NEXT);
	CLR_BIT(SPI -> SPI_CR1 , CRC_EN);
	CLR_BIT(SPI -> SPI_CR1 , BIDI_OE);
	CLR_BIT(SPI -> SPI_CR1 , BIDI_MODE);
	
	#if   SPI1_STATUS == ENABLE
	SET_BIT(SPI -> SPI_CR1 , SPE);
	#elif SPI1_STATUS == DISABLE
	CLR_BIT(SPI -> SPI_CR1 , SPE);
	#endif
	
}
void SPI1_voidInitMaster(void)
{
	DIO_voidSetDirection(GPIOA , 7 , OUTPUT_PP_2MHZ);  /* MOSI*/
	DIO_voidSetDirection(GPIOA , 5 , OUTPUT_PP_2MHZ);  /* SCK1*/
	DIO_voidSetDirection(GPIOA , 6 , INPUT_FLOATING);  /* MISO*/
	
}
void SPI1_voidInitSlave(void)
{   
    DIO_voidSetDirection(GPIOA , 6 , OUTPUT_PP_2MHZ);  /* MISO*/
	DIO_voidSetDirection(GPIOA , 5 , INPUT_FLOATING);  /* SCK1*/
	DIO_voidSetDirection(GPIOA , 7 , INPUT_FLOATING);  /* MOSI*/
}
void SPI1_voidSendReceiveSynch(u16 Copy_u16DataToTransmit , u16 *Copy_DataToReceive)
{
	DIO_voidSetValue(SPI_SLAVE_PIN , GPIO_LOW);
	
	/* Send Data */
	SPI -> SPI_DR = Copy_u16DataToTransmit;
	/* Wait Busy Flag to finish */
	while(GET_BIT(SPI -> SPI_SR , BSY) == 1);
	/* receive data */
	*Copy_DataToReceive = SPI -> SPI_DR;
	
	DIO_voidSetValue(SPI_SLAVE_PIN , GPIO_HIGH);
	
}

void SPI1_voidSendReceiveAsynch(u16 Copy_u16DataToTransmit , void (*CallBack)(u16))
{
	SPI_CallBack = CallBack;
	SPI -> SPI_DR = Copy_u16DataToTransmit;
}


void SPI1_IRQHandler(void)
{   
    /* clear flag */
    CLR_BIT( SPI -> SPI_SR , RXNE );
	/* Receive Data */
	u16 Local_u16ReceData = ((u16*)(SPI -> SPI_DR));
	/* call function */
	SPI_CallBack(Local_u16ReceData);
}