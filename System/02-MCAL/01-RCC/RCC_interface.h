/**********************************************************************/
/* Author       : OsamaMahmoud                                        */
/* Version      : V01                                                 */
/* Date         : 8 August 2020                                       */
/**********************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHP   0
#define RCC_APB1  1
#define RCC_APB2  2


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

/* RCC_APB2 */
#define  AFIO_EN     0
#define  IOPA_EN     2
#define  IOPB_EN     3
#define  IOPC_EN     4
#define  IOPD_EN     5
#define  IOPE_EN     6
#define  ADC1_EN     9
#define  ADC2_EN     10
#define  TIM1_EN     11






#endif