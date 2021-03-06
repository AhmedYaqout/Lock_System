/*******************************************/
/** Author      : Ahmed Yakout            */
/** Description : interface file for EEPROM   */
/** Date        : 11 Jan 2020		       */
/** Version     : 1.0V                     */
/*******************************************/

#ifndef  EEPROM_INT_H 
#define  EEPROM_INT_H

#define EEPROM_BLOCK0	0
#define EEPROM_BLOCK1	1
#define EEPROM_BLOCK2	2
#define EEPROM_BLOCK3	3

typedef enum{
	EEPROM_OK,
	EEPROM_NOK,
	EEPROM_SC_ERROR,
	EEPROM_RSC_ERROR,
	EEPROM_OUT_OF_RANGE,
	EEPROM_SLA_ERROR,
	EEPROM_SLA_R_ERROR,
	EEPROM_ADDRESS_ERROR,
	EEPROM_READ_ERROR,
	EEPROM_DATA_ERROR
}EEPROM_ErrorStatus;

void EEPROM_voidInit(void);

EEPROM_ErrorStatus EEPROM_enuWrite(u8 Copy_u8Data, u8 Copy_u8Block, u8 Copy_u8Address);
EEPROM_ErrorStatus EEPROM_enuRead(u8 * Copy_Pu8Data, u8 Copy_u8Block, u8 Copy_u8Address);
#endif
