/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
 
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <RobotContainer.h>



void Robot::RobotInit() {
  cs::UsbCamera cam = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
  cam.SetResolution(640,480);
  cam.SetFPS(40);
  cs::UsbCamera cam2 = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
  cam2.SetResolution(640,480);
  cam2.SetFPS(40);
}

void Robot::RobotPeriodic() { 
  
  frc2::CommandScheduler::GetInstance().Run(); 
}

void Robot::DisabledInit() {
  
}

void Robot::DisabledPeriodic() {
  m_container.Reset();
}

void Robot::AutonomousInit() {
  step = 0;
  auton->Reset();
  m_container.Reset();
  
}


void Robot::AutonomousPeriodic() {
  m_container.Lower();
  switch(movements[step]){
    case 'm':
      if(auton->Move(targets[step])){
        auton->Disable();
        auton->Reset();
        step++;        
      }
      break;
    case 'l':
      if(auton->MoveLoad(targets[step])){
        auton->Disable();
        auton->Reset();
        step++;        
      }
      break;
    case 't':
      if(auton->Turn(targets[step])){
        auton->Disable();
        auton->Reset();
        step++;
      }
      break;
    case 'i':
      if(auton->Intake(targets[step])){
        auton->Disable();
        auton->Reset();
        step++;
      }
      break;
    case 's':
      if(auton->Launch()){
        
        step++;
      }
      break;
    case 'p':
      if(auton->Start()) step++;
      break;
    default:
      auton->Disable();
      break;
  }
  
  
}

void Robot::TeleopInit() {
  
  auton->Disable();
  auton->Reset();
  m_container.Reset();
  

}

void Robot::TeleopPeriodic() {
  m_container.Lower();
  m_container.Drive();  
  
}


void Robot::TestInit(){
  
}
void Robot::TestPeriodic() {
  
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif