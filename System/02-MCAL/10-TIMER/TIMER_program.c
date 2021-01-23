/************************************************************************/
/*  Author  : OsamaMahmoud                                              */
/*  Date    : 4/10/2020                                                 */
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

extern const TIMER_config_t configTable[TIMER_NUMBER];
void (* callBackFunc[TIMER_NUMBER])(void);


void TIMER_voidInit(void)
{
	for(TIMER_channels_t i=0 ; i<MAX_TIMERS ; i++)
	{
		if(configTable[i].u8Enable)
		{
			/* Disable Timer */
			CLR_BIT( *(TIM[i]+CR1)  , 0);
			
			/* choose mode */
			switch(configTable[i].u8Mode)
			{
				case UP_COUNTER   :
				        CLR_BIT( *(TIM[i]+CR1) , 4);
                        break;
                case DOWN_COUNTER :
                        SET_BIT( *(TIM[i]+CR1) , 4);
                        break;
                default:
                        break;				
			}
			
			if(configTable[i].u8InterruptEnable)
			{
				SET_BIT( *(TIM[i]+DIER) , 0);
			}
			else{
				CLR_BIT( *(TIM[i]+DIER) , 0);
			}
			
			(*(TIM[i]+PSC)) = (configTable[i].u16Prescaler - 1);
			
			u32 Local_u32Hold = (configTable[i].u32ClkSource / 1000000) * configTable[i].u32Interval;
			Local_u32Hold = Local_u32Hold / configTable[i].u16Prescaler;
			if(Local_u32Hold<65536)
			{
				(*(TIM[i]+ARR)) = Local_u32Hold;
			}
			else{
				 /* Error Code */
			}
			
			/* Start Timer  */
			SET_BIT( *(TIM[i]+CR1)  , 0);
		}
	}
}
void TIMER_voidSetBusyWait(TIMER_channels_t copy_channel , u32 Copy_u32TimeUS)
{
	/* Disable Timer */
	CLR_BIT( *(TIM[copy_channel]+CR1)  , 0);
	
	/* clear flag */
	CLR_BIT( *(TIM[copy_channel]+SR) , 0);
	
	u32 Local_u32Hold = (configTable[copy_channel].u32ClkSource / 1000000) * Copy_u32TimeUS;
	Local_u32Hold = Local_u32Hold / configTable[copy_channel].u16Prescaler;
	if(Local_u32Hold<65536)
	{
		(*(TIM[copy_channel]+ARR)) = Local_u32Hold;
		(*(TIM[copy_channel]+CNT)) = 0;
	}
	else{
			/* Error Code */
	}
	
	/* Start Timer  */
	SET_BIT( *(TIM[copy_channel]+CR1)  , 0);
	
	/* wait for flag */
	while(!(GET_BIT((*(TIM[copy_channel]+SR)) , 0)));
	
	/* Disable Timer */
	CLR_BIT( *(TIM[copy_channel]+CR1)  , 0);
	
	
}
void TIMER_voidSetPeriodic(TIMER_channels_t copy_channel , u32 Copy_u32TimeUS , void (*func)(void))
{
	/* Disable Timer */
	CLR_BIT( *(TIM[copy_channel]+CR1)  , 0);
	
	u32 Local_u32Hold = (configTable[copy_channel].u32ClkSource / 1000000) * Copy_u32TimeUS;
	Local_u32Hold = Local_u32Hold / configTable[copy_channel].u16Prescaler;
	if(Local_u32Hold<65536)
	{
		(*(TIM[copy_channel]+ARR)) = Local_u32Hold;
		
	}
	else{
			/* Error Code */
	}
	
	/* set callback function */
	callBackFunc[copy_channel] = func;
	
	/* Start Timer  */
	SET_BIT( *(TIM[copy_channel]+CR1)  , 0);
	
	/* Enable Interrupt */
	SET_BIT( *(TIM[copy_channel]+DIER) , 0);
	
}
void TIMER_voidDisableOverFlowInterrupt(TIMER_channels_t copy_channel)
{
	CLR_BIT( *(TIM[copy_channel]+DIER) , 0);
}

/********** ISR Handler*************/
void TIM2_IRQHandler(void)
{
	/* clear flag */
	CLR_BIT( (*(TIM[1]+SR)) , 0);
	callBackFunc[1]();
}
void TIM3_IRQHandler(void)
{
	/* clear flag */
	CLR_BIT( (*(TIM[2]+SR)) , 0);
	callBackFunc[2]();
}
void TIM4_IRQHandler(void)
{
	/* clear flag */
	CLR_BIT( (*(TIM[3]+SR)) , 0);
	callBackFunc[3]();
}