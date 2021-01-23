/**************************************************************************************************/
/*  Author   :  OsamaMahmoud                                                                      */
/*  Date     :  7/9/2020                                                                          */
/*  Version  :  V01                                                                               */
/**************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"



void OS_voidCreateTask(u8 Copy_u8TaskID,u16 Copy_u16Priodicity,void(*Ptr)(void),u16 Copy_u16FirstDelay)
{
	OS_TASKS[Copy_u8TaskID].priodicity = Copy_u16Priodicity;
	OS_TASKS[Copy_u8TaskID].TaskHandler= Ptr;
	OS_TASKS[Copy_u8TaskID].FirstDelay = Copy_u16FirstDelay;
	OS_TASKS[Copy_u8TaskID].State      = TASK_READY;
}

void OS_voidStart(void)
{
	MSTK_voidInit();
	/*Tick 1msec */
	MSTK_voidSetIntervalPriodic(1000,Scheduler);
}

void OS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OS_TASKS[Copy_u8TaskID].State = TASK_SUSPENDED;
}
void OS_voidResumeTask(u8 Copy_u8TaskID)
{
    OS_TASKS[Copy_u8TaskID].State = TASK_READY;	
}
void OS_voidDeleteTask(u8 Copy_u8TaskID)
{
	OS_TASKS[Copy_u8TaskID].TaskHandler = NULL;
}

