/*************************************/
/*Author : Ahmed Mahmoud      */
/*Description : BIT_math Lib  */
/*Date :19 oct 19             */
/*Version : 1.0V              */
/*************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(reg,bitno) reg|=(1<<bitno)
#define CLR_BIT(reg,bitno) reg&=~(1<<bitno)
#define TGL_BIT(reg,bitno) reg^=(1<<bitno)
#define GET_BIT(reg,bitno) ((reg>>bitno)&(0x01))


#define conc(b7,b6,b5,b4,b3,b2,b1,b0)         conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define conc_help(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif