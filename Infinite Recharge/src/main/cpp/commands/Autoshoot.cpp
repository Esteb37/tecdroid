/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shoot.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/DriverStation.h>
#include <frc/Timer.h>



Shoot::Shoot(Shooter* shooter_,Tower* tower_)
    : shooter{shooter_},tower{tower_} {
    AddRequirements({shooter,tower});

}

void Shoot::Initialize(){
 
    shooter->timer.Reset();
    shooter->timer.Start();
}

void Shoot::Execute(){
    
    bool climbMode = SmartDashboard::GetBoolean("Climb Mode",false);
    if(!climbMode){
        shooter->SetMotor(kShooterSpeed);
        shooter->Open();
    }
    tower->SetMotor(-kTowerSpeed);
    
}

bool Shoot::IsFinished(){
   bool climbMode = SmartDashboard::GetBoolean("Climb Mode",false);
   return shooter->timer.Get()>kShootTime||climbMode;
}

void Shoot::End(bool interrupted){
    tower->SetMotor(0);
}

