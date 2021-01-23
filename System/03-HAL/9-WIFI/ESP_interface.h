/****************************************************************/
/* Author    : Osama Mahmoud                                    */
/* Date      : 28 SEP 2020                                      */
/* Version   : V01                                              */
/****************************************************************/
#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP_voidInit(void);
void ESP_voidConnectOnWifi(void);
void ESP_voidConnectOnServer(void);
u8 ESP_u8SendData(void);
#endif