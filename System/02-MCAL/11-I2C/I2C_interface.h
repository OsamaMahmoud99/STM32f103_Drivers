/***********************************************************************/
/* Author  : OsamaMahmoud                                              */
/* Date    : 9/10/2020                                                 */
/***********************************************************************/
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H



typdef enum{
	
	i2c1,
	i2c2
	
}I2C_Number;

/* Speed Mode */
#define I2C_FM 0x2d
#define I2C_SM 0xB4

void I2C_voidInit(I2C_Number CopyI2CNumber , u16 Copy_u16SpeedMode);













#endif