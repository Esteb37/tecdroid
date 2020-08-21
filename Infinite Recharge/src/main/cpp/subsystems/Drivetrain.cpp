/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"
#include <frc/smartdashboard/smartdashboard.h>
#include <math.h>
#include "Constants.h"
#include <iostream>
#include <string.h>


using namespace frc;
using namespace std;

Drivetrain::Drivetrain() {

}

void Drivetrain::Periodic() {
    
   if(flag&&control.GetRawButton(cStart)){
       climbMode = !climbMode;
       flag = false;
   }
   else if(!control.GetRawButton(cStart)){
       flag = true;
   }
  
  SmartDashboard::PutBoolean("Climb Mode",climbMode);

  
  
}


void Drivetrain::Drive(){
    
    float x = control.GetRawAxis(4);
    float y = -control.GetRawAxis(1);
    chasis.ArcadeDrive(-y,x);

}

void Drivetrain::Drive(float y,float x){
    chasis.ArcadeDrive(y,x);

}


void Drivetrain::SetSafetyEnabled(bool state){
    chasis.SetSafetyEnabled(state);
}

void Drivetrain::Align(float speed){
    
    Drive(control.GetRawAxis(cLeftAxisY),speed);
}