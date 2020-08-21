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
#include <frc/VictorSp.h>
#include "RobotMap.h"
#include <frc/Timer.h>

class Intake : public frc::Subsystem {
 public:
  Intake();
  void InitDefaultCommand() override;

  //Set motor value
  void Set(double value);

  //Stop motor
  void Stop();

  //Functions for controlling the time 
  void StartTime();
  void StopTime();
  double GetTime();

 private:
  
  //Motor for the intake controlled by a VictorSP
  frc::VictorSP m_intake{p_intake};

  //Timer object to control take time
  frc::Timer timer;

};
