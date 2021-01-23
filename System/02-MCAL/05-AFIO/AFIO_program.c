/*******************************************************************************************/
/*  Author   :  Osama mahmoud                                                              */
/*  Date     :  24/8/2020                                                                  */
/*******************************************************************************************/



void  AFIO_voidSetEXTIConfig(u8 Copy_u8Line ,u8 Copy_u8PortMap)
{
	u8 Local_u8RedIndex = 0;
	
	if (Copy_u8Line <= 3)
	{
		Local_u8RedIndex = 0;
	}
	else if(Copy_u8Line <= 7)
	{   
            /*	another	solution									*/
			/*	line 7 => 1.... 									*/
			/*	Local_u8RegIndex = copy_u8Line/4					*/
			/*	copy_u8Line = copy_u8Line%4 => (3 in the EXTICR2)	*/	
		Copy_u8Line -= 4;
		Local_u8RedIndex = 1;
		
	}
	else if(Copy_u8Line <= 11)
	{
		Copy_u8Line -= 8;
		Local_u8RedIndex = 2;
		
	}
	else if(Copy_u8Line <= 15)
	{
		Copy_u8Line -= 12;
		Local_u8RedIndex = 3;
		
	}
	AFIO -> EXTICR[Local_u8RedIndex] &= ~((0b1111) << (Copy_u8Line*4));
	AFIO -> EXTICR[Local_u8RedIndex] |=  ((Copy_u8PortMap) << (Copy_u8Line*4));
}