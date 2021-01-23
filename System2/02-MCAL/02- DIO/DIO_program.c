/*******************************************************************/
/* Author  : Osama Mahmoud                                         */
/* Date    : 9/4/2020                                              */
/*******************************************************************/
#include "DIO_interface.h"

extern void DIO_Init(void)
{
	u8 PinNum_InPort;
	Port_Type Port;
	Mode_Type Status;
	u8 LocalIterator;
	
	for(LocalIterator = 0;LocalIterator<TOTAL_PINS;LocalIterator++)
	{
		Status = PinsStatus[LocalIterator];
		Port   = LocalIterator/16;
		PinNum_InPort=LocalIterator%16;
		
		switch(Status)
		{
			case OUTPUT_PP_2MHZ : 
			switch(Port)
			{
				case PA :
				if(PinNum_InPort <=7)
				{
					GPIOA_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOA_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOA_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOA_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				case PB :
				if(PinNum_InPort <=7)
				{
					GPIOB_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOB_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOB_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOB_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				case PC :
				if(PinNum_InPort <=7)
				{
					GPIOC_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOC_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOC_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOC_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				
			}
			break;
			case INPUT_FLOATING :
			switch(Port)
			{
				case PA :
				if(PinNum_InPort <=7)
				{
					GPIOA_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOA_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOA_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOA_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				case PB :
				if(PinNum_InPort <=7)
				{
					GPIOB_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOB_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOB_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOB_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				case PC :
				if(PinNum_InPort <=7)
				{
					GPIOC_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOC_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOC_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOC_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				
			}
			break;
			case INPUT_PP_PD :
			switch(Port)
			{
				case PA :
				if(PinNum_InPort <=7)
				{
					GPIOA_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOA_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOA_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOA_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				case PB :
				if(PinNum_InPort <=7)
				{
					GPIOB_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOB_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOB_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOB_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				case PC :
				if(PinNum_InPort <=7)
				{
					GPIOC_CRL &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOC_CRL |=  ((Status)<<(PinNum_InPort*4));
				}
				else if(PinNum_InPort <=15)
				{ 
			        GPIOC_CRH &= ~((0b1111)<<(PinNum_InPort*4));
			        GPIOC_CRH |=  ((Status)<<(PinNum_InPort*4));
				}
				break;
				
			}
			break;
			
		}
	}
}
extern void DIO_WritePin(PinNum_type Pin,Voltage_Type Value)
{
	u8 PinNum_InPort=Pin%16;
	Port_Type Port=Pin/16;
	
	switch (Port)
	{
		case PA:
		if (HIGH==Value)
		{
			SET_BIT(GPIOA_ODR,PinNum_InPort);
		}
		else
		{
			CLR_BIT(GPIOA_ODR,PinNum_InPort);
		}
		break;
		case PB:
		if (HIGH==Value)
		{
			SET_BIT(GPIOB_ODR,PinNum_InPort);
		}
		else
		{
			CLR_BIT(GPIOB_ODR,PinNum_InPort);
		}
		break;
		case PC:
		if (HIGH==Value)
		{
			SET_BIT(GPIOC_ODR,PinNum_InPort);
		}
		else
		{
			CLR_BIT(GPIOC_ODR,PinNum_InPort);
		}
		break;
		default :
		            break;
}

extern Voltage_Type DIO_ReadPin(PinNum_type Pin)
{
	u8 PinNum_InPort=Pin%16;
	Port_Type Port=Pin/16;
	
	switch(Port)
	{
		case PA : 
		return GET_BIT(GPIOA_IDR , PinNum_InPort);
		break;
		case PB:
		return GET_BIT(GPIOB_IDR , PinNum_InPort);
		break;
		case PC :
		return GET_BIT(GPIOC_IDR , PinNum_InPort);
		default :
		return 0;
		break;
		
	}
}

extern void DIO_WritePort(Port_Type Port,u8 Value)
{
	switch(Port)
	{
		case PA :
		SET_PORT(GPIOA_ODR , value);
		break;
		case PB : 
		SET_PORT(GPIOB_ODR , Value);
		break;
		case PC :
		SET_PORT(GPIOC_ODR , Value);
		break;
	}
}