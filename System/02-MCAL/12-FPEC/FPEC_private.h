/*****************************************************************/
/* Author  : OsamaMahmoud                                        */
/* Date    : 12/10/2020                                          */
/*****************************************************************/
#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H


typedef struct 
{
	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_AR;
	volatile u32 RESERVED;
	volatile u32 FLASH_OBR;
	volatile u32 FLASH_WRPR;
	
}FPEC_Registers;

#define  FPEC  ((FPEC_Registers*)0x40022000)

/* FLASH_SR */
#define  BSY      0
#define  PGERR    2
#define  WRPRTERR 4
#define  EOP      5

/* FLASH_CR */
#define  PG     0
#define  PER    1 
#define  MER    2
#define  OPTPG  4
#define  OPTER  5
#define  STRT   6
#define  LOCK   7
#define  OPTWRE 9
#define  ERRIE  10
#define  EOPIE  12

/* Key values */
#define  KEY1  0x45670123
#define  KEY2  0xCDEF89AB
#define  RDPRT 0x00A5




#endif