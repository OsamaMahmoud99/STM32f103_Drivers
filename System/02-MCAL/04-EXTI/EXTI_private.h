/***************************************************************************************************/
/*  Author   :  OsamaMahmoud                                                                       */
/*  Date     :  24/8/2020                                                                          */
/*  Version  :  V01                                                                                */
/***************************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


void (*EXTI_CallBack[15])(void);

typedef struct {
	
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_t;

#define EXTI   ((volatile EXTI_t *)0x40010400)    /* pointer to struct */




#endif