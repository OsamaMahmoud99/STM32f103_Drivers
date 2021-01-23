





int main(void)
{
	
	
	
	OS_voidCreateTask(0 , 1000 ,LED1 );
	OS_voidCreateTask(1 , 2000 ,LED2 );
	OS_voidCreateTask(2 , 3000 ,LED3 );
	OS_voidStart();
	while(1)
	{
		
	}
	return 0;
}

void LED1()
{
	static u8 Local_u8pin0 = 0;
	TOG_BIT(Local_u8pin0 , 0);
	DIO_voidSetValue(GPIOA , 0 , Local_u8pin0);
}
void LED2()
{
	static u8 Local_u8pin1 = 0;
	TOG_BIT(Local_u8pin1 , 0);
	DIO_voidSetValue(GPIOA , 1 , Local_u8pin1);
}
void LED3()
{
	static u8 Local_u8pin2 = 0;
	TOG_BIT(Local_u8pin2 , 0);
	DIO_voidSetValue(GPIOA , 2 , Local_u8pin2);
}