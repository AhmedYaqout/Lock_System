/*
 * Author		:		Ahmad Yaqoot			
 * Description	:	    I2C Configuration file
 * Date			:		22/Nov/2020
 * Version		:		V1.0
 */

#ifdef  I2C_CONFIG_H
#ifndef I2C_CONFIG_H

/* I2C_ACK_MODE OPTIONS : ENABLE , DISABLE */
#define I2C_ACK_MODE	ENABLE


/* I2C SCL Freq. = F_CPU / [16 + 2(TWBR) . 4^(PRESCALER)] 
*	where,
*			PRESCALER (I2C_SCL_PRES) options : I2C_PRESCALER_1, 
*												I2C_PRESCALER_4,
*												I2C_PRESCALER_16,
*												I2C_PRESCALER_64
*	
*	and 	0X00 <= TWBR (I2C_TWBR_VALUE) <= 0xFF		
*/
#define I2C_SCL_PRES 	I2C_PRESCALER_1

#define I2C_TWBR_VALUE 	32


/* put down your unit address */
#define I2C_SLAVE_ADD  0x05

/** I2C_GENERAL_CALL OPTIONS : ENABLE , DISABLE **/
#define I2C_GENERAL_CALL	DISABLE

#endif