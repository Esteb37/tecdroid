/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoMove.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/DriverStation.h>
#include <frc/Timer.h>



AutoMove::AutoMove(Auto* subsystem, float setpoint)
    : auton{subsystem} {
    AddRequirements({subsystem});

    auton->SetTargetDistance(setpoint);
    auton->SetTargetAngle(0);
}

void AutoMove::Initialize(){
   
    auton->Reset();

}

void AutoMove::Execute(){
    auton->Move();
}

bool AutoMove::IsFinished(){
    return auton->AtDistance();
 
}

void AutoMove::End(bool interrupted){
    auton->Disable();
}

