/****************************************************************************/
/* Author  :  OsamaMahmoud                                                  */
/* Date    :  11/9/2020                                                     */
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "DAC_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"


u8 BIT[16]={BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7};
volatile u16 global_u16Index =0;

void DAC_voidInit(void)
{
	for(u8 i=0; i<8; ++i)
	{
		DIO_voidSetDirection(BIT[i*2] , BIT[i*2+1] , MODE_BITS);
	}
}

void DAC_voidSetCallBack(u8 Copy_u8SampleTime , void(*Fptr)(void))
{   DAC_CallBack = Fptr;
	MSTK_voidSetIntervalPeriodic(Copy_u8SampleTime , DAC_CallBack);
}

void DAC_voidSetVoice(u8 *Song)
{
	DIO_voidWritePins(BIT0 , PINS_8 , Song[global_u16Index]);
	global_u16Index++;
	if( j == SIZE_SONG )
	{
		j = 0;
	}
	
}