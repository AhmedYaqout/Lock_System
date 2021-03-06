/**
 * Author		:		Ahmad Yaqoot			
 * Description	:	    I2C Interface file
 * Date			:		22/Nov/2020
 * Version		:		V1.0
 */

#ifdef I2C_INTER_H
#ifndef I2C_INTER_H

#define I2C_PRESCALER_1     0
#define I2C_PRESCALER_4     1
#define I2C_PRESCALER_16    2
#define I2C_PRESCALER_64    3

/* Status Codes in Master Transmitter Mode*/
#define	STATUS_MT_START			0x08	/* A START condition has been transmitted */   
#define	STATUS_MT_R_START		0x10	/* A repeated START condition has been transmitted */ 
#define	STATUS_MT_SLA_W_ACK		0x18	/* SLA+W has been transmitted; ACK has been received */
#define	STATUS_MT_SLA_W_NACK	0x20	/* SLA+W has been transmitted; NOT ACK has been received */
#define	STATUS_MT_DATA_ACK		0x28	/* Data byte has been transmitted; ACK has been received */
#define	STATUS_MT_DATA_NACK		0x30	/* Data byte has been transmitted; NOT ACK has been received */
#define	STATUS_MT_ARB_LOST		0x38	 /* Arbitration lost in SLA+W or data bytes */  

/* Status Codes in Master Receiver Mode*/
#define	STATUS_MR_START			0x08	/* A START condition has been transmitted */   
#define	STATUS_MR_R_START		0x10    /* A repeated START condition has been transmitted */
#define	STATUS_MR_ARB_LOST		0x38	/* Arbitration lost in SLA+W or data bytes */
#define	STATUS_MR_SLA_R_ACK		0x40	/* SLA+R has been transmitted; ACK has been received */
#define	STATUS_MR_SLA_R_NACK	0x48	/* SLA+R has been transmitted; NOT ACK has been received */
#define	STATUS_MR_DATA_ACK		0x50	/* Data byte has been received; ACK has been returned */
#define	STATUS_MR_DATA_NACK		0x58	/* Data byte has been received; NOT ACK has been returned */

/*Status Codes in Slave Receiver Mode*/
#define	STATUS_SLR_SLA_W_ACK			0x60	/* Own SLA+W has been received; ACK has been returned */	
#define	STATUS_SLR_ARB_LOST_SLA_W_ACK	0x68	/* Arbitration lost in SLA+R/W; own SLA+W has been received; ACK has been returned */
#define	STATUS_SLR_GCALL_ACK			0x70	/* General call address has been received; ACK has been returned */
#define	STATUS_SLR_ARB_LOST_GCALL_ACK	0x78	/* Arbitration lost in SLA+R/W; General call address has been received; ACK has been returned */
#define	STATUS_SLR_DATA_SLA_W_ACK		0x80	/* Previously addressed with own SLA+W; data has been received; ACK has been returned */
#define	STATUS_SLR_DATA_SLA_W_NACK		0x88	/* Previously addressed with own SLA+W; data has been received; NOT ACK has been returned */
#define	STATUS_SLR_DATA_GCALL_ACK		0x90	/* Previously addressed with general call; data has been received; ACK has been returned */
#define	STATUS_SLR_DATA_GCALL_NACK		0x98	/* Previously addressed with general call; data has been received; NOT ACK has been returned */
#define	STATUS_SLR_STOP_R_START			0xA0	/* A STOP condition or repeated START condition has been received while still addressed as slave */

/*Status Codes in Slave Transmitter Mode*/
#define	STATUS_SLT_SLA_R_ACK			0xA8	/* Own SLA+R has been received; ACK has been returned */
#define	STATUS_SLT_ARB_LOST_SLA_R_ACK	0xB0	/* Arbitration lost in SLA+R/W as master; own SLA+R has been received; ACK has been returned */
#define	STATUS_SLT_DATA_ACK				0xB8	/* Data byte in TWDR has been transmitted; ACK has been received */
#define	STATUS_SLT_DATA_NACK			0xC0	/* Data byte in TWDR has been transmitted; NOT ACK has been received */
#define	STATUS_SLT_DATA_LAST_ACK		0xC8	/* Last data byte in TWDR has been transmitted (TWEA = “0”); ACK has been received */

#define I2C_STATUS_NO_INFO                         0xF8 /* No relevant state information available; TWINT = “0” */
#define I2C_STATUS_BUS_ERROR                        0x00 /* Bus error due to an illegal START or STOP condition */

#define TWINT_LOCATION   7
#define TWEA_LOCATION    6
#define TWSTA_LOCATION   5
#define TWSTO_LOCATION   4
#define TWWC_LOCATION   3
#define TWEN_LOCATION   2
#define TWIE_LOCATION   0


ErrorStatus I2C_enuStart(void);
ErrorStatus I2C_enuReStart(void);
ErrorStatus I2C_enuStop(void);
ErrorStatus I2C_enuWriteData(u8 Copy_u8Address,u8 Copy_u8Data);
ErrorStatus I2C_enuReadData(u8 Copy_u8Address, u8 * Copy_pu8Data);


#endif 
