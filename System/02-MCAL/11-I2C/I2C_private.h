/***********************************************************************/
/* Author  : OsamaMahmoud                                              */
/* Date    : 9/10/2020                                                 */
/***********************************************************************/
#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/*
I2C2
PB10 -> SCL
PB11 -> SDA

I2C1
PB6 -> SCL
PB7 -> SDA

*/

typedef struct {
	
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 OAR1;
	volatile u32 OAR2;
	volatile u32 DR;
	volatile u32 SR1;
	volatile u32 SR2;
	volatile u32 CCR;
	volatile u32 TRISE;
	
}I2C_Registers;



#define   I2C1     ((I2C_Registers*)0x40005400)
#define   I2C2     ((I2C_Registers*)0x40005800)















#endif