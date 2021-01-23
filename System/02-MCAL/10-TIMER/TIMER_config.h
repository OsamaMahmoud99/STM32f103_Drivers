/************************************************************************/
/*  Author  : OsamaMahmoud                                              */
/*  Date    : 4/10/2020                                                 */
/************************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H


#define  APB2_CLK    8000000
#define  APB1_CLK    8000000



#define  TIMER_NUMBER    4



typedef struct{
	
	u8  u8Channel;
	u8  u8Enable;
	u8  u8Mode;
	u8  u8InterruptEnable;
	u32 u32ClkSource;
	u16 u16Prescaler;
	u32 u32Interval;
	
}TIMER_config_t;

#define   ENABLE    1
#define   DISABLE   0

#define   UP_COUNTER    0
#define   DOWN_COUNTER  1



#endif