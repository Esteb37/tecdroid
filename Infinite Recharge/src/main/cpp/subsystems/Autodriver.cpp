/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Autodriver.h"
#include <frc/smartdashboard/smartdashboard.h>
#include <math.h>
#include "Constants.h"


using namespace frc;


Autodriver::Autodriver() {

   
}

void Autodriver::Periodic() {
    
    float anglex = gyro.GetGyroAngleX();
    SmartDashboard::PutNumber("AngleX",anglex);
    float angley = gyro.GetGyroAngleY();
    SmartDashboard::PutNumber("AngleY",angley);
    float anglez = gyro.GetGyroAngleZ();
    SmartDashboard::PutNumber("AngleZ",anglez);
    float accelx = accelerometer.GetX()*9.80665;
    SmartDashboard::PutNumber("Accelx",accelx);
    float accely = accelerometer.GetY()*9.80665;
    SmartDashboard::PutNumber("AccelY",accely);
    float accelz = accelerometer.GetZ()*9.80665;
    SmartDashboard::PutNumber("AccelZ",accelz);
  
    SmartDashboard::PutNumber("Encoder Right",encoderRight.GetDistance());
    SmartDashboard::PutNumber("Encoder Left",encoderLeft.GetDistance());
    SmartDashboard::PutNumber("Error",encoderRight.GetDistance()-encoderLeft.GetDistance());
    
 
}





