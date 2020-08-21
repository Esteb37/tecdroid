/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Drive.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/DriverStation.h>




Drive::Drive(Drivetrain* subsystem)
    : drivetrain{subsystem} {
    AddRequirements({subsystem});

}

void Drive::Initialize(){

}

void Drive::Execute(){

}

bool Drive::IsFinished(){
    return false;
}

void Drive::End(bool interrupted){

}

