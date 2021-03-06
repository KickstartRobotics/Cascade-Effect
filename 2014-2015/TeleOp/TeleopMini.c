#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     driveRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     driveLeft,     tmotorTetrix, openLoop, reversed)
//#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
//#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
//#pragma config(Motor,  mtr_S1_C2_1,     beltMotor,     tmotorTetrix, openLoop)
//#pragma config(Motor,  mtr_S1_C2_2,     liftMotor,     tmotorTetrix, openLoop)
//#pragma config(Servo,  srvo_S2_C1_1,    liftToggle,           tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//*Includes*//
#pragma debuggerWindows("joystickGame");
#include "JoystickDriver.c" //Include file to "handle" the Bluetooth messages.
//#include "controlFunctions.h"

//*Constants*//
const int BUTTONX  			= 1;
const int BUTTONA 		  = 2;
const int BUTTONB       = 3;
const int BUTTONY  			= 4;
const int BUTTONLB 			= 5;
const int BUTTONRB 			= 6;
const int BUTTONLT 			= 7;
const int BUTTONRT 			= 8;
bool sloMo 							= false;
bool direction 					= false;

//*Global Variables*//
float moveModifier				= 1;

//*Function Prototypes
//void initializeRobot();
void moveRobot();
//void moveLift();
//void runConveyer();
int toggleSloMo(int counter);
int toggleDirection(int counter);


//The main task will run the robot initialization and then will wait for the signal from FCS
//to begin and enter the continuous loop that recieves joystick values and executes functions
//with this data.
task main()
{
  //initializeRobot();   //Sets servos into

  waitForStart();   // Waits for start of tele-op phase
	int sloMoCounter = 0;
	int directionCounter = 0;
  while ( true )
  {

  	//Updates joystick variables with data from joystick station
		getJoystickSettings( joystick );
		moveRobot();
		sloMoCounter = toggleSloMo(sloMoCounter);
		directionCounter = toggleDirection(directionCounter);
  	//runConveyer();
  	//moveLift();
  	//moveServo();

  }
}
//*Functions*//

//Sets all values and servos prior to the start of the telop mode.
/*void initializeRobot()
{
	servo[ liftToggle ] = 130; //Initializes servo to start position
  return;
}

//
void moveServo()
{
	//Moves servo to down position if the a button is pressed
	if( joy1Btn( BUTTONA ) )
		{
			servo[ liftToggle ] = 250;
			wait1Msec(1);
		}

	//Moves servo to up position if the b button is pressed
		if( joy1Btn( BUTTONB ) )
		{
			servo[ liftToggle ] = 130;
			wait1Msec(1);
		}
}


void runConveyer()
{
	if( joy1Btn( BUTTONRB ) )
	{
		motor[ beltMotor ] = 15;
		wait1Msec(1);
	}
	else if ( joy1Btn( BUTTONLB ) )
  {
  	motor[ beltMotor ] = -15;
  	wait1Msec(1);
  }
	else
	{
		motor[ beltMotor ] = 0;
		wait1Msec(1);
	}
}

void moveLift()
{
	//Moves the lift upwards
	if( joy1Btn( BUTTONRT ) )
	{
			motor( liftMotor ) = 100;
			wait1Msec(10);
	}
	else
	{
		motor( liftMotor ) = 0;
		wait1Msec(10);
	}
	//Moves the lift down
	if( joy1Btn( BUTTONLT ) )
	{
			motor( liftMotor ) = -100;
			wait1Msec(10);
	}
	else
	{
		motor( liftMotor ) = 0;
		wait1Msec(10);
	}
}
*/

int toggleSloMo(int counter)
{
	if(joy1Btn( BUTTONA ))
	{

		if( counter > 100 && !sloMo )
		{
			moveModifier *= 10;
			sloMo = true;
			return -1000;
		}
		else if(counter > 100)
		{
			moveModifier /= 10;
			sloMo = false;
			return -1000;
		}
		else
		{
		return ++counter;
		}
	}
	else
	{
		return 0;
	}
}
int toggleDirection(int counter)
{
	if(joy1Btn( BUTTONY ))
	{

		if(counter > 100 && !direction)
		{
			moveModifier *= -1;
			direction = true;
			return -1000;
		}
		else if(counter > 100)
		{
			moveModifier *= -1;
			direction = false;
			return -1000;
		}
		else
		{
				return ++counter;
		}
	}
	else
	{
		return 0;
	}
}
//Recieves joystick data from controllers then modifies that value
//and sets the motor equal to the modified value.
void moveRobot()
{
	if ( ( joystick.joy1_y1 > -5 && joystick.joy1_y1 < 5 ) && ( joystick.joy1_y2 > -5 && joystick.joy1_y2 < 5 ) )
	{
		 motor[ driveLeft ] = 0;
	   motor[ driveRight ] = 0;
	}
	else
	{
		motor[ driveLeft ] 		  = joystick.joy1_y2 / moveModifier;
  	motor[ driveRight ] 		= joystick.joy1_y1 / moveModifier;
  }
}
