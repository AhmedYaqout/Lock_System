/*******************************************/
/** Author      : ahmed mahmoud            */
/** Description : Program file for kEYPAD  */
/** Date        : 29 Nov 2019		       */
/** Version     : 1.0V                     */
/*******************************************/

#include "STD_Types.h"
#include "BIT_math.h"
#include <util/delay.h>


#include "DIO_int.h"

#include "KEY_int.h"
#include "KEY_cfg.h"
#include "KEY_priv.h"




void KEY_voidInit(void)
{
	/**!Comment : Activate Pullup Resistor for Input Pins*/
	DIO_enuSetPinValue(KEY_u8INPUT_0 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8INPUT_1 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8INPUT_2 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8INPUT_3 ,DIO_u8HIGH);
	
}

u8 KEY_u8GetPressedKey(void)
{
	u8 u8TempLoc ;
	u8 u8ReturnLoc = 0xFF;
	DIO_enuSetPinValue(KEY_u8OUTPUT_0 ,DIO_u8LOW );
	DIO_enuSetPinValue(KEY_u8OUTPUT_1 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8OUTPUT_2 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8OUTPUT_3 ,DIO_u8HIGH);

	DIO_enuGetPinValue(KEY_u8INPUT_0,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_0 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_1,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_4 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_2,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_8 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_3,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_12 ;
	}
	/******************************************/
	/************** SEQ 2 *********************/
   if (u8ReturnLoc == 0xFF)
   {
	DIO_enuSetPinValue(KEY_u8OUTPUT_0 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8OUTPUT_1 ,DIO_u8LOW );
	DIO_enuSetPinValue(KEY_u8OUTPUT_2 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8OUTPUT_3 ,DIO_u8HIGH);

	DIO_enuGetPinValue(KEY_u8INPUT_0,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_1 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_1,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_5 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_2,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_9 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_3,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_13 ;
	}
	   
   }
/******************************************/
	/************** SEQ 3 *********************/
   if (u8ReturnLoc == 0xFF)
   {
	DIO_enuSetPinValue(KEY_u8OUTPUT_0 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8OUTPUT_1 ,DIO_u8HIGH );
	DIO_enuSetPinValue(KEY_u8OUTPUT_2 ,DIO_u8LOW);
	DIO_enuSetPinValue(KEY_u8OUTPUT_3 ,DIO_u8HIGH);

	DIO_enuGetPinValue(KEY_u8INPUT_0,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_2 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_1,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_6 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_2,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_10 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_3,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_14 ;
	}
	   
   }
   /******************************************/
	/************** SEQ 4 *********************/
   if (u8ReturnLoc == 0xFF)
   {
	DIO_enuSetPinValue(KEY_u8OUTPUT_0 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8OUTPUT_1 ,DIO_u8HIGH );
	DIO_enuSetPinValue(KEY_u8OUTPUT_2 ,DIO_u8HIGH);
	DIO_enuSetPinValue(KEY_u8OUTPUT_3 ,DIO_u8LOW);

	DIO_enuGetPinValue(KEY_u8INPUT_0,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_3 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_1,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_7 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_2,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_11 ;
	}
	DIO_enuGetPinValue(KEY_u8INPUT_3,&u8TempLoc);
	if(u8TempLoc == 0)
	{
		u8ReturnLoc = BUTTON_15 ;
	}
	   
   }

return u8ReturnLoc ;
	

}
