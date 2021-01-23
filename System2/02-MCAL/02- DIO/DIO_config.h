/*******************************************************/
/* Author  : Osama Mahmoud                             */
/* Date    : 9/4/2020                                  */
/*******************************************************/
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H


typedef enum
{
	INPUT_ANALOG   =0b0000,
	INPUT_FLOATING =0b0100,
	INPUT_PP_PD    =0b1000,
	OUTPUT_PP_10MHZ=0b0001,
	OUTPUT_OD_10MHZ=0b0101,
	OUTPUT_PP_2MHZ =0b0010,
    OUTPUT_OD_2MHZ =0b0110,
	OUTPUT_PP_50MHZ=0b0011,
	OUTPUT_OD_50MHZ=0b0111,
	
}Mode_Type;

typedef enum
{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINA8,
	PINA9,
	PINA10,
	PINA11,
	PINA12,
	PINA13,
	PINA14,
	PINA15,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINB8,
	PINB9,
	PINB10,
	PINB11,
	PINB12,
	PINB13,
	PINB14,
	PINB15,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PINC8,
	PINC9,
	PINC10,
	PINC11,
	PINC12,
	PINC13,
	PINC14,
	PINC15,
	TOTAL_PINS
	}PinNum_type;
	
extern const Mode_Type PinsStatus[TOTAL_PINS];




#endif