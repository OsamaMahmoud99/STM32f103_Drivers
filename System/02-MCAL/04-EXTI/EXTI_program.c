/***************************************************************************************************/
/*  Author   :  OsamaMahmoud                                                                       */
/*  Date     :  24/8/2020                                                                          */
/*  Version  :  V01                                                                                */
/***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


void EXTI_voidInit()
{
	#if   EXTI_MODE    ==  RISING
	SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif EXTI_MODE    ==  FALLING
    SET_BIT(EXTI -> FTSR , EXTI_LINE);
    #elif EXTI_MODE    ==  ON_CHANGE
    SET_BIT(EXTI -> RTSR , EXTI_LINE);	
	SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else  #error "Wrong Mode"
	
	 /* Disable Interrupt */
	CLR_BIT(EXTI -> IMR , Copy_u8Line);
	
	#endif
}
void EXTI_voidEnable(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> IMR , Copy_u8Line);
}
void EXTI_voidDisable(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> IMR , Copy_u8Line);
}
void EXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
}
void EXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8MODE)
{
	switch(Copy_u8MODE)
	{
		case RISING    :
		SET_BIT(EXTI -> RTSR , Copy_u8Line);
		break;
		case FALLING   :
		SET_BIT(EXTI -> FTSR , Copy_u8Line);
		break;
		case ON_CHANGE :
		SET_BIT(EXTI -> RTSR , Copy_u8Line);	
	    SET_BIT(EXTI -> FTSR , Copy_u8Line);
		break;
		
	}
}
void EXTI_voidSetCallBack(u8 Copy_u8Line , void (*Fptr)(void))
{
	
    EXTI_CallBack[Copy_u8Line] = Fptr ;
	
}
void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	/* Clear this bit by writing 1 */
	SET_BIT(EXTI -> PR , 0);
}
void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();
	/* Clear this bit by writing 1 */
	SET_BIT(EXTI -> PR , 1);
}