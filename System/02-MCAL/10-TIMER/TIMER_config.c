/************************************************************************/
/*  Author  : OsamaMahmoud                                              */
/*  Date    : 4/10/2020                                                 */
/************************************************************************/

#include "STD_TYPES.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"



const TIMER_config_t configTable[TIMER_NUMBER]={
	//         Timer        Timermode        Interrupt  CLKsource     prescaler   Interval in US
	{TIM1   ,  DISABLE   ,  UP_COUNTER   ,    DISABLE  , APB2_CLK   ,  128  ,      0},
	{TIM2   ,  DISABLE   ,  UP_COUNTER   ,    DISABLE  , APB1_CLK   ,  8    ,      0},
	{TIM3   ,  ENABLE    ,  UP_COUNTER   ,    DISABLE  , APB1_CLK   ,  128  ,      0},
	{TIM4   ,  DISABLE   ,  UP_COUNTER   ,    DISABLE  , APB1_CLK   ,  128  ,      0}
	
	
};