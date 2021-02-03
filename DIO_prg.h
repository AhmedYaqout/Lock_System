#include "STD_Types.h"
#include "BIT_math.h"

#include "DIO_int.h"
#include "DIO_cfg.h"
#include "DIO_priv.h"

void DIO_voidInit(){
	DDRA=conc(DIO_u8PINDIR_7,DIO_u8PINDIR_6,DIO_u8PINDIR_5,DIO_u8PINDIR_4,DIO_u8PINDIR_3,DIO_u8PINDIR_2,DIO_u8PINDIR_1,DIO_u8PINDIR_0);
	DDRB=conc(DIO_u8PINDIR_15,DIO_u8PINDIR_14,DIO_u8PINDIR_13,DIO_u8PINDIR_12,DIO_u8PINDIR_11,DIO_u8PINDIR_10,DIO_u8PINDIR_9,DIO_u8PINDIR_8);
	DDRC=conc(DIO_u8PINDIR_23,DIO_u8PINDIR_22,DIO_u8PINDIR_21,DIO_u8PINDIR_20,DIO_u8PINDIR_19,DIO_u8PINDIR_18,DIO_u8PINDIR_17,DIO_u8PINDIR_16);
	DDRD=conc(DIO_u8PINDIR_31,DIO_u8PINDIR_30,DIO_u8PINDIR_29,DIO_u8PINDIR_28,DIO_u8PINDIR_27,DIO_u8PINDIR_26,DIO_u8PINDIR_25,DIO_u8PINDIR_24);
	}

tenuErrorStatus	DIO_enuSetPinValue(u8 u8PinNbCpy,u8 u8PinvalueCpy){
	tenuErrorStatus enuReturn= OK;
	
	if(u8PinNbCpy <= DIO_u8_PIN_7){
		if(u8PinNbCpy==DIO_u8HIGH){
				SET_BIT(PORTA,u8PinNbCpy);
		}else{
			
				CLR_BIT(PORTA,u8PinNbCpy);
		}
	}else if (u8PinNbCpy >= DIO_u8_PIN_8 && u8PinNbCpy <= DIO_u8_PIN_15){
		u8PinNbCpy=u8PinNbCpy%DIO_u8_PIN_8;
		if(u8PinNbCpy==DIO_u8HIGH){
				SET_BIT(PORTB,u8PinNbCpy);
		}else{
			
				CLR_BIT(PORTB,u8PinNbCpy);
		}
	}else if (u8PinNbCpy >= DIO_u8_PIN_16 && u8PinNbCpy <= DIO_u8_PIN_23){
		u8PinNbCpy=u8PinNbCpy%DIO_u8_PIN_16;
		if(u8PinNbCpy==DIO_u8HIGH){
				SET_BIT(PORTC,u8PinNbCpy);
		}else{
			
				CLR_BIT(PORTC,u8PinNbCpy);
		}
	}else if (u8PinNbCpy >= DIO_u8_PIN_24 && u8PinNbCpy <= DIO_u8_PIN_31){
		u8PinNbCpy=u8PinNbCpy%DIO_u8_PIN_24;
		if(u8PinNbCpy==DIO_u8HIGH){
				SET_BIT(PORTD,u8PinNbCpy);
		}else{
			
				CLR_BIT(PORTD,u8PinNbCpy);
		}
	}else{
		enuReturn =INDEX_OUT_OF_RANGE;
	}
}




