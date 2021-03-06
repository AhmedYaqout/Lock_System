/*******************************************/
/** Author      : ahmed mahmoud            */
/** Description : prg file for SEV         */
/** Date        : 22 Nov 2019		       */
/** Version     : 1.0V                     */
/*******************************************/


#include "STD_Types.h"
#include "BIT_math.h"
#include "util/delay.h"
#include "DIO_int.h"

#include "STEPPER_int.h"
#include "STEPPER_cfg.h"
#include "STEPPER_priv.h"


void Stepper_RotateCW(void)
{	
	DIO_enuSetPinValue(Coil_Blue, DIO_u8HIGH);
	DIO_enuSetPinValue(Coil_Pink, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Yellow, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Orange, DIO_u8LOW);
	_delay_ms(15);

	DIO_enuSetPinValue(Coil_Blue, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Pink, DIO_u8HIGH);
	DIO_enuSetPinValue(Coil_Yellow, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Orange, DIO_u8LOW);
	_delay_ms(15);

	DIO_enuSetPinValue(Coil_Blue, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Pink, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Yellow, DIO_u8HIGH);
	DIO_enuSetPinValue(Coil_Orange, DIO_u8LOW);
	_delay_ms(15);

	DIO_enuSetPinValue(Coil_Blue, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Pink, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Yellow, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Orange, DIO_u8HIGH);
	_delay_ms(15);
}

void Stepper_RotateACW(void)
{

	DIO_enuSetPinValue(Coil_Blue, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Pink, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Yellow, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Orange, DIO_u8HIGH);
	_delay_ms(15);

	DIO_enuSetPinValue(Coil_Blue, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Pink, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Yellow, DIO_u8HIGH);
	DIO_enuSetPinValue(Coil_Orange, DIO_u8LOW);
	_delay_ms(15);

	DIO_enuSetPinValue(Coil_Blue, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Pink, DIO_u8HIGH);
	DIO_enuSetPinValue(Coil_Yellow, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Orange, DIO_u8LOW);
	_delay_ms(15);

	DIO_enuSetPinValue(Coil_Blue, DIO_u8HIGH);
	DIO_enuSetPinValue(Coil_Pink, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Yellow, DIO_u8LOW);
	DIO_enuSetPinValue(Coil_Orange, DIO_u8LOW);
	_delay_ms(15);

}
