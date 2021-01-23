/****************************************************************************/
/* Author  :  OsamaMahmoud                                                  */
/* Date    :  11/9/2020                                                     */
/****************************************************************************/
#ifndef DAC_INTERFCAE_H
#define DAC_INTERFACE_H



void DAC_voidInit(void);
void DAC_voidSetCallBack(u8 Copy_u8SampleTime , void(*Fptr)(void));
void DAC_voidSetVoice(u8 *Song);










#endif