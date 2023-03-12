

/****************************************************************/
/*   Author             :    Mustafa Kazem				    */
/*	 Date 				:    28 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "dio.h"
#include "dio_types.h"
#include "Stepper_private.h"
#include "Stepper_config.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _STEPPER_INT_H
#define _STEPPER_INT_H

/****************************************************************/
/* Description    : This function used for stepper motor INIT  	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void ST_motorvidinit (u8 motor_nums);

/****************************************************************/
/* Description    : This function used for stepper motor to  	*/ 
/*                   the direction of the rotation and angle    */
/*					  of rotation and motor speed & steps       */
/*																*/
/*					Inputs : motor_nums , direction , speed		*/
/*                            type_steps , num_steps            */
/*					Return : void		 					    */
/****************************************************************/

void ST_motorvidmove (u8 motor_ID , u8 direction , u16 speed ,u16 num_steps);

#endif /* End of the file guard*/