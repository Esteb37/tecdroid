/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/

#include "commands/MoveWrist.h"

#include "Robot.h"
#include <frc/Preferences.h>

MoveWrist::MoveWrist() {
  Requires(&Robot::wrist);
}

void MoveWrist::Initialize() {

}

void MoveWrist::Execute() {
  auto& joystick = Robot::oi.GetJoystick(1);
  
  frc::Preferences *pref;
  pref = frc::Preferences::GetInstance();
  float wrists = pref->GetFloat("s_wrist",s_wrist);
  Robot::wrist.Set((joystick.GetRawAxis(j_rightTrigger)-joystick.GetRawAxis(j_leftTrigger))*0.7);
  
}

bool MoveWrist::IsFinished() { return true; }

void MoveWrist::End() {}

void MoveWrist::Interrupted() {}
