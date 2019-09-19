/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

// Joystick preferences
const int joy_idx = 0;
const int joy_x_axis_idx = 1;
const int joy_y_axis_idx = 4;
const int joy_manipulator_button = 4;

// TalonSRX Addressing
const int drivebase_talonsrx_id_left = 0;
const int drivebase_talonsrx_id_right = 1;
const int manipulator_talonsrx_id = 2;

// Motor speed settings
const float manipulator_speed = 1.0;
const float drive_speed = 1.0;

void Robot::RobotInit() {
    // Initialize motor controllers and set pointers on this object 
    this->drivebase_left = new TalonSRX(drivebase_talonsrx_id_left);
    this->drivebase_right = new TalonSRX(drivebase_talonsrx_id_right);
    this->manipulator = new TalonSRX(manipulator_talonsrx_id);
    this->joy = new frc::Joystick(joy_idx);
}

void Robot::TeleopPeriodic() {
    // Capture joystick input
    float joy_x = joy->GetRawAxis(joy_x_axis_idx);
    float joy_y = joy->GetRawAxis(joy_y_axis_idx); 

    // Calculate tank-drive joystick movements
    // TODO: Clamp values between -1.0 and 1.0
    float drive_left_percent = joy_y - joy_x;
    float drive_right_percent = joy_y + joy_x;

    // Set drivebase speeds
    this->drivebase_left->Set(ControlMode::PercentOutput, drive_left_percent * drive_speed);
    this->drivebase_right->Set(ControlMode::PercentOutput, drive_right_percent * drive_speed);

    // Activate manipulator if the button is pressed
    if (joy->GetRawButton(joy_manipulator_button)) {
        this->manipulator->Set(ControlMode::PercentOutput, manipulator_speed);
    } else {
        this->manipulator->Set(ControlMode::PercentOutput, 0);
    }
}

// Unused for now
void Robot::TeleopInit() {}
void Robot::TestPeriodic() {}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
