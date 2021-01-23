/**********************************************************************/
/* Author       : OsamaMahmoud                                        */
/* Version      : V01                                                 */
/* Date         : 8 August 2020                                       */
/**********************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definitions */

#define RCC_CR            *((volatile u32*)0x40021000)
#define RCC_CFGR          *((volatile u32*)0x40021004)
#define RCC_CIR           *((volatile u32*)0x40021008)
#define RCC_APB2RSTR      *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR      *((volatile u32*)0x40021010)
#define RCC_AHBENR        *((volatile u32*)0x40021014)
#define RCC_APB2ENR       *((volatile u32*)0x40021018)
#define RCC_APB1ENR       *((volatile u32*)0x4002101C)
#define RCC_BDCR          *((volatile u32*)0x40021020)
#define RCC_CSR           *((volatile u32*)0x40021024)
#define RCC_AHBSTR        *((volatile u32*)0x40021028)
#define RCC_CFGR2         *((volatile u32*)0x4002102C)

/* Clock Types */ 

#define RCC_HSI                0
#define RCC_HSE_CRYSTAL        1
#define RCC_HSE_RC             2
#define RCC_PLL                3

/* PLL Options */

#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2

/* PLL Multiplication Factor */

#define PLL_INPUT_CLOCK_X2    0
#define PLL_INPUT_CLOCK_X3    1
#define PLL_INPUT_CLOCK_X4    2
#define PLL_INPUT_CLOCK_X5    3
#define PLL_INPUT_CLOCK_X6    4
#define PLL_INPUT_CLOCK_X7    5
#define PLL_INPUT_CLOCK_X8    6
#define PLL_INPUT_CLOCK_X9    7
#define PLL_INPUT_CLOCK_X10   8
#define PLL_INPUT_CLOCK_X11   9
#define PLL_INPUT_CLOCK_X12   10
#define PLL_INPUT_CLOCK_X13   11
#define PLL_INPUT_CLOCK_X14   12
#define PLL_INPUT_CLOCK_X15   13
#define PLL_INPUT_CLOCK_X16   14






#endif