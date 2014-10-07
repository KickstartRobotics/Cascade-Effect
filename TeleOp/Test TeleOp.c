#pragma config(Hubs,  S1, HTMotor,  none,  none,  none)
#pragma config(Motor,  mtr_S1_C1_1,     motorR,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorL,        tmotorTetrix, openLoop)


#pragma debuggerWindows("joystickGame");
#include "JoystickDriver.c"



task main()
{
	while( true )
	{
		getJoystickSettings( joystick );
 	  motor[ motorL ] 		= joystick.joy1_y2;
  	motor[ motorR ] 		= joystick.joy1_y1;
	}
}
