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
    shooter->Light(true);
}

void Shoot::Execute(){
    
    if(shooter->timer.Get()>kChargeTime){
      tower->SetMotor(kTowerSpeed);
    }
    
    
}

bool Shoot::IsFinished(){
   return shooter->timer.Get()>kShootTime+kChargeTime;
}

void Shoot::End(bool interrupted){
    tower->SetMotor(0);
    shooter->SetMotor(0);
    shooter->Light(false);
}

