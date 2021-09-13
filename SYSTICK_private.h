#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SYSTICK_type;

#define SYSTICK ((volatile SYSTICK_type *)(0xE000E010))

#define AHB       0
#define AHB_DIV   1










#endif
