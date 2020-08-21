/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      January, 19, 2019
      |___|    |________/
-------------------------------------------------------------*/
#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/VictorSp.h>
#include "RobotMap.h"


class Wrist : public frc::Subsystem {
 public:
  Wrist();
  void InitDefaultCommand() override;

  //Set motor value
  void Set(double value);

 private:

  //Motor for the wrist controlled by a VictorSP
  frc::VictorSP m_wrist{p_wrist};

};
