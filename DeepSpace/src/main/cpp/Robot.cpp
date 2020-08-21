/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

Hatch Robot::hatch;
Cam Robot::cam;
DriveTrain Robot::drivetrain;
Arm Robot::arm;
Climber Robot::climber;
Intake Robot::intake;
Wrist Robot::wrist;
OI Robot::oi;

void Robot::RobotInit() {
  Robot::cam.c_body = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
  Robot::cam.c_arm = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
  Robot::cam.server = frc::CameraServer::GetInstance()->GetServer();
  Robot::arm.GetEncoder().Reset();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {
    Robot::arm.GetEncoder().Reset();
}

void Robot::DisabledPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
}


void Robot::AutonomousInit() {


}

void Robot::AutonomousPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
}

void Robot::TeleopInit() {
    
}

void Robot::TeleopPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
    
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
