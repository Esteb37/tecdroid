/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Balance.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/DriverStation.h>
#include <frc/Timer.h>



Balance::Balance(Elevator* subsystem)
    : elevator{subsystem} {
    AddRequirements({subsystem});

}

void Balance::Initialize(){
 
    

}

void Balance::Execute(){
    
    elevator->Balance();
    
}

bool Balance::IsFinished(){
   bool climbMode = SmartDashboard::GetBoolean("Climb Mode",false);
   return elevator->IsBalanced()||!climbMode;
}

void Balance::End(bool interrupted){
    elevator->Slide(0);
}

