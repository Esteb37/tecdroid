/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "commands/LevelArm.h"

#include "Robot.h"
#include <cmath>


void LevelArm::Put(double target,double speed) {
  Requires(&Robot::arm);
  SetInterruptible(true);
	m_target = target;
	m_speed = speed;
} 
LevelArm::LevelArm(double target) {
	Put(target,1);
}

LevelArm::LevelArm(double target,double speed) {
	Put(target, speed);
}

void LevelArm::Initialize() {

}

void LevelArm::Execute() {

  frc::Preferences *pref;
  pref = frc::Preferences::GetInstance();
  float autos = pref->GetFloat("s_auto",s_auto);
  float encoderActive = Robot::arm.EncoderActive();
  
  double angle = Robot::arm.GetEncoder().GetDistance;
  frc::SmartDashboard::PutNumber("Arm Angle",angle);
  if(encoderActive){
    m_error = (target - angle);
	  if (m_speed * kP * m_error >= m_speed) {
  		Robot::arm.Set(-m_speed*autos);
  	} else {
	  	Robot::arm.Set(-m_speed * kP * m_error);
	  };
  }
}

bool LevelArm::IsFinished() {
  auto& joystick = Robot::oi.GetJoystick(1);
  return (
            joystick.GetRawAxis(j_rightTrigger)+joystick.GetRawAxis(j_leftTrigger)>0
            ||std::fabs(m_error) <= kTolerance
            ||!Robot::arm.GetLimit(0).Get()
            ||!Robot::arm.GetLimit(1).Get()
          ); 
        /*|| IsTimedOut()*/; 
  }

void LevelArm::End() {
  Robot::arm.Set(0);
}

void LevelArm::Interrupted() {
  Robot::arm.Set(0);
}
