/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/

#include "commands/Shoot.h"

#include "Robot.h"
#include <frc/Timer.h>
#include <frc/smartdashboard/SmartDashboard.h>

Shoot::Shoot() {
  Requires(&Robot::intake);
}

void Shoot::Initialize() {  
  Robot::intake.StartTime();
}

void Shoot::Execute() {
  frc::Preferences *pref;
  pref = frc::Preferences::GetInstance();
  float shoots = pref->GetFloat("s_shoot",s_shoot);
  
  
  Robot::intake.Set(-shoots);
}

bool Shoot::IsFinished() { return Robot::intake.GetTime()>=0.5;}

void Shoot::End() {
  Robot::intake.Stop();
  Robot::intake.StopTime();
}

void Shoot::Interrupted() {
  Robot::intake.Stop();
  Robot::intake.StopTime();
}
