/*
 * Stepper_private.h
 *
 * Created: 3/12/2023 3:43:32 AM
 *  Author: sata
 */ 


#ifndef STEPPER_PRIVATE_H_
#define STEPPER_PRIVATE_H_



typedef struct Stepper_motor 
{
	u8 blue_port ;
	u8 blue_pin ;
	u8 pink_port ;
	u8 pink_pin ;
	u8 yellow_port ;
	u8 yellow_pin ;
	u8 orange_port ;
	u8 orange_pin ;
}st_motor ;



#endif  /* End of the file guard*/
