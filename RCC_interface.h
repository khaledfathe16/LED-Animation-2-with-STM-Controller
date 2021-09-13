#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H




void MRCC_voidInitializeClockSystem(void);
void MRCC_voidEnablePeripheralClock( u8 copy_BusId , u8 copy_u8PeripheralId);
void MRCC_voidDisablePeripheralClock(u8 copy_u8busId , u8 copy_u8PeripheralId);


#define RCC_AHB    0
#define RCC_APB1   1
#define RCC_APB2   2




#endif
