/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "commands/DriveChasis.h"

#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Preferences.h>



DriveChasis::DriveChasis() {
  Requires(&Robot::drivetrain);
}

void DriveChasis::Initialize() {}

void DriveChasis::Execute() {
  auto& joystick = Robot::oi.GetJoystick(0);
  
  frc::Preferences *pref;
  pref = frc::Preferences::GetInstance();
  float chasisY = pref->GetFloat("s_chasisY",s_chasisY);
  float chasisX = pref->GetFloat("s_chasisX",s_chasisX);

  Robot::drivetrain.Drive(joystick.GetRawAxis(j_leftY)*1,
                         joystick.GetRawAxis(j_rightX)*0.65,joystick.GetRawButton(1));
   
  
  

}	

bool DriveChasis::IsFinished() {}

void DriveChasis::End() {}

void DriveChasis::Interrupted() {}
