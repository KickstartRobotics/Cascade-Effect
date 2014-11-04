#pragma config(Hubs,  S1, HTMotor,  HtMotor,  none,  none)
#pragma config(Motor,  mtr_S1_C1_1,     motorR,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorL,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorBelt,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorLift,        tmotorTetrix, openLoop)
#pragma debuggerWindows("joystickGame");
#include "JoystickDriver.c"
const int buttonX  			= 1;
const int buttonA 		  = 2;
const int buttonB       = 3;
const int buttonY  			= 4;
const int buttonLB 			= 5;
const int buttonRB 			= 6;
const int buttonLT 			= 7;
const int buttonRT 			= 8;


task main()
{
	while( true )
	{
		getJoystickSettings( joystick );
 	  motor[ motorL ] 		= joystick.joy1_y2;
  	motor[ motorR ] 		= joystick.joy1_y1;
  	runConveyer();
  	runLift();
	}
}

void runConveyer()
{
	if ( joy1btn( buttonB ) )
	{
		motor[ motorBelt ] = 50;
		wait1Msec(1);
	}
	else
	{
		motor[ motorBelt ] = 0;
		wait1Msec(1);
	}
}

void runLift()
{
	if ( joy1btn( buttonRT ) )
	{
		motor[ motorLift ] = 50;
		wait1Msec(1);
	}
	else if ( joy1btn( buttonRB ) )
	{
		motor[ motorLift ] = -50;
		wait1Msec(1);
	}
	else {
		motor[ motorLift ] = 0;
		wait1Msec(1);
	}
}
