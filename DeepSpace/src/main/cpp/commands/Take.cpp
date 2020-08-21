/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "commands/Take.h"
#include <frc/GenericHID.h>
#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>

Take::Take() {
  Requires(&Robot::intake);
}

void Take::Initialize() {}

void Take::Execute() {
  auto& joystick = Robot::oi.GetJoystick(0);

  frc::Preferences *pref;
  pref = frc::Preferences::GetInstance();
  float takes = pref->GetFloat("s_take",s_take);

  

  Robot::intake.Set(-joystick.GetRawButton(j_leftBumper)*0.8);


  
}

bool Take::IsFinished() { 
  
   return false; 
   }

void Take::End() {
  Robot::intake.Stop();
}

void Take::Interrupted() {
  Robot::intake.Stop();
}
