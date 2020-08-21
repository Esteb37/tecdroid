/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "subsystems/DriveTrain.h"

#include "RobotMap.h"
#include "commands/DriveChasis.h"
#include <frc/Joystick.h>
#include <frc/WPILib.h>

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
  m_robotDrive.SetSafetyEnabled(true);
	m_robotDrive.SetExpiration(0.1);
	m_robotDrive.SetMaxOutput(1.0);
	m_left.SetInverted(false);
	m_right.SetInverted(false);

}

void DriveTrain::Drive(double leftAxis, double rightAxis,bool active) {
	m_robotDrive.ArcadeDrive(leftAxis, rightAxis);
}



void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveChasis());
}

