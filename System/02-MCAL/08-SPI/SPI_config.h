/****************************************************************************************/
/* Author :  OsamaMahmoud                                                               */
/* Date   :  16/9/2020                                                                  */
/****************************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


#define   SPI1_SLAVE_PIN       GPIOB,0

#define   SPI1_CLK_PHASE       SECOND_CLOCK

#define   SPI1_CLK_POLARITY    CK_TO_ONE
 
#define   SPI1_MASTER_CONFIG   MASTER

#define   SPI1_BAUDE_RATE      FPCLK_8

#define   SPI1_STATUS          ENABLE

#define   SPI1_FRAME_FORMAT    MSB

#define   SPI1_SOFTWARE_SLAVE  SSM_ENABLED

#define   SPI1_INTERNAL_SLAVE  EFFECT_SSM

#define   SPI1_RECEIVE         RECEIVE_SEND

#define   SPI1_DATA_FRAME      DATA_8BIT




#endif  