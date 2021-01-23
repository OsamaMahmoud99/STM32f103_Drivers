/**************************************************************************************************/
/*  Author   :  OsamaMahmoud                                                                      */
/*  Date     :  7/9/2020                                                                          */
/*  Version  :  V01                                                                               */
/**************************************************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define          NULL                   (void*)0

#define          TASK_READY              1
#define          TASK_SUSPENDED          2

static void Scheduler(void);
typedef struct{
	
	u16  priodicity;
	void (*TaskHandler)(void);
	u16  FirstDelay;
	u8   State;
	
}TASk;

static TASK OS_TASKS[NUMBER_OF_TASKS] = { NULL };

static void Scheduler(void)
{
	static u8 Local_u8TaskCounter;
	
	for(Local_u8TaskCounter=0; Local_u8TaskCounter<NUMBER_OF_TASKS; Local_u8TaskCounter++)
	{
		if((OS_TASKS[Local_u8TaskCounter].TaskHandler != NULL) && (OS_TASKS[Local_u8TaskCounter].State == TASK_READY))
		{
			if(OS_TASKS[Local_u8TaskCounter].FirstDelay == 0)
			{
				OS_TASKS[Local_u8TaskCounter].FirstDelay = OS_TASKS[Local_u8TaskCounter].priodicity-1;
				OS_TASKS[Local_u8TaskCounter].TaskHandler();
			}
			else
			{
				OS_TASKS[Local_u8TaskCounter].FirstDelay--;
			}
			
		}
		else
		{
			/* Do Nothing */
		}
		
	}
    
}




#endif