/**
 * Author		:		Ahmad Yaqoot			
 * Description	:	    Two Wire Interface Private file
 * Date			:		28/August/2020
 * Version		:		V1.0
 */

#ifdef I2C_PRIVATE_H
#ifndef I2C_PRIVATE_H

/* TWI Registers */
#define TWAR    *((volatile u8 *) 0x22)
#define TWBR    *((volatile u8 *) 0x20)
#define TWCR    *((volatile u8 *) 0x56)
#define TWDR    *((volatile u8 *) 0x23)
#define TWSR    *((volatile u8 *) 0x21)

/* TWCR Contents */
#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
#define TWIE	0

/* TWSR Prescaler Bits */
#define TWPS0	 0	
#define TWPS1    1	

/* TWAR General Call Enable Bit */
#define TWGCE  0


#define ENABLE  0
#define DISABLE 1

/* Prescaler Values */
#define PRES_1		0
#define PRES_4		1	
#define PRES_16		2
#define PRES_64		3

#endif