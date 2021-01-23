/***********************************************************************************/
/*  Author  :  OsamaMahmoud                                                        */
/*  Date    :  9/9/2020                                                            */
/***********************************************************************************/       
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"

u8 rows[16]={LEDMRX_ROW0_PIN,LEDMRX_ROW1_PIN,LEDMRX_ROW2_PIN,LEDMRX_ROW3_PIN,LEDMRX_ROW4_PIN,
             LEDMRX_ROW5_PIN,LEDMRX_ROW6_PIN,LEDMRX_ROW7_PIN};

u8 cols[16]={LEDMRX_COL0_PIN,LEDMRX_COL1_PIN,LEDMRX_COL2_PIN,LEDMRX_COL3_PIN,LEDMRX_COL4_PIN,
             LEDMRX_COL5_PIN,LEDMRX_COL6_PIN,LEDMRX_COL7_PIN};

volatile u8  Waiting = 10;
volatile u8  No_Animation = 0;
void LEDMRX_voidInit(void)
{
	for(u8 i=0 ; i<=7; ++i)
	{
		DIO_voidSetDirection(rows[i*2] , rows[i*2 + 1] , OUTPUT_PP_2MHZ);
		DIO_voidSetDirection(cols[i*2] , cols[i*2 + 1] , OUTPUT_PP_2MHZ); 	
	}
}

void LEDMRX_voidDispaly(u8 *Copy_u8Data)
{
	while(1)
	{
		for(u8 i=0; i<=7; ++i)
		{
            DisableALLCols();
			SetRowValues(Copy_u8Data[i]);
			DIO_voidSetValue(cols[i*2], cols[i*2 + 1] ,GPIO_LOW);
			MSTK_voidSetBusyWait(2500);
		}
	}
	
}

static void DisableALLCols()
{
	for(u8 j=0; j<=7 ; ++j)
	{
		DIO_voidSetValue(cols[j*2] , cols[j*2 + 1] , GPIO_HIGH);
	}
}


static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	
	for(u8 k=0;k<=7;++k)
	{
		Local_u8BIT=GET_BIT(Copy_u8Value,k);
		DIO_voidSetValue(rows[k*2] , rows[k*2 + 1] , Local_u8BIT);
	}
}
void LEDMRX_voidAnimation(u8 *Copy_u8Data) 
{

	u8 index = 0;
    while(1)
    {
		
        for(index =0 ; index<30 ; ++index)
	    {
		while(No_Animation);
		u8 Local_u8TempData[8]={Copy_u8Data[index],Copy_u8Data[index+1],Copy_u8Data[index+2],Copy_u8Data[index+3],Copy_u8Data[index+4],
							    Copy_u8Data[index+5],Copy_u8Data[index+6],Copy_u8Data[index+7]};
		    for(u8 w=0; w<Waiting; ++w)
		    {
			    for(u8 i=0; i<=7; ++i)
				{
			        DisableALLCols();
					SetRowValues(Local_u8TempData[i]);
					DIO_voidSetValue(cols[i*2], cols[i*2 + 1] ,GPIO_LOW);
					MSTK_voidSetBusyWait(2500);
				}
		    }
	    }
    }
}

void LEDMRX_voidResumeAnimation(void)
{
	No_Animation = 0;
}
void LEDMRX_voidStopAnimation(void)
{
	No_Animation = 1;
}
void LEDMRX_voidSpeedUp(void)
{
	Waiting = Waiting - 2;
}
void LEDMRX_voidSpeedDown(void)
{
	Waiting = Waiting + 2;
}


