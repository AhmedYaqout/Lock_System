/*************************************/
/*Author : Ahmed Mahmoud             */
/*Description : STD Lib              */
/*Date :18 oct 19                    */
/*Version : 1.0V                     */
/*************************************/
#ifndef  STD_TYPES_H
#define  STD_TYPES_H

typedef unsigned char       u8;
typedef unsigned short int u16;
typedef unsigned long int  u32;

typedef signed char         s8;
typedef signed short int   s16;
typedef signed long int    s32;

typedef float              f32;
typedef double             f64;
typedef long double       f128;



typedef enum{
	OK,
	NOK,
	NULL_POINTER,
	INDEX_OUT_OF_RANGE
	
	
}tenuErrorStatus;

typedef void (*PF) (void);


#endif