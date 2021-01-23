/************************************************************************/
/*  Author  : OsamaMahmoud                                              */
/*  Date    : 4/10/2020                                                 */
/************************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


typedef enum{
	
	TIM1,
	TIM2,
	TIM3,
	TIM4,
	MAX_TIMERS
	
}TIMER_channels_t;


void TIMER_voidInit(void);
void TIMER_voidSetBusyWait(TIMER_channels_t copy_channel , u32 Copy_u32TimeUS);
void TIMER_voidSetPeriodic(TIMER_channels_t copy_channel , u32 Copy_u32TimeUS , void (*func)(void));
void TIMER_voidDisableOverFlowInterrupt(TIMER_channels_t copy_channel);










#endif