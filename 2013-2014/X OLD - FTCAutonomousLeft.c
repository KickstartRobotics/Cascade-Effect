
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorR,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorL,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorArm,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)

#include "JoystickDriver.c"

//Dillon & Chase & Will & Walsh(GOD)
//11/9/13
//left side Block and Ramp Autonomous

void RobotTurnLeft( int speed );
void RobotTurnRight( int speed );
void RobotMoveForward( int speed );
void RobotMoveBackward( int speed );
void StopRobot();

void initializeRobot()
{
  return;
}

task main()
{
  initializeRobot();

	waitForStart();

	RobotMoveBackward( 50 ); //move toward basket
	wait1Msec( 800 );

	StopRobot(); //stop robot in front of ramp

	motor[ motorArm ] = 80; //drop block in basket
	wait1Msec( 500 );

	motor[ motorArm ] = 0; //stop arm

	wait1Msec( 500 );

	RobotMoveForward( 50 ); //move back toward wall
	wait1Msec( 250 );

	RobotTurnRight( 50 ); //turn 90* left
	wait1Msec( 850 );

	RobotMoveForward( 50 ); //move forward till lined up with ramp
	wait1Msec( 850 );

	RobotTurnRight( 50 ); //turn 90* left
	wait1Msec( 1050 );

	RobotMoveForward( 50 ); // move forward till on ramp
	wait1Msec( 1600 );

	StopRobot();
	while(true){}
}

void RobotTurnLeft( int speed )
{
	motor[ motorR ] = -speed;
	motor[ motorL ] = speed;
}

void RobotTurnRight( int speed )
{
	motor[ motorR ] = speed;
	motor[ motorL ] = -speed;
}

void RobotMoveForward( int speed )
{
	motor[ motorR ] = speed;
	motor[ motorL ] = speed;
}

void RobotMoveBackward( int speed )
{
	motor[ motorR ] = -speed;
	motor[ motorL ] = -speed;
}

void StopRobot()
{
	motor[ motorR ] = 0;
	motor[ motorL ] = 0;
}
