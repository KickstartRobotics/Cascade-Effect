#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     IRSensorL,      sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     motorR,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorL,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorFlag,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorLift2,             tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servoIRbucket,        tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)

#pragma debuggerWindows("joystickSimple");
#include "JoystickDriver.c"


//Dillon & Chase & Will & Walsh(GOD)
//10/26/13
//Practice Programming

//Functions
void RobotTurnLeft( int speed );
void RobotTurnRight( int speed );
void RobotMoveForward( int speed );
void RobotMoveBackward( int speed );
void motionKill();
int getIrReading( tSensors irReceiverPin );

void initializeRobot()
{
	servo( servoIRbucket ) = 255;
  return;
}

////////////////////////////////////////////////////////////////////
task main()
{
	initializeRobot();
	waitForStart();
	bool found 	= false;
	int time 		= 0;
	ClearTimer( T1 );
  while( true )
	{
		if ( getIrReading ( IRSensorL ) == 5 )
  	{
  		time = time1[ T1 ];
  		motionKill();
      servo( servoIRbucket ) = 127;
      wait1Msec( 1000 );
      servo( servoIRbucket ) = 255;
      wait1Msec( 500 );
      found = true;
      //break
    }
    else if (	getIrReading (	IRSensorL	) != 5	)
    {
    	RobotMoveForward( 50 );
    }
   if( found )
     break;
  }

  		RobotMoveBackward( 50 );
    	wait1Msec( time - 300 );

    	RobotTurnRight( 50 ); //turn 90* left
			wait1Msec( 1350 );

    	RobotMoveBackward( 50 ); //move forward till lined up with ramp
			wait1Msec( 1400 );

			RobotTurnRight( 50 ); //turn 90* left
			wait1Msec( 1350 );

			RobotMoveBackward( 50 ); // move forward till on ramp
			wait1Msec( 1800 );

			motionKill();
}

//////////////////////////////////////////////////////

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

void motionKill()
{
	motor[ motorR ] = 0;
	motor[ motorL ] = 0;
}

int getIrReading( tSensors irReceiverPin )
{
	wait1Msec( 1 );
  int ir = SensorValue[ irReceiverPin ];
  return ir;
}
