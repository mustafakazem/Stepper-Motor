#ifndef _STEPPER_config_H
#define _STEPPER_config_H


#define NUM_MOTORS  3

extern st_motor motors [NUM_MOTORS] ;


#define  FULL_STEP          1
#define  HALF_STEP          2

#define ST_MOTOR_ROTATION  FULL_STEP

#define  CW          1
#define  CCW         2
#define  STOP        3

#define  MINSPEED     20
#define  MAXSPEED     300


#endif  /* End of the file guard*/