/*Libirary*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinMode(u8 copy_u8PortId , u8 copy_u8PinId , u8 copy_u8PinMode )
{
 if(copy_u8PinId <=15)
 {
	 switch(copy_u8PortId)
	 {
		 case GPIOA : if(copy_u8PinId <= 7)
		                  {
							  GPIOA_CRL &= ~((0b1111)<<(copy_u8PinId*4)) ;
							  GPIOA_CRL |=  ((copy_u8PinMode)<<(copy_u8PinId*4)) ;
							  
						  }		 
						  else if(copy_u8PinId <= 15 && copy_u8PinId >=8)
						  {
							  copy_u8PinId -= 8;
							  GPIOA_CRH &= ~((0b1111)<<(copy_u8PinId*4)) ;
							  GPIOA_CRH |=  ((copy_u8PinMode)<<(copy_u8PinId*4)) ;
							  
							  
						  }; break;
		 case GPIOB : if(copy_u8PinId <= 7)
		                  {
							  GPIOB_CRL &= ~((0b1111)<<(copy_u8PinId*4)) ;
							  GPIOB_CRL |=  ((copy_u8PinMode)<<(copy_u8PinId*4)) ;
							  
						  }
						  else if(copy_u8PinId <= 15 && copy_u8PinId >=8)
						  {
							 copy_u8PinId -= 8;
							  GPIOB_CRH &= ~((0b1111)<<(copy_u8PinId*4)) ;
							  GPIOB_CRH |=  ((copy_u8PinMode)<<(copy_u8PinId*4)) ;
							  
							  
						  }; break;
		 case GPIOC : if(copy_u8PinId <= 7)
		                  {
							  GPIOC_CRL &= ~((0b1111)<<(copy_u8PinId*4)) ;
							  GPIOC_CRL |=  ((copy_u8PinMode)<<(copy_u8PinId*4)) ;
							  
						  }
						  else if(copy_u8PinId <= 15 && copy_u8PinId >=8)
						  {
							  copy_u8PinId -= 8; 
							  GPIOC_CRH &= ~((0b1111)<<(copy_u8PinId*4)) ;
							  GPIOC_CRH |=  ((copy_u8PinMode)<<(copy_u8PinId*4)) ;
							  
							  
						  } ; break;
		 default :/*Invalid*/ ; break;
	 }
	 
	 
 }
 else 
 {
  	 
	/*ERROR*/ 
 }
	
}

void MGPIO_voidSetPinValue(u8 copy_u8PortId , u8 copy_u8PinId , u8 copy_u8PinValue)
{
	if(copy_u8PinId <=15)
	{
		switch(copy_u8PortId)
		{
			case GPIOA :  
			if(copy_u8PinValue == HIGH)
			{
				SET_BIT(GPIOA_ODR , copy_u8PinId); 
			}
			else if(copy_u8PinValue == LOW)
			{
				CLR_BIT(GPIOA_ODR , copy_u8PinId); 
			} ; break;
				
				case GPIOB :  
			if(copy_u8PinValue == HIGH)
			{
				SET_BIT(GPIOB_ODR , copy_u8PinId); 
			}
			else if(copy_u8PinValue == LOW)
			{
				CLR_BIT(GPIOB_ODR , copy_u8PinId); 
			} ; break; 
				
				case GPIOC :  
			if(copy_u8PinValue == HIGH)
			{
				SET_BIT(GPIOC_ODR , copy_u8PinId); 
			}
			else if(copy_u8PinValue == LOW)
			{
				CLR_BIT(GPIOC_ODR , copy_u8PinId); 
			} ; break;
		
		default : /*Invalid*/;break;
		
	}
	}
	else 
	{
		/*ERROR*/
	}
	

}


void MGPIO_voidSetPinValueFast(u8 copy_u8PortId , u8 copy_u8PinId , u8 copy_u8PinValue)
{

if(copy_u8PinId <= 15)
{
	switch(copy_u8PortId)
	{
		case GPIOA :   if(copy_u8PinValue == HIGH)
		                     {
		                     	GPIOA_BSRR = (1<<copy_u8PinId);


		                     }
								else if(copy_u8PinValue == LOW)
								{
									GPIOA_BSRR = (1<<(copy_u8PinId + 16));


								};  break;
		case GPIOB :  if(copy_u8PinValue == HIGH)
		                     {
		                     	GPIOB_BSRR = (1<<copy_u8PinId);


		                     }
								else if(copy_u8PinValue == LOW)
								{
									GPIOB_BSRR = (1<<(copy_u8PinId + 16));


								}    ;  break;
		case GPIOC :   if(copy_u8PinValue == HIGH)
		                     {
		                     	GPIOC_BSRR = (1<<copy_u8PinId);


		                     }
								else if(copy_u8PinValue == LOW)
								{
									GPIOC_BSRR = (1<<(copy_u8PinId + 16));


								}   ;  break;

		default :/*Invalid*/ ;break;
	}


}
else {

	/* ERROR*/

}


}


void MGPIO_voidClearPinValueFast(u8 copy_u8PortId ,u8 copy_u8PinId )
{


	if(copy_u8PinId <= 15)
	{
		switch(copy_u8PortId)
		{
			case GPIOA :	GPIOA_BRR = (1<<copy_u8PinId)		;  break;
			case GPIOB :    GPIOB_BRR = (1<<copy_u8PinId)    ;  break;
			case GPIOC :    GPIOC_BRR = (1<<copy_u8PinId)   ;  break;

			default :/*Invalid*/ ;break;
		}


	}
	else {

		/* ERROR*/

	}



}


u8 MGPIO_u8GetPinValue(u8 copy_u8PortId , u8 copy_u8PinId)
{
	u8 Local_u8Value = 0 ;
	if(copy_u8PinId <=15)
	{
		switch(copy_u8PortId)
		{
			case GPIOA :  
			
			Local_u8Value = GET_BIT(GPIOA_IDR , copy_u8PinId); break;
				
				case GPIOB :  
			Local_u8Value = GET_BIT(GPIOB_IDR, copy_u8PinId); break; 
				
				case GPIOC :  
			Local_u8Value = GET_BIT(GPIOC_IDR , copy_u8PinId); break;
		
		default : /*Invalid*/;break;
		
	    }
	}
	else 
	{
		/*ERROR*/
	}
	
	return Local_u8Value;
	
	
}

