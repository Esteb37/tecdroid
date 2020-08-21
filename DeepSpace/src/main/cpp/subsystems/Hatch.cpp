/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "subsystems/Hatch.h"

#include "RobotMap.h"
#include "commands/MoveHatch.h"


Hatch::Hatch() : frc::Subsystem("Hatch") {}

void Hatch::InitDefaultCommand() {
  SetDefaultCommand(new MoveHatch());
}

void Hatch::Set(double value){
  m_hatch.Set(value);
}
