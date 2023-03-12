/*********************************************************************/
/*   Author             :    mustafa kazem				         */
/*	 Date 				:    12 march 2023 					     */
/*	 Version 			:    1.0V 							 	     */
/*	 Description 		:   Configuration Link Time in build process */
/*********************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "dio.h"
#include "Stepper_private.h"
#include "Stepper_config.h"

/************************************************/
/*              Array of motors                 */
/************************************************/

st_motor motors [NUM_MOTORS] =
{
	{DIO_PORTA,DIO_PIN0,DIO_PORTA,DIO_PIN1,DIO_PORTA,DIO_PIN2,DIO_PORTA,DIO_PIN3},
	{DIO_PORTA,DIO_PIN4,DIO_PORTA,DIO_PIN5,DIO_PORTA,DIO_PIN6,DIO_PORTA,DIO_PIN7},
	{DIO_PORTB,DIO_PIN0,DIO_PORTB,DIO_PIN1,DIO_PORTB,DIO_PIN2,DIO_PORTB,DIO_PIN3}
};