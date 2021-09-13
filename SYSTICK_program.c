#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


void MSYSTICK_voidInit(void)
{

#if SYSTICK_CLOCK == AHB_DIV
	SYSTICK -> CTRL = 0x02;
#elif SYSTICK_CLOCK == AHB
	SYSTICK -> CTRL = 0x06;
#endif
}



void MSYSTICK_SetBusyWait(u32 copy_u32Load)
{
	if(copy_u32Load <= 0x00FFFFFF && copy_u32Load>= 0x00000001)
	{

			SYSTICK -> LOAD = copy_u32Load;
			SYSTICK -> VAL = 0;
			SET_BIT( SYSTICK->CTRL , 0 );
			SET_BIT( SYSTICK->CTRL , 1 );

			while(!GET_BIT(SYSTICK -> CTRL , 16));
			SYSTICK -> CTRL = 0;
	}
}
