/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <ctre/Phoenix.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/Joystick.h>

class Robot : public frc::TimedRobot {
    public:
        void RobotInit() override;
        void RobotPeriodic() override;
        void AutonomousInit() override;
        void AutonomousPeriodic() override;
        void TeleopInit() override;
        void TeleopPeriodic() override;
        void TestPeriodic() override;

    private:
        // TODO: Use std::shared_ptr<T> or std::unique_ptr<T> for greater safety.
        // WARNING: Currently incorrect as these items are never deallocated.

        // Pointers to motor controller objects
        TalonSRX* drivebase_left;
        TalonSRX* drivebase_right;
        TalonSRX* manipulator;

        // Pointers to Joystick controller objects
        frc::Joystick* joy;
};
