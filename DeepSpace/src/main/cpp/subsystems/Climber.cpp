/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "subsystems/Climber.h"
#include <frc/WPILib.h>
#include "RobotMap.h"
#include "commands/Climb.h"
#include <frc/ADXRS450_Gyro.h>

Climber::Climber() : frc::Subsystem("Climber") {
	m_elevator.SetInverted(false);
	m_slider.SetInverted(false);
}

void Climber::InitDefaultCommand() {
  SetDefaultCommand(new Climb);
}

void Climber::SetElevator(double value) {
	m_elevator.Set(value);
}
void Climber::SetSlider(double value){
    m_slider.Set(value);
}

