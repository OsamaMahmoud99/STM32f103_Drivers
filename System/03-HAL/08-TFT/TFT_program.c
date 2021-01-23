/*****************************************************/
/* Author  :  OsamaMahmoud                           */
/* Date    :  21/9/2020                              */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void TFT_voidInitialize(void)
{
	DIO_voidSetValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	DIO_voidSetValue(TFT_RST_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	DIO_voidSetValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	DIO_voidSetValue(TFT_RST_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(100);
	DIO_voidSetValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);
	
	WriteCommand(0x11);
	MSTK_voidSetBusyWait(1500000);
	WriteCommand(0x3A);
	WriteDate(0x05);
	
	WriteCommand(0x29);
}
void TFT_voidDispalyImage(const u16* Copy_Image)
{
	 u16 counter;
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(127);

	WriteCommand(0x2B);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(159);

	WriteCommand(0x2C);

		for(counter =0; counter<20480; counter++)
		{
			WriteData(Copy_Image[counter] >> 8);
			WriteData(Copy_Image[counter] & 0x00ff);
		}
}
void TFT_voidFillColor(u16 Copy_u16Color)
{
	u16 counter;
	u8  Data;
	/* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(127);
	
    /* Set Y Address */
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(159);
    
	/* RAM Write */
	WriteCommand(0x2C);

		for(counter =0; counter<20480; counter++)
		{
			Data = Copy_u16Color >> 8;
			
			/* Write the high byte */
			WriteData(Data);
			/* Write the low byte  */
			Data = Copy_u16Color & 0x00ff;
			WriteData(Data);
		}
}

void TFT_voidDrawRect(u8 x1 , u8 x2 , u8 y1 ,u8 y2 , u16 Copy_u16Color)
{
	u16 counter;
	u8  Data;
	u16 Size =(x2-x1) * (y2 -y1);
	/* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(127);
	
    /* Set Y Address */
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(159);
    
	/* RAM Write */
	WriteCommand(0x2C);

		for(counter =0; counter<Size ; counter++)
		{
			Data = Copy_u16Color >> 8;
			
			/* Write the high byte */
			WriteData(Data);
			/* Write the low byte  */
			Data = Copy_u16Color & 0x00ff;
			WriteData(Data);
		}
}

static void WriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	DIO_voidSetValue(TFT_A0_PIN , GPIO_LOW);
	MSPI1_voidSendReceiveSynch(Copy_u8Command , &Local_u8Temp);
}

static void WriteDate(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	DIO_voidSetValue(TFT_A0_PIN , GPIO_HIGH);
	MSPI1_voidSendReceiveSynch(Copy_u8Data , &Local_u8Temp);
}