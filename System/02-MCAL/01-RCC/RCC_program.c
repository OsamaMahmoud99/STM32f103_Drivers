/**********************************************************************/
/* Author       : OsamaMahmoud                                        */
/* Version      : V01                                                 */
/* Date         : 8 August 2020                                       */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
  #if     RCC_CLOCK_TYPE == RCC_HSI
      RCC_CR   = 0x00000081;  /*Enable HSI + Trimming = 0 */
      RCC_CFGR = 0x00000000;
  
  #elif   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
      RCC_CR   = 0x00010000;  /* Enable HSE With NO bypass */
      RCC_CFGR = 0x00000001;
  
  #elif   RCC_CLOCK_TYPE == RCC_HSE_RC
      RCC_CR   = 0x00050000;  /* Enable HSE With bypass */
	  RCC_CFGR = 0x00000001;
	 
  #elif   RCC_CLOCK_TYPE == RCC_PLL
  
  RCC_CFGR |= (RCC_PLL_MUL_VAL <<18);
  
      #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2 
   
		
		CLR_BIT(RCC_CFGR, 16);  /* Enable HSI Clock /2 */
		SET_BIT(RCC_CR  ,  0);  /* Enable HSI */ 
		CLR_BIT(RCC_CFGR,  0);  
		SET_BIT(RCC_CFGR,  1);  /* Select_PLL   */
		SET_BIT(RCC_CR  , 24);  /* Enable PLL */
	   
	  #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	  
		SET_BIT(RCC_CFGR, 17);
		SET_BIT(RCC_CR  , 16);
		CLR_BIT(RCC_CFGR,  0); 
		SET_BIT(RCC_CFGR,  1);    /*Select_PLL */
		SET_BIT(RCC_CR  , 24);
		
	  
	  #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	  
		SET_BIT(RCC_CFGR, 16);
		SET_BIT(RCC_CR  , 16);
		CLR_BIT(RCC_CFGR,  0); 
		SET_BIT(RCC_CFGR,  1);   /*Select_PLL  */
		SET_BIT(RCC_CR  , 24);
	 
	  #endif
	  
       
  #else
      #error("You chosed Wrong Clock type")
  #endif  
}
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
      if(Copy_u8PerId<=31)
	  {
	     switch(Copy_u8BusId)
		 {
		   case RCC_AHP  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId); break;
		   case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId); break; 
		   case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId); break;
		   //default       : /* Return Error */                break;
		 }
	  }
	  else
	  {
	     /* Return Error */
	  }
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
      if(Copy_u8PerId<=31)
	  {
	     switch(Copy_u8BusId)
		 {
		   case RCC_AHP  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId); break;
		   case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId); break; 
		   case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId); break;
		   //default     : /* Return Error */                  break;
		 }
	  }
	  else
	  {
	     /* Return Error */
	  }
}