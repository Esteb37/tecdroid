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
#include "RobotMap.h" 

class Hatch : public frc::Subsystem {
 public:
  Hatch();
  void InitDefaultCommand() override;

  //Set motor value
  void Set(double value);

  private:

  //Motor for the hatch panel collector controlled by a VictorSP
  frc::VictorSP m_hatch{p_hatch};
};
