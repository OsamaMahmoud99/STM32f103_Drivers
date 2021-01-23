/**************************************************************************************************/
/*  Author   :  OsamaMahmoud                                                                      */
/*  Date     :  7/9/2020                                                                          */
/*  Version  :  V01                                                                               */
/**************************************************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H



void OS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Priodicity , void(*Ptr)(void) , u16 Copy_u16FirstDelay);

void OS_voidStart(void);

void OS_voidSuspendTask(u8 Copy_u8TaskID);
void OS_voidResumeTask(u8 Copy_u8TaskID);
void OS_voidDeleteTask(u8 Copy_u8TaskID);



#endif