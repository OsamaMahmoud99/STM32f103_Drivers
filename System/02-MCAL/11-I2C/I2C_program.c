/***********************************************************************/
/* Author  : OsamaMahmoud                                              */
/* Date    : 9/10/2020                                                 */
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "I2C_interface.h"
#include "I2C_config.h"
#include "I2C_private.h"


void I2C_voidInit(I2C_Number CopyI2CNumber , u16 Copy_u16SpeedMode)
{
	switch(CopyI2CNumber)
	{
		case i2c1 :
		   /* to make sure the lines are released and the bus is free */
		   SET_BIT(I2C1 -> CR1 , 15);
		   CLR_BIT(I2C1 -> CR1 , 15);
		   /* clock frequency for peripheral */
		   I2C1 -> CR2 = 0x08;	
		   /* Speed Mode */
		   I2C1 -> CCR = Copy_u16SpeedMode;
		   /* maximum rise time */
		   I2C1 -> TRISE = 0x09;
		   /* peripheral enable */
		   SET_BIT(I2C1 -> CR1 , 0);
		   break;
		   
		case i2c2 :
		   /* to make sure the lines are released and the bus is free */
		   SET_BIT(I2C2 -> CR1 , 15);
		   CLR_BIT(I2C2 -> CR1 , 15);
		   /* clock frequency for peripheral */
		   I2C2 -> CR2 = 0x08;	
		   /* Speed Mode */
		   I2C2 -> CCR = Copy_u16SpeedMode;
		   /* maximum rise time */
		   I2C2 -> TRISE = 0x09;
		   /* peripheral enable */
		   SET_BIT(I2C2 -> CR1 , 0);
		   break;
	}
}