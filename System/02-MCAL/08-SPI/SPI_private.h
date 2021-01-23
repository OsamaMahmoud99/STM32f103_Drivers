/****************************************************************************************/
/* Author :  OsamaMahmoud                                                               */
/* Date   :  16/9/2020                                                                  */
/****************************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

static void (*SPI_CallBack)(u16);

typedef struct 
{
	volatile u32 SPI_CR1    ;
	volatile u32 SPI_CR2    ;
    volatile u32 SPI_SR     ;
	volatile u32 SPI_DR     ;
	volatile u32 SPI_CRCPR  ;
	volatile u32 SPI_RXCRCR ;
	volatile u32 SPI_TXCRCR ;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR  ;
	
}SPI_Register;


#define   SPI       ((volatile SPI_Register*)0x40013000) 

/*** Clock Polarity***/
#define   CK_TO_ZERO     0
#define   CK_TO_ONE      1
/*** Clock Phase***/
#define   FIRST_CLOCK    0
#define   SECOND_CLOCK   1
/*** Master Selection***/
#define   MASTER         0
#define   SLAVE          1
/*** Baude Rate***/
#define   FPCLK_2        0b000
#define   FPCLK_4        0b001
#define   FPCLK_8        0b010
#define   FPCLK_16       0b011
#define   FPCLK_32       0b100
#define   FPCLK_64       0b101
#define   FPCLK_128      0b110
#define   FPCLK_256      0b111
/*** SPI Status***/
#define   ENABLE          1
#define   DISABLE         0

/*** Frame Format***/
#define   LSB             0
#define   MSB             1
/**** Software Slave Management***/
#define   SSM_Disabled    0
#define   SSM_ENABLED     1
/**** Receive Only***/
#define   RECEIVE_ONLY    0
#define   RECEIVE_SEND    1
/**** Data Frame format***/
#define   DATA_8BIT       0
#define   DATA_16BIT      1
/***Internal Slave Select***/
#define   EFFECT_SSM      0
#define   NOEFFECT_SSM    1

/* SPI_CR1 Bits */
#define  CPHA       0
#define  CPOL       1
#define  MSTR       2
#define  SPE        6
#define  LSB_FIRST  7
#define  SSI        8
#define  SSM        9
#define  RX_ONLY    10
#define  DFF        11
#define  CRC_NEXT   12
#define  CRC_EN     13
#define  BIDI_OE    14
#define  BIDI_MODE  15
/* SPI_SR Bits */
#define  RXNE       0
#define  TXE        1
#define  CHSIDE     2
#define  UDR        3
#define  CRC_ERR    4
#define  MODF       5
#define  OVR        6
#define  BSY        7 

#endif  