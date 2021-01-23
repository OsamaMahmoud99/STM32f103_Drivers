/****************************************************************/
/* Author    : Osama Mahmoud                                    */
/* Date      : 28 SEP 2020                                      */
/* Version   : V01                                              */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

u8 Global_u8Result;

void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		USART1_voidTransmit("ATE0\r\n");
		Local_u8Result = ESP_u8pValidateCmd();
	}
	
	Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Set station mode */
		USART1_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result = ESP_u8pValidateCmd();
	}
}

void ESP_voidConnectOnWifi(void)
{
	u8 Local_u8Response[100]={0};
	u8 Local_u8Result = 0;
	
	while(Local_u8Response == 0)
	{
		USART1_voidTransmit("AT+CWJAP_CUR=" "\"osama2222\"" "," "\"011283740934093\"\r\n");
		Local_uResult = ESP_u8pValidateCmd();
		
	}
	
}
void ESP_voidConnectOnServer(void)
{
	u8 Local_u8Response[100]={0};
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		USART1_voidTransmit("AT+CIPSTART=" "\"TCP\"" "," "\"162.253.155.226\",80\r\n");
		Local_uResult = ESP_u8pValidateCmd();
	}
	
}
u8 ESP_u8SendData(void)
{
	u8 Local_u8Data[100]={0};
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		USART1_voidTransmit("AT+CIPSEND=48\r\n");
		Local_u8Result = ESP_u8pValidateCmd();
	}
	Local_u8Result = 0;
	while(Local_u8Result == 0)
	{
		USART1_voidTransmit("GET http://osamamahmoud.freevar.com/status.txt\r\n");
		Local_u8Result = ESP_u8pValidateCmd();
	}
	
	return Global_u8Result;
}

static u8 voidEspValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;
	
	while (i<=100)
	{
		Dummy = MUSART1_u8Receive();
		Local_u8Response[i] = Dummy;
		i++;
	}
	
	for(u8 i=0 ;i<70; i++)
	{
		if(Local_u8Response[i] == ':')
		{
			Global_u8Result = Local_u8Response[i+1];
		}
	}
	/* Check if Ok */
	
	for(u8 i =0 ;i<100;i++)
	{
	  if (Local_u8Response[i] == 'O' && Local_u8Response[i+1] == 'K')
	  {
		Result = 1;
		break;
	  }
	}
	
	return Result;
}
