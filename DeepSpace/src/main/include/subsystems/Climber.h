/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/VictorSP.h>
#include <frc/WPILib.h>
#include "RobotMap.h"

#include <frc/SPI.h>

class Climber : public frc::Subsystem {
 public:
  Climber();
  void InitDefaultCommand() override;

  //Functions for controlling the climber systems
  void SetElevator(double value);
  void SetSlider(double value);

 private:

  //Motor for the elevator controlled by a VictorSP
  frc::VictorSP m_elevator{p_elevator};

   //Motor for the slider controlled by a VictorSP
  frc::VictorSP m_slider{p_slider};
   
};
