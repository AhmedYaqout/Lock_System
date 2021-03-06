/*******************************************/
/** Author      : Ahmed Yakout            */
/** Description : Priv file for EEPROM        */
/** Date        : 22 Nov 2019		       */
/** Version     : 1.0V                     */
/*******************************************/
#ifndef  EEPROM_PRIV_H 
#define  EEPROM_PRIV_H

/*8KB*/

/* Write */
#define EEPROM_AD_BLOCK_0_W	0b10100000
#define EEPROM_AD_BLOCK_1_W	0b10100010
#define EEPROM_AD_BLOCK_2_W	0b10100100
#define EEPROM_AD_BLOCK_3_W	0b10100110

/* Read */
#define EEPROM_AD_BLOCK_0_R	0b10100001
#define EEPROM_AD_BLOCK_1_R	0b10100011
#define EEPROM_AD_BLOCK_2_R	0b10100101
#define EEPROM_AD_BLOCK_3_R	0b10100111





#endif