/**************************************************************************************/
/*  Author  : OsamaMahmoud                                                            */
/*  Date    : 14/9/2020                                                               */
/**************************************************************************************/


void DMA_voidInitChannel(void)
{   /* 
        1- mem to mem 
		2- Very High
		3- source size , destination size =32 bit
		4- MINC , PINC activated
		5- no circuiler
		6- direction :
		7- transfer interrupt enable 
		
	*/
	#if CHANNEL_ID == 1
	
	    #if    MEM2MEM == ENABLE
	           SET_BIT(DMA -> Channel[0].CCR , 14);
	    #elif  MEM2MEM == DISABLE
	           CLR_BIT(DMA -> Channel[0].CCR , 14);
	    #if    PRIORITY_LEVEl == Low
	           CLR_BIT(DMA -> Channel[0].CCR , 12);
			   CLR_BIT(DMA -> Channel[0].CCR , 13);
		#elif  PRIORITY_LEVEl == Medium  
		       SET_BIT(DMA -> Channel[0].CCR , 12);
			   CLR_BIT(DMA -> Channel[0].CCR , 13);
		#elif  PRIORITY_LEVEl == High 
		       CLR_BIT(DMA -> Channel[0].CCR , 12);
			   SET_BIT(DMA -> Channel[0].CCR , 13);
		#elif  PRIORITY_LEVEl == VeryHigh
		       SET_BIT(DMA -> Channel[0].CCR , 12);
			   SET_BIT(DMA -> Channel[0].CCR , 13);
	 
	 
	DMA -> Channel[0].CCR = 
}

void DMA_voidStartChannel(u32 *Copy_Pu32SourceAdrress,u32 *Copy_Pu32DestinationAdrress,u16 Copy_u16BlockLength)
{
	CLR_BIT(DMA -> Channel[0].CCR , 0);
	
	DMA -> Channel[0].CPAR = Copy_Pu32SourceAdrress;
	DMA -> Channel[0].CMAR = Copy_Pu32DestinationAdrress;
	
	DMA -> Channel[0].CNDTR = Copy_u16Locklength;
	
	SET_BIT(DMA -> Channel[0].CCR , 0);
}