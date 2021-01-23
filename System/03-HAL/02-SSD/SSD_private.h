/**************************************************************************************/
/*  Author    : OsamaMahmoud                                                          */
/*  Date      : 14/8/2020                                                             */
/**************************************************************************************/
#ifndef SEVEN_SEG_PRIVATE_H
#define SEVEN_SEG_PRIVATE_H


#if   defined(COMMON_CATHODE)

 u8 data[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

#elif defined(COMMON_ANODE)
 u8 data[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

#endif



#endif
