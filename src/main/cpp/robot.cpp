/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

const int joy_idx = 0;
const int joy_x_axis_idx = 1;
const int joy_y_axis_idx = 4;
const int joy_manipulator_button = 4;

const int drivebase_talonsrx_id_left = 0;
const int drivebase_talonsrx_id_right = 1;
const int manipulator_talonsrx_id = 2;

const float manipulator_speed = 1.0;
const float drive_speed = 1.0;

void Robot::RobotInit() {
    this->drivebase_left = new TalonSRX(drivebase_talonsrx_id_left);
    this->drivebase_right = new TalonSRX(drivebase_talonsrx_id_right);
    this->manipulator = new TalonSRX(manipulator_talonsrx_id);
    this->joy = new frc::Joystick(joy_idx);
}

void Robot::TeleopPeriodic() {
    float joy_x = joy->GetRawAxis(joy_x_axis_idx);
    float joy_y = joy->GetRawAxis(joy_y_axis_idx); 
    float drive_left_percent = joy_y - joy_x;
    float drive_right_percent = joy_y + joy_x;
    this->drivebase_left->Set(ControlMode::PercentOutput, drive_left_percent * drive_speed);
    this->drivebase_right->Set(ControlMode::PercentOutput, drive_right_percent * drive_speed);

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
