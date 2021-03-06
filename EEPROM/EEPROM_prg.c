/*******************************************/
/** Author      : Ahmed Yakout            */
/** Description : prg file for EEPROM         */
/** Date        : 11 Jan 2020		       */
/** Version     : 1.0V                     */
/*******************************************/


#include "STD_Types.h"
#include "BIT_math.h"

#include "I2C_int.h"

#include "EEPROM_int.h"
#include "EEPROM_cfg.h"
#include "EEPROM_priv.h"


void EEPROM_voidInit(void){
	I2C_voidInit();
	
}

EEPROM_ErrorStatus EEPROM_enuWrite(u8 Copy_u8Data, u8 Copy_u8Block, u8 Copy_u8Address){
	EEPROM_ErrorStatus State= EEPROM_NOK;
	/* Step 1 Start Condition */
	I2C_voidStartCondition();
	
	/* Step 2 Polling on Flag */
	I2C_voidWait();
	
	/* Step 3 Check Start Condition Acknowledgement */
	if (I2C_enuCheckAck(I2C_SC_ACK) != OK){
		State =	EEPROM_SC_ERROR;
		return State;
	}
	
	/* Step 4 Slave Address and Block */
	switch (Copy_u8Block)
	{
		case EEPROM_BLOCK0:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_0_W);
		break;
		
		case EEPROM_BLOCK1:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_1_W);
		break;
		
		case EEPROM_BLOCK2:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_2_W);
		break;
		
		case EEPROM_BLOCK3:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_3_W);
		break;
		
		default:
		State=EEPROM_OUT_OF_RANGE;
		return State;
	}
	
	I2C_voidWait();
	if (I2C_enuCheckAck(I2C_MT_SLA_W_ACK) != OK){
		State =	EEPROM_SLA_ERROR;
		return State;
	}
	
	/* Step 4 Write Address */
	I2C_voidWriteByte(Copy_u8Address);
	I2C_voidWait();
	if (I2C_enuCheckAck(I2C_MT_DATA_ACK) != OK){
		State =	EEPROM_ADDRESS_ERROR;
		return State;
	}
	
	/* Step 5 Write Data */
	I2C_voidWriteByte(Copy_u8Data);
	I2C_voidWait();
	if (I2C_enuCheckAck(I2C_MT_DATA_ACK) != OK){
		State =	EEPROM_DATA_ERROR;
		return State;
	}
	
	/* Step 6 Stop Condition */
	I2C_voidStopCondition();
	State=EEPROM_OK;
	
	return State;
	
}
EEPROM_ErrorStatus EEPROM_enuRead(u8 * Copy_Pu8Data, u8 Copy_u8Block, u8 Copy_u8Address){
	
	EEPROM_ErrorStatus State= EEPROM_NOK;
	
	/* Step 1 Start Condition */
	I2C_voidStartCondition();
/* Step 2 Polling on Flag */
	I2C_voidWait();
	
	/* Step 3 Check Start Condition Acknowledgement */
	if (I2C_enuCheckAck(I2C_SC_ACK) != OK){
		State =	EEPROM_SC_ERROR;
		return State;
	}
	switch (Copy_u8Block)
	{
		case EEPROM_BLOCK0:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_0_W);
		break;
		
		case EEPROM_BLOCK1:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_1_W);
		break;
		
		case EEPROM_BLOCK2:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_2_W);
		break;
		
		case EEPROM_BLOCK3:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_3_W);
		break;
		
		default:
		State=EEPROM_OUT_OF_RANGE;
		return State;
	}
	
	I2C_voidWait();
	if (I2C_enuCheckAck(I2C_MT_SLA_W_ACK) != OK){
		State =	EEPROM_SLA_ERROR;
		return State;
	}
	/* Step 4 Write Address */
	I2C_voidWriteByte(Copy_u8Address);
	I2C_voidWait();
	if (I2C_enuCheckAck(I2C_MT_DATA_ACK) != OK){
		State =	EEPROM_ADDRESS_ERROR;
		return State;
	}

	/* Step 5 Repeated Start */
	I2C_voidStartCondition();	
	I2C_voidWait();
	if (I2C_enuCheckAck(I2C_SC_ACK) != OK){
		State =	EEPROM_RSC_ERROR;
		return State;
	}
	
	/* Step 6 Send Slave Address with read Bit */
	
	switch (Copy_u8Block)
	{
		case EEPROM_BLOCK0:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_0_R);
		break;
		
		case EEPROM_BLOCK1:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_1_R);
		break;
		
		case EEPROM_BLOCK2:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_2_R);
		break;
		
		case EEPROM_BLOCK3:
		I2C_voidWriteByte(EEPROM_AD_BLOCK_3_R);
		break;
		
		default:
		State=EEPROM_OUT_OF_RANGE;
		return State;
	}
	I2C_voidWait();
	if (I2C_enuCheckAck(I2C_MR_SLA_R_ACK) != OK){
		State =	EEPROM_SLA_R_ERROR;
		return State;
	}

	/* Step 7 Read Data */
	if(I2C_enuReadByte(Copy_Pu8Data) != OK){
	State=EEPROM_READ_ERROR;
	return State;
	}
	
	/* Step 8 Stop Condition */
	I2C_voidStopCondition();
	State = EEPROM_OK;
	return State;

	}