#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S3,     SonarSensor,    sensorSONAR)
#pragma config(Sensor, S4,     IRSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     driveRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     driveLeft,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     beltMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     liftMotor,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    goalServo,            tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    SonarServo,           tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

const int ONEROTATION = 1410;
const int QUARTERTURNATHALFPOWER = 2100;
const int overEncoderAmount = 2000; //
const int CIRCUMFERENCEOFWHEEL = 31.9;
const float encoderTicksPerCentimeters =  ONEROTATION / CIRCUMFERENCEOFWHEEL;
const int STARTPOSITION = 250;

//Function Prototyping
void turnRight(int degree);
void turnLeft( int degree );
void goForward( int distance );
int getIrReading( tSensors irReceiverPin);

//Sets initialization values
void initializeRobot()
{
  servo[ goalServo ] = STARTPOSITION; //Initializes servo to start position
}


task main()
{
	bFloatDuringInactiveMotorPWM = false;  //Motor brakes when idle
	initializeRobot();
	//waitForStart(); // Wait for the beginning of autonomous phase.
	while( true )
	{
		if (getIrReading ( IRSensor ) == 5)
		{
				motor[ driveLeft ] = 0;
				motor[ driveRight ] = 0;
		}
		else if (getIrReading ( IRSensor ) < 5)
		{
			turnLeft(5);
		}
		else if (getIrReading ( IRSensor ) > 5)
		{
			turnRight(5);
		}
		else
		{
			motor[ driveLeft ] = 0;
			motor[ driveRight ] = 0;
		}
	}

  //nxtDisplayCenteredtextLine ( 3, "Sensor Value: %d", SensorValue[ SonarSensor ] );  // display "Sensor Value: ##"
  wait1Msec ( 100 );
}




void goForward( int distance ) //centimeters
{
	int encoderTicksNeeded = -( distance * encoderTicksPerCentimeters );
	nMotorEncoder[ driveLeft ] = 0;
  nMotorEncoder[ driveRight ] = 0;
  int hiSpeedTicks = encoderTicksNeeded + overEncoderAmount;

 	while( nMotorEncoder[ driveLeft ] > hiSpeedTicks && nMotorEncoder[ driveRight ] > hiSpeedTicks )
	{
		motor[ driveLeft ] = 50;
  	motor[ driveRight ] = 50;
	}
// motor[ driveLeft ] = 0;
// motor[ driveRight ] = 0;
// wait1Msec( 1000 );
	while( nMotorEncoder[ driveLeft ] > encoderTicksNeeded && nMotorEncoder[ driveRight ] > encoderTicksNeeded )
	{
		motor[ driveLeft ] = 10;
		motor[ driveRight ] = 10;
	}
	motor[ driveLeft ] = 0;
	motor[ driveRight ] = 0;
}

void turnRight(int degree )
{
	nMotorEncoder[ driveLeft ] = 0;
  nMotorEncoder[ driveRight ] = 0;
  int encoderAmount = QUARTERTURNATHALFPOWER / 90 * degree;
  while( nMotorEncoder[ driveLeft ] > -encoderAmount && nMotorEncoder[ driveRight ] > -encoderAmount )
	{
		motor[ driveLeft ] = 50;
		motor[ driveRight ] = -50;
	}
	motor[ driveLeft ] = 0;
	motor[ driveRight ] = 0;
}

void turnLeft( int degree )
{
	nMotorEncoder[ driveLeft ] = 0;
  nMotorEncoder[ driveRight ] = 0;
  int encoderAmount = QUARTERTURNATHALFPOWER / 90 * degree;

  //Turn
  while( nMotorEncoder[ driveLeft ] > -encoderAmount && nMotorEncoder[ driveRight ] > -encoderAmount )
	{
		motor[ driveLeft ] = -50;
		motor[ driveRight ] = 50;
	}

	//Stop robot
	motor[ driveLeft ] = 0;
	motor[ driveRight ] = 0;
}

int getIrReading( tSensors irReceiverPin )
{
	wait1Msec( 1 );
  int ir = SensorValue[ irReceiverPin ];
  return ir;
}
