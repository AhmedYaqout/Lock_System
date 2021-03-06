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



#define BITRATE 0x07

#define TWAR    *((volatile u8 *) 0x22)
#define TWBR    *((volatile u8 *) 0x20)
#define TWCR    *((volatile u8 *) 0x56)
#define TWDR    *((volatile u8 *) 0x23)
#define TWSR    *((volatile u8 *) 0x21)


void I2C_voidInit(void)
{
	TWSR	=	0;
	TWBR	=	BITRATE;
}
/* 
u8 I2C_u8MTSendData(u8 Copy_u8SlaveAddress,u8 Copy_u8Data)
{
	u8 Local_u8StartState=255;
	u8 Local_u8SLAState=255;
	u8 Local_u8DataState=255;
	u8 Local_u8State=255;
	Local_u8StartState	=	PRIVATE_I2C_u8MTSendStart();
	Local_u8SLAState	=	PRIVATE_I2C_u8MTSendSlaveAddress(u8 Copy_u8SlaveAddress);
	Local_u8DataState	=	PRIVATE_I2C_u8MTSendData(u8 Copy_u8Data);
	PRIVATE_I2C_voidMTSendStop();
	if(Local_u8StartState == 1 && Local_u8SLAState == 1 &&  Local_u8DataState == 1)
	{
		Local_u8State	=	1;
	}
	else
	{
		Local_u8State	=	0;
	}
	return Local_u8State;
} */

u8 I2C_u8MRReceiveData(u8 Copy_u8SlaveAddress,u8 * Copy_u8Data)
{
	u8 Local_u8StartState=255;
	u8 Local_u8SLAState=255;
	u8 Local_u8DataState=255;
	u8 Local_u8State=255;
	
	Local_u8StartState	=	PRIVATE_I2C_u8MRSendStart();
	Local_u8SLAState	=	PRIVATE_I2C_u8MRSendSlaveAddress(u8 Copy_u8SlaveAddress);
	Local_u8DataState	=	PRIVATE_I2C_u8MRReceiveData(u8 * Copy_u8Data);
	PRIVATE_I2C_voidMRSendStop();
	if(Local_u8StartState == 1 && Local_u8SLAState == 1 &&  Local_u8DataState == 1)
	{
		Local_u8State	=	1;
	}
	else
	{
		Local_u8State	=	0;
	}
	return Local_u8State;
}

/*Master Transmitter Mode Private Functions */

void PRIVATE_I2C_u8WaitFlag(void)
{
	while(!(GET_BIT(TWCR,TWINT)));
}

u8 I2C_u8MTSendStart(void)
{
	u8 Local_u8State;
	TWCR	=	(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	PRIVATE_I2C_u8WaitFlag();
	if (TWSR&0xF8 == STATUS_MT_START)
	{
		Local_u8State	=	1;
	}
	else
	{
		Local_u8State	=	0;
	}
	return Local_u8State;
}

u8 I2C_u8MTSendSlaveAddress(u8 Copy_u8SlaveAddress)
{/*The user must send 7-bit address and the LSB should be Cleared for Write operation*/
	TWDR	=	Copy_u8SlaveAddress;
	u8 Local_u8State;
	TWCR	=	(1<<TWINT)|(1<<TWEN);
	PRIVATE_I2C_u8WaitFlag();
	if (TWSR&0xF8 == STATUS_MT_SLA_W_ACK)
	{
		Local_u8State	=	1;
	}
	elseif(TWSR&0xF8 == STATUS_MT_SLA_W_NACK)
	{
		Local_u8State	=	2;
	}
	else
	{
		Local_u8State	=	0;
	}
	return Local_u8State;
}

u8 I2C_u8MTSendData(u8 Copy_u8Data)
{
	TWDR	=	Copy_u8Data;
	u8 Local_u8State;
	TWCR	=	(1<<TWINT)|(1<<TWEN);
	PRIVATE_I2C_u8WaitFlag();
	if (TWSR&0xF8 == STATUS_MT_DATA_ACK)
	{
		Local_u8State	=	1;
	}
	elseif(TWSR&0xF8 == STATUS_MT_DATA_NACK)
	{
		Local_u8State	=	2;
	}
	else
	{
		Local_u8State	=	0;
	}
	return Local_u8State;
}

void I2C_voidMTSendStop(void)
{
	TWCR	=	(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}


/*Master Receiver Mode Private Functions */

u8 I2C_u8MRSendStart(void)
{
	u8 Local_u8State;
	TWCR	=	(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	PRIVATE_I2C_u8WaitFlag();	
	if (TWSR&0xF8 == STATUS_MR_START)
	{
		Local_u8State	=	1;
	}
	else
	{
		Local_u8State	=	0;
	}
	return Local_u8State;
}

u8 I2C_u8MRSendSlaveAddress(u8 Copy_u8SlaveAddress)
{
	TWDR	=	Copy_u8SlaveAddress+R;
	u8 Local_u8State;
	TWCR	=	(1<<TWINT)|(1<<TWEN);
	PRIVATE_I2C_u8WaitFlag();
	if (TWSR&0xF8 == STATUS_MT_SLA_W_ACK)
	{
		Local_u8State	=	1;
	}
	elseif(TWSR&0xF8 == STATUS_MT_SLA_W_NACK)
	{
		Local_u8State	=	2;
	}
	else
	{
		Local_u8State	=	0;
	}
	return Local_u8State;
}

u8 I2C_u8MRReceiveData(u8 * Copy_u8Data)
{
	TWDR	=	Copy_u8SlaveAddress;
	u8 Local_u8State;
	TWCR	=	(1<<TWINT)|(1<<TWEN);
	while(!(GET_BIT(TWCR,TWINT)));
	if (TWSR&0xF8 == STATUS_MT_DATA_ACK)
	{
		Local_u8State	=	1;
	}
	elseif(TWSR&0xF8 == STATUS_MT_DATA_NACK)
	{
		Local_u8State	=	2;
	}
	else
	{
		Local_u8State	=	0;
	}
	return Local_u8State;
}

void I2C_voidMRSendStop(void)
{
	TWCR	=	(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}



