/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "commands/Climb.h"

#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Preferences.h>

Climb::Climb() {
  Requires(&Robot::climber);
}

void Climb::Initialize() {

}

void Climb::Execute() {
  auto& ruben = Robot::oi.GetJoystick(0);
  frc::Preferences *pref;
  pref = frc::Preferences::GetInstance();

  Robot::climber.SetElevator(-ruben.GetRawAxis(j_rightTrigger)+ruben.GetRawAxis(j_leftTrigger));
  
  
  
}	

bool Climb::IsFinished() {}

void Climb::End() {}

void Climb::Interrupted() {}
