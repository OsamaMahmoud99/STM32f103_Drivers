/********************************************************************/
/*  Author     :  OsamaMahmoud                                      */
/*  Date       :  9/9/2020                                          */
/********************************************************************/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H



#define   POWER   69
#define   MODE    70
#define   BLUE    68
#define   ZERO    22
#define   ONE     12
#define   TWO     24
#define   THREE   94
#define   FOUR    8
#define   FIVE    0
#define   SIX     90
#define   SEVEN   66
#define   EIGHT   82
#define   NINE    74


void IR_voidGetFrame(void);
void voidTakeAction(void);
void IR_voidSetCallBack( void(*Fptr)(u8 Key_Data) );









#endif