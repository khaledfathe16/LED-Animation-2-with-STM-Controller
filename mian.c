/*
 * mian.c
 *
 *  Created on: ???/???/????
 *      Author: Algo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"




int main()
{
  /*Clock System initialization*/
	MRCC_voidInitializeClockSystem();
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);

 /*SET GPIO MODE*/
 for(u8 Local_u8Counter = 0; Local_u8Counter<=7;Local_u8Counter++)
 {
	 MGPIO_voidSetPinMode(GPIOA,Local_u8Counter,OUTPUT_2MHZ_PP);
 }

 /*Systick initialization*/
  MSYSTICK_voidInit();

  s8 x;
while(1){
	x=3;

	for(u8 i=4;i<=7;i++)
	{

		MGPIO_voidSetPinValue(GPIOA , i , HIGH);
		MSYSTICK_SetBusyWait(200000);

		MGPIO_voidSetPinValue(GPIOA , x , HIGH);
		MSYSTICK_SetBusyWait(200000);
		x--;

	}
       x=0;
	for(u8 i=7;i>=4;i--)
		{

			MGPIO_voidSetPinValue(GPIOA , i , LOW);
			MSYSTICK_SetBusyWait(200000);

			MGPIO_voidSetPinValue(GPIOA , x , LOW);
			MSYSTICK_SetBusyWait(200000);
			x++;

		}

}






return 0;
}


