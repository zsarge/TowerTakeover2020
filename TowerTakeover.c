#pragma config(Motor,  port2,           leftRear,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightRear,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           verticalArm,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightIntake,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftIntake,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
] This is the code for Elder High School's Vex Robot for the Tower Takeover Competition for 2019
] Last edited: Sunday, 12/1/2019
]
] Controls:
] Button            | Description
}-----------------------+---------------------------------------------------------------
] Left Joystick     | Controls the front left and back left motors. Pushing the joystick away from your body makes the motors go forward. Pulling the joystick towards your body makes the motors bo backward.
] Right Joystick    | Controls the front right and back right motors. It behaves the same way as the left joystick.
] Button 8U         | Controls the vertical scissor arm. Pushing down this button sends full power forward to the motor. This should cause the vertical arm to raise.
] Button 8D         | Controls the vertical scissor arm. Pushing down this button sends full power backwards to the motor. This should cause the vertical arm to lower. (With the current design, it stops at a certian point and cannot get to the original down position. Be aware.)
] Button 6U         | Controls the flipper arm. Pushing down this button sends full forwards power to the flipper motor. This should cause the flipper arm to raise, until it is no longer held by the gear.
] Button 6D         | Controls the flipper arm. Pushing down this button sends full backwards power to the flipper motor. This should cause the flipper arm to lower, until it pops back up.
] Button 5U         | Controls the flipper arm. Pushing down this button sends 15% backwards power to the flipper motor. This should cause the flipper arm to raise, this should cause the flipper arm to move back up, but at a slower pace than full power.
] Button 5D         | Controls the flipper arm. Pushing down this button sends 15% forwards power to the flipper motor. This should cause the flipper arm stay in place under the tension of the rubber bands.
]
]Ports:
] I/O pin   | Description
}-----------+-------------------------------------------------------------------------
]   2       | This is the right rear motor. In our case, this is a large motor.
]   3       | This is the left rear motor. In our case, this is a large motor.
]   4       | This is the front right motor. In our case, this is a small motor.
]   5       | This is the front left motor. In our case, this is a small motor.
]
*/

//Competition and duration controls
#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma AutonomousDuration(0)
#pragma userControlDuration(120)
#include "VEX_Competition_Includes.c"   //Main competition background code - DO NOT MODIFY!!!

void pre_auton()
{
    bStopTasksBetweenModes = true;
}

task autonomous()       //autonomous program (Ours worked perfectly every time)
{
}

task usercontrol ()
{

    while (true)                //loop runs forever
    {
        motor[rightRear] = vexRT[Ch2]; //Full power is 127

        motor[leftRear] = vexRT[Ch3]; //Full power is 127

        // Vertical Arm COntrol
				if(vexRT[Btn5U] == 1)
				{
					motor[verticalArm] = -127;
				}
				else if(vexRT[Btn5D] == 1)
				{
					motor[verticalArm] = 127;
				}
				else
				{
					motor[verticalArm] = 0;
				}

				// Intake Control
				if(vexRT[Btn6U] == 1)
				{

					motor[rightIntake] = -125;
					motor[leftIntake]  = -125;
				}
				else if(vexRT[Btn6D] == 1)
				{
					motor[rightIntake] = 127;
					motor[leftIntake] = 127;
				}
				else
				{
					motor[rightIntake] = 0;
					motor[leftIntake] = 0;
				}

    }
}
