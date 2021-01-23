/**************************************************************************************/
/*  Author  : OsamaMahmoud                                                            */
/*  Date    : 14/9/2020                                                               */
/**************************************************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel;


typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;

/* Base Address 0x40020000 of DMA1  on AHP  */
#define  DMA1     ((volatile DMA_t *)0x40020000)



#endif