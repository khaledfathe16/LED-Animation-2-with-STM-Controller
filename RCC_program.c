/*Library*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*Header files */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInitializeClockSystem(void)
{

	#if  CLOCK_SYSTEM_TYPE == RCC_HSE_CRYSTAL
	
	RCC_CR   = 0x00010000;
	RCC_CFGR = 0x00000001;
	
	#elif CLOCK_SYSTEM_TYPE == RCC_HSE_RC
	RCC_CR   =  0x00050000 ;
	RCC_CFGR =  0x00000001;
	
	#elif CLOCK_SYSTEM_TYPE == RCC_HSI
	RCC_CR   = 0x00000081 ;
	RCC_CFGR = 0x00000000;
	
	/*
	#elif CLOCK_SYSTEM_TYPE == RCC_PLL_HSE_CRYSTAL
	RCC_CR = ;
	RCC_CFGR = ;

	#elif CLOCK_SYSTEM_TYPE == RCC_PLL_HSE_RC
	RCC_CR = ;
	RCC_CFGR = ;

    #elif CLOCK_SYSTEM_TYPE == RCC_PLL_HSI
	RCC_CR = ;
	RCC_CFGR = ;
*/
#endif

}



void MRCC_voidEnablePeripheralClock( u8 copy_BusId , u8 copy_u8PeripheralId)
{
	if(copy_u8PeripheralId <= 31)
      {
		  
		  switch(copy_BusId)
		  {
			  case RCC_AHB : SET_BIT(RCC_AHBENR , copy_u8PeripheralId); break;
			  case RCC_APB1: SET_BIT(RCC_APB1ENR ,copy_u8PeripheralId); break;
			  case RCC_APB2: SET_BIT(RCC_APB2ENR ,copy_u8PeripheralId); break;
			  
			  default :/*invalid*/ ; break;   
		  }
		  
		  
		  
	  }
	  else 
	  {
		  /*ERROR*/
		  
	  }
	
	
	
	
}


void MRCC_voidDisablePeripheralClock( u8 copy_BusId , u8 copy_u8PeripheralId)
{
	if(copy_u8PeripheralId <= 31)
      {
		  
		  switch(copy_BusId)
		  {
			  case RCC_AHB  :  CLR_BIT(RCC_AHBENR , copy_u8PeripheralId);  break;
			  case RCC_APB1 :  CLR_BIT(RCC_APB1ENR , copy_u8PeripheralId); break;
			  case RCC_APB2 :  CLR_BIT(RCC_APB2ENR , copy_u8PeripheralId); break;
			  
			  default :/*invalid*/ ; break;   
		  }
		  
		  
		  
	  }
	  else 
	  {
		  /*ERROR*/
		  
	  }
	
	
	
	
}
