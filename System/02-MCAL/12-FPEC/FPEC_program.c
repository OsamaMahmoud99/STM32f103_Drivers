/*****************************************************************/
/* Author  : OsamaMahmoud                                        */
/* Date    : 12/10/2020                                          */
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#Include "FPEC_interface.h"
#include "FPEC_config.h"
#include "FPEC_private.h"


void FPEC_voidFlashWrite(u32 Copy_u32Address , u16 *Copy_u16Data , u8 Copy_u8Length)
{
	u8 i;
	volatile u16 Temp;

	while (GET_BIT(FPEC->FLASH_SR,BSY) == 1);
	
	if(GET_BIT(FPEC->FLASH_CR , LOCK)== 1)
	{
	  FPEC->FLASH_KEYR = KEY1;
      FPEC->FLASH_KEYR = KEY2;	  
	}
	
	for (i = 0; i< Copy_u8Length; i++)
	{
		/* Write Flash Programming */
		SET_BIT(FPEC->FLASH_CR,PG);

		/* Half word operation */

		Temp = Copy_u16Data[i];
		*((volatile u16*)Copy_u32Address) = Copy_u16Data[i];
		Copy_u32Address += 2 ;

		/* Wait Busy Flag */
		while (GET_BIT(FPEC->FLASH_SR,BSY) == 1);
	
		/* EOP */
		SET_BIT(FPEC->FLASH_SR,EOP);
		CLR_BIT(FPEC->FLASH_CR,PG);
	}
}
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber)
{
	/* wait till erase is done */
	while(GET(FPEC->FLASH_SR , BSY));
	
	if(GET_BIT(FPEC->FLASH_CR , LOCK)== 1)
	{
	  FPEC->FLASH_KEYR = KEY1;
      FPEC->FLASH_KEYR = KEY2;	  
	}
	
	/* enable erase for page */
	SET_BIT(FPEC->FLASH_CR , PER);
	
	/* write address for page */
	FPEC->FLASH_AR = (u32)(Copy_u8PageNumber*1024)+0x8000000;
	
	/* trigger an erase operation */
	SET(FPEC->FLASH_CR , STRT);
	
	/* wait till erase is done */
	while(GET(FPEC->FLASH_SR , BSY));
	
	/* Disable erase for page */
	SET_BIT(FPEC->FLAsh_SR , EOP);
	CLR_BIT(FPEC->FLASH_CR , PER);
}
void FPEC_voidMassErase(void)
{
	if(GET_BIT(FPEC->FLASH_CR , LOCK)== 1)
	{
	  FPEC->FLASH_KEYR = KEY1;
      FPEC->FLASH_KEYR = KEY2;	  
	}
	
	/* enable erase for Mass */
	SET_BIT(FPEC->FLASH_CR , MER);
	
	/* trigger an erase operation */
	SET(FPEC->FLASH_CR , STRT);
	
	/* wait till erase is done */
	while(GET(FPEC->FLASH_SR , BSY));
	
}