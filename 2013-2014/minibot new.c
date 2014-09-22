#pragma config(Motor,  motorB,          motorBack,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorR,        tmotorNXT, PIDControl, encoder)

#pragma debuggerWindows("joystickSimple");
#include "JoystickDriver.c"

//const int buttonLB = 5;
//const int buttonRB = 6;
//const int buttonLT = 7;
//const int buttonRT = 8;
//const int maxMotor =127;

//task main()
//{
	while( true )
	{
		getJoystickSettings(joystick);
		motor(motorB)=joystick.joy1_y2;
		motor(motorC)=joystick.joy1_y1;
	}
}
