/****************************************************************/
/*   Author             :    Mustafa Kazem				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   prog.c for Stepper Motor            */
/****************************************************************/

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "stepper_motor_int.h"
#include <util/delay.h>

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : This function used for stepper motor INIT  	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void ST_motorvidinit (u8 motor_nums)
{
	/***************************************************************/
	/*         Configure all pins as output and low                */
	/***************************************************************/
	for (u8 i = 0 ; i <motor_nums ; i++ )
	{
		/*********************** BLUE WIRE ***********************/
		
		dio_vidConfigChannel(motors[i].blue_port,motors[i].blue_pin, OUTPUT);
		dio_vidWriteChannel(motors[i].blue_port,motors[i].blue_pin,STD_LOW);
		
		/*********************** PINK WIRE ***********************/
		
		dio_vidConfigChannel(motors[i].pink_port,motors[i].pink_pin, OUTPUT);
		dio_vidWriteChannel(motors[i].pink_port,motors[i].pink_pin,STD_LOW);
		
		/*********************** YELLOW WIRE ***********************/
		
		dio_vidConfigChannel(motors[i].yellow_port,motors[i].yellow_pin, OUTPUT);
		dio_vidWriteChannel(motors[i].yellow_port,motors[i].yellow_pin,STD_LOW);
		
		/*********************** ORANGE WIRE ***********************/
		
		dio_vidConfigChannel(motors[i].orange_port,motors[i].orange_pin, OUTPUT);
		dio_vidWriteChannel(motors[i].orange_port,motors[i].orange_pin,STD_LOW);
		
		_delay_ms(MAXSPEED);
	}
	
}

/****************************************************************/
/* Description    : This function used for stepper motor to  	*/
/*                   the direction of the rotation and angle    */
/*					  of rotation and motor speed & steps       */
/*																*/
/*					Inputs : motor_nums , direction , speed		*/
/*                            type_steps , num_steps            */
/*					Return : void		 					    */
/****************************************************************/

void ST_motorvidmove (u8 motor_ID , u8 direction , u16 speed ,u16 num_steps)
{
	
	#if (ST_MOTOR_ROTATION == FULL_STEP )
	switch (direction)
	{
		
		case CCW :
		
		for (u8 i = 0 ; i<num_steps ; i++ )
		{
			
			/***************         sequence of full step        *****************/
			/******************************** 1st ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 2nd ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 3rd ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 4th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_HIGH);
			
			_delay_ms(speed);
			
		}
		break;
		
		
		case CW :
		for (u8 i = 0 ; i<num_steps ; i++ )
		{
			/***************         sequence of full step        *****************/
			/******************************** 1st ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_HIGH);
			
			_delay_ms(speed);
			
			/******************************** 2nd ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 3rd ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 4th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
		}
		
		break;
		
		case STOP :
		for (u8 i = 0 ; i<num_steps ; i++ )
		{
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
		}
		_delay_ms(MAXSPEED);
		
		break;
	}
	
	#endif

	/**************************************************************************************************************/
	/***************                                 HALF STEP                                    *****************/
	/**************************************************************************************************************/

	#if (ST_MOTOR_ROTATION == HALF_STEP )

	switch (direction)
	{
		
		case CCW :
		
		for (u8 i = 0 ; i<num_steps ; i++ )
		{
			
			/***************         sequence of half step        *****************/
			/******************************** 1st ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_HIGH);
			
			_delay_ms(speed);
			
			/******************************** 2nd ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 3rd ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 4th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 5th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 6th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 7th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_HIGH);
			
			_delay_ms(speed);
			
			/******************************** 8th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_HIGH);
			
			_delay_ms(speed);
			
		}
		break;
		
		
		case CW :
		
		for (u8 i = 0 ; i<num_steps ; i++ )
		{
			
			/***************         sequence of half step        *****************/
			/******************************** 1st ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_HIGH);
			
			_delay_ms(speed);
			
			/******************************** 2nd ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_HIGH);
			
			_delay_ms(speed);
			
			/******************************** 3rd ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_HIGH);
			
			_delay_ms(speed);
			
			/******************************** 4th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 5th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 6th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 7th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
			/******************************** 8th ********************************/
			
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_HIGH);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
			
			_delay_ms(speed);
			
		}
		break;

		case STOP :
		for (u8 i = 0 ; i<num_steps ; i++ )
		{
			dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
			dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
		}
		_delay_ms(MAXSPEED);
		
		break;
		
		
		default:
		dio_vidWriteChannel(motors[motor_ID].blue_port,motors[motor_ID].blue_pin,STD_LOW);
		dio_vidWriteChannel(motors[motor_ID].pink_port,motors[motor_ID].pink_pin,STD_LOW);
		dio_vidWriteChannel(motors[motor_ID].yellow_port,motors[motor_ID].yellow_pin,STD_LOW);
		dio_vidWriteChannel(motors[motor_ID].orange_port,motors[motor_ID].orange_pin,STD_LOW);
		
		_delay_ms(MAXSPEED);
		
		break;
	}

	#endif
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/