/**
* Author		:		Ahmad Yaqoot
* Description	:	    EXECUTABLE I2C Program file
* Date			:		29/AUG/2020
* Version		:		V1.0
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_inter.h"
#include "I2C_config.h"
#include "I2C_private.h"


ErrorStatus I2C_enuStart(void)
{ u8 Local_State	=	0;
	TWCR = (1<<TWINT_LOCATION)|(1<<TWSTA_LOCATION)| (1<<TWEN_LOCATION)
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & I2C_STATUS_NO_INFO) != START){
		 Local_State	=	;
		 }
}
ErrorStatus I2C_enuReStart(void);
ErrorStatus I2C_enuStop(void);
ErrorStatus I2C_enuWriteData(u8 Copy_u8Address,u8 Copy_u8Data);
ErrorStatus I2C_enuReadData(u8 Copy_u8Address, u8 * Copy_pu8Data);
