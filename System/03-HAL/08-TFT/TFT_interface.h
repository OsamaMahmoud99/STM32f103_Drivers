/*****************************************************/
/* Author  :  OsamaMahmoud                           */
/* Date    :  21/9/2020                              */
/*****************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H


void TFT_voidInitialize(void);
void TFT_voidDispalyImage(const u16* Copy_Image);
void TFT_voidFillColor(u16 Copy_u16Color);
void TFT_voidDrawRect(u8 x1 , u8 x2 , u8 y1 ,u8 y2 , u16 Copy_u16Color);




#endif