/*******************************/
/***                        ****/
/*** Date		:23 Nov 2019   ****/
/*** Author		: Ahmed Yakout ****/
/*** Version	: V1.0			***/
/*******************************/

#include"STD_Types.h"
#include"BIT_math.h"

#include"DIO_int.h"

#include"LCD_int.h"
#include "LCD_priv.h"
#include "LCD_cfg.h"

#include<util/delay.h>

#define EIGHTBITS2LINE5X8DOTS	0x38
#define SHIFTDISPLAYLEFT 	0x0c
#define CLEARDISPLAY		0x01
#define MOVECURSORLEFT		0x06

void LCD_voidInit(void){
	_delay_ms(30);
	LCD_voidSendCmd(0x38);
	_delay_ms(1);
	LCD_voidSendCmd(0x0c);
	_delay_ms(1);
	LCD_voidSendCmd(0x01);
	_delay_ms(2);
	LCD_voidSendCmd(0x06);
	_delay_ms(2);
	
}

void LCD_voidSendCmd(u8 u8CmdCpy){
	DIO_enuSetPinValue(LCD_u8RS, DIO_u8LOW);
	voidPutOnBus(u8CmdCpy);
}

void LCD_voidWriteChar(u8 u8CharCpy){
	DIO_enuSetPinValue(LCD_u8RS,DIO_u8HIGH);
	DIO_enuSetPinValue(LCD_u8RW,DIO_u8LOW);
	voidPutOnBus(u8CharCpy);
}


static void voidPutOnBus (u8 u8DCmdCpy){
DIO_enuSetPinValue(LCD_u8RW, DIO_u8LOW);

DIO_enuSetPinValue(LCD_u8DATA_0,GET_BIT(u8DCmdCpy,0));
DIO_enuSetPinValue(LCD_u8DATA_1,GET_BIT(u8DCmdCpy,1));
DIO_enuSetPinValue(LCD_u8DATA_2,GET_BIT(u8DCmdCpy,2));
DIO_enuSetPinValue(LCD_u8DATA_3,GET_BIT(u8DCmdCpy,3));
DIO_enuSetPinValue(LCD_u8DATA_4,GET_BIT(u8DCmdCpy,4));
DIO_enuSetPinValue(LCD_u8DATA_5,GET_BIT(u8DCmdCpy,5));
DIO_enuSetPinValue(LCD_u8DATA_6,GET_BIT(u8DCmdCpy,6));
DIO_enuSetPinValue(LCD_u8DATA_7,GET_BIT(u8DCmdCpy,7));

DIO_enuSetPinValue(LCD_u8EN, DIO_u8HIGH);
_delay_ms(1);
DIO_enuSetPinValue(LCD_u8EN, DIO_u8LOW);
_delay_ms(1);
}

void LCD_voidClear(void){
	LCD_voidSendCmd(0x01);
	_delay_ms(2);
}

void LCD_voidGoToXY(u8 u8LineNbCpy, u8 u8CharNbCpy){
	if(u8LineNbCpy==1){
		LCD_voidSendCmd((128+u8CharNbCpy));
	}else if (u8LineNbCpy==2){
		LCD_voidSendCmd((192+u8CharNbCpy));
	}
}

void LCD_voidWriteString(u8 *pu8StringCpy){
	u8 Loc_u8Counter=0;
	
	while (pu8StringCpy[Loc_u8Counter] != '\0')
	{
		LCD_voidWriteChar(pu8StringCpy[Loc_u8Counter]);
		Loc_u8Counter++;
	}
}

