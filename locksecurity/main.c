/*
 * main.c
 *
 *  Created on: 11 Dec 2019
 *      Author: Ahmad Yaqoot
 */
#include "STD_Types.h"
#include "BIT_math.h"
#include <util/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "SEV_int.h"
#include "KEY_int.h"
#include "STEPPER_int.h"

void OpenDoor(void);
void CloseDoor(void);
void ClearPasswordField(void);
u8 PasswordCheck(void);
void WrongPassword(void);
u8 GetKey(void);
void ClearInputData(void);

#define	u8PasswordLength 	4
u8	u8UserInput[u8PasswordLength]	=	{0};
u8	u8Password[u8PasswordLength]	=	{1,2,3,4}	;

int main (void){
	s8 i=0 ,j;
	u8 condition;
	u8 u8PressedLoc;
	DIO_voidInit();
	LCD_voidInit();
	KEY_voidInit();
	LCD_voidWriteString("Home Security");
	_delay_ms(2000);
	LCD_voidClear();
	LCD_voidWriteString("Enter Password:");
	LCD_voidGoToXY(2,0);
	LCD_voidSendCmd(0x0F);
	while(1){

		u8PressedLoc = GetKey() ;

		if(u8PressedLoc == 'C')
		{
			i=0;
			ClearPasswordField();
			ClearInputData();
		}
		else if(u8PressedLoc == 'E')
		{
			condition =PasswordCheck();

			if(condition == 1 && i<=u8PasswordLength)
			{
				i=0;
				OpenDoor();
				ClearInputData();
			}
			else
			{
				i=0;
				WrongPassword();
				ClearInputData();
			}
		}
		else if(u8PressedLoc == 'L'){
			CloseDoor();
			ClearInputData();
		}
		else if (u8PressedLoc >= 1 && u8PressedLoc <=9 )
		{
			LCD_voidWriteChar(u8PressedLoc +0x30);
			u8UserInput[i]=u8PressedLoc;
			i++;
			_delay_ms(250);
		}

	}

	_delay_ms(10);

	return 0;
}

void OpenDoor(void){
	s8 i;
	LCD_voidClear();
	LCD_voidWriteString("Welcome Home!");
	LCD_voidGoToXY(2,0);
	LCD_voidWriteString("Unlocking Door...");

	for (i=3;i>=0;i--)
	{
		SEV_voidDisplayNb(SEV_LEFT,i);
		_delay_ms(1000);
	}
	/*for (i=0;i<=63;i++){
			Stepper_RotateCW();*/
}
void CloseDoor(void){
	s8 i;
	LCD_voidClear();
	LCD_voidWriteString("GoodBye!");
	LCD_voidGoToXY(2,0);
	LCD_voidWriteString("Locking Door...");

	for (i=3;i>=0;i--)
	{
		SEV_voidDisplayNb(SEV_LEFT,i);
		_delay_ms(1000);
	}
	/*for (i=0;i<=63;i++){
				Stepper_RotateACW();*/
	LCD_voidClear();
	LCD_voidWriteString("Enter Password:");
	LCD_voidGoToXY(2,0);
}

void ClearPasswordField(void){
	LCD_voidClear();
	LCD_voidWriteString("Enter Password:");
	LCD_voidGoToXY(2,0);
}

u8 PasswordCheck(void){
	u8 PasswordCondition=0;
	s8 i	=	0;

	/*Comparing Password*/
	for(i=0; i<u8PasswordLength;i++)
	{
		if(u8UserInput[i]!=u8Password[i])
		{
			WrongPassword();
			PasswordCondition =	0;
			return PasswordCondition;
		}else{
			PasswordCondition = 1;
		}
	}
	return PasswordCondition;
}

void WrongPassword(void){
	LCD_voidClear();
	LCD_voidWriteString("Wrong Password!");
	LCD_voidGoToXY(2,0);
	//_delay_ms(1000);
	LCD_voidWriteString("Try again!");
	_delay_ms(1000);
	LCD_voidClear();
	LCD_voidWriteString("Enter Password:");
	LCD_voidGoToXY(2,0);
}

u8 GetKey(void){
	u8 u8PressedLoc;
	while ((u8PressedLoc = KEY_u8GetPressedKey())	== 0xFF);
	return u8PressedLoc;
}

void ClearInputData(void){
	 s8 i;
	for(i=0;i<u8PasswordLength;i++)
	{
		u8UserInput[i] = 0;
	}
}
