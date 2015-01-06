motor[ motorLeft ] = 100;
motor[ motorRight ] = 100;
wait1Msec( 3300 );

motor[ motorLeft ] = -100;
motor[ motorRight ] = 100;
wait1Msec( 500 );

if( SensorValue[ IRSensor ] == 5 || SensorValue[ IRSensor ] == 6 )
{
	motor[ motorLeft ] == -100;
	motor[ motorRight ] == 100;
	wait1Msec( 500 );

	motor[ motorLeft ] == 100;
	motor[ motorRight ] == 100;
	wait1Msec( 500 );

	motor[ motorLeft ] == 100;
	motor[ motorRight ] == -100;
	wait1Msec( 1000 );

	motor[ motorLeft ] == 100;
	motor[ motorRight ] == 100;
	wait1Msec( 2500 );