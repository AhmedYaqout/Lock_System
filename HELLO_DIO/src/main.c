/*
 * main.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Silver
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#define PORTA_CRL	*((u32*)(0x40010800))
#define PORTA_ODR	*((u32*)(0x4001080C))

void main (void){
	/*Initialize Clock system*/
	RCC_voidInitSysClock();

	/*Enable peripheral 2 on APB2 bus (GPIOA)*/
	RCC_voidEnableClock(RCC_APB2,2);

	/* Configure A0 as output Push Pull*/
	PORTA_CRL	=	0x00000002;

	/* Set A0 High*/
	PORTA_ODR	=	0x00000001;
	while(1){

	}
}

