/**************************************************************************************/
/*    Author  : OsamaMahmoud                                                          */
/*    Date    : 13/8/2020                                                             */
/*    Version : V01                                                                   */
/**************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define  GPIOA  0
#define  GPIOB  1
#define  GPIOC  2

#define  GPIO_LOW       0
#define  GPIO_HIGH      1

/* Number of pins to write into */
#define PINS_2          0x03
#define PINS_3          0x07
#define PINS_4          0x0f
#define PINS_5          0x1f
#define PINS_6          0x3f
#define PINS_7          0x7f
#define PINS_8          0xff

/* INPUT MODE            */
#define  INPUT_ANALOG         0b0000
#define  INPUT_FLOATING       0b0100
#define  INPUT_PP_PD          0b1000
/* OUTPUT MODE For 10MHZ */
#define  OUTPUT_PP_10MHZ      0b0001
#define  OUTPUT_OD_10MHZ      0b0101
#define  OUTPUT_AF_PP_10MHZ   0b1001
#define  OUTPUT_AF_OD_10MHZ   0b1101
/* OUTPUT MODE For 2MHZ  */
#define  OUTPUT_PP_2MHZ       0b0010
#define  OUTPUT_OD_2MHZ       0b0110
#define  OUTPUT_AF_PP_2MHZ    0b1010
#define  OUTPUT_AF_OD_2MHZ    0b1110
/* OUTPUT MODE For 50MHZ */
#define  OUTPUT_PP_50MHZ      0b0011
#define  OUTPUT_OD_50MHZ      0b0111
#define  OUTPUT_AF_PP_50MHZ   0b1011
#define  OUTPUT_AF_OD_50MHZ   0b1111


void DIO_voidSetDirection(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8mode);
void DIO_voidSetValue    (u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8value);
void DIO_voidTogPin      (u8 Copy_u8port, u8 Copy_u8pin);
void DIO_voidSetPort     (u8 Copy_u8port, u8 Copy_u8value);
void DIO_voidSetLockPin  (u8 Copy_u8port, u8 Copy_u8bit);
u8   DIO_u8GetLockPin    (u8 Copy_u8port, u8 Copy_u8bit);
u8   DIO_u8GetValue      (u8 Copy_u8port, u8 Copy_u8pin);
void DIO_voidWritePins   (u8 Copy_u8Port,u8 Copy_u8StartPin,u8 Copy_u8NumberofPins,u8 Copy_u8Value);


#endif