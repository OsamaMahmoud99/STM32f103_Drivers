
int main(void)
{
  u32 Arr1[1000] = {0};
  u32 Arr2[1000];
  
  u32 Arr3[1000] = {0};
  u32 Arr4[1000];
  
  RCC_voidinitSyClock();
  RCC_voidEnableClock(RCC_AHB , 0);
  
  DMA_voidInitChannel();
  
  MNVIC_voidInterruptEnable(11);
  
  DMA_voidStartChannel(Arr1 ,Arr2 , 1000);
  
  for(u16 i=0 ; i<1000 ; i++)
  {
    Arr4[i] = Arr3[i];
  }
  
  
  while(1)
  {
  
  }
  return 0;
}

void DMA1_Channel1_IRQHandler(void)
{   /* clear GIF */
	DMA -> IFCR = 1<<0;
	/* TC      */
	DMA -> IFCR = 1<<1;
}