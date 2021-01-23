/***************************************************************************************************/
/*  Author   :  OsamaMahmoud                                                                       */
/*  Date     :  24/8/2020                                                                          */
/*  Version  :  V01                                                                                */
/***************************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H



void EXTI_voidInit();
void EXTI_voidEnable(u8 Copy_u8Line);
void EXTI_voidDisable(u8 Copy_u8Line);
void EXTI_voidSwTrigger(u8 Copy_u8Line);
void EXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8MODE);
void EXTI_voidSetCallBack(u8 Copy_u8Line , void (*Fptr)(void));

#define RISING         1
#define FALLING        3
#define ON_CHANGE      5

#define LINE0          0
#define LINE1          1
#define LINE2          2
#define LINE3          3
#define LINE4          4
#define LINE5          5
#define LINE6          6
#define LINE7          7
#define LINE8          8
#define LINE9          9
#define LINE10         10
#define LINE11         11
#define LINE12         12
#define LINE13         13
#define LINE14         14
#define LINE15         15




#endif