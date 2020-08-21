/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Auto.h"
#include <frc/smartdashboard/smartdashboard.h>
#include "Constants.h"
#include <frc/Preferences.h>


using namespace frc;


Auto::Auto(Drivetrain& drivetrain_,Tower& tower_, Shooter& shooter_): chasis{drivetrain_},tower(tower_),shooter(shooter_) {

    //turn.SetInputRange(-360,360);
    //turn.SetOutputRange(-kAutoTurn, kAutoTurn);
    speed.SetInputRange(-360,360);
    speed.SetOutputRange(-kAutoSpeed, kAutoSpeed);
    encoder.SetDistancePerPulse(kEncoderPulse);
    speed.SetPIDSourceType(PIDSourceType::kDisplacement);
  
}

void Auto::Periodic() {
    SmartDashboard::PutNumber("Encoder",encoder.GetDistance());
    //SmartDashboard::PutNumber("Gyrp",gyro.GetAngle());
}

void Auto::Reset(){
    
    encoder.Reset();
    //gyro.Reset();
    
    //turn.Reset();
    speed.Reset();

    
}


bool Auto::Move(float setpoint){

    speed.SetSetpoint(setpoint);
    if(fabs(speed.GetError())<6) speed.SetOutputRange(-kAutoSpeed*0.7,kAutoSpeed*0.7);
    else speed.SetOutputRange(-kAutoSpeed,kAutoSpeed);
    //turn.Enable();
    speed.Get();
    speed.Enable();
    return AtDistance();
}

bool Auto::MoveLoad(float setpoint){
    if(timer.Get()<1.5){
      shooter.SetMotor(kShooterSpeed*timer.Get()/1.5);
    }
    if(timer.Get()>1.5){
       shooter.SetMotor(kShooterSpeed);
    }
    speed.SetSetpoint(setpoint);
    if(fabs(speed.GetError())<6) speed.SetOutputRange(-kAutoSpeed*0.7,kAutoSpeed*0.7);
    else speed.SetOutputRange(-kAutoSpeed,kAutoSpeed);
    speed.Get();
    speed.Enable();
    return AtDistance();
}
bool Auto::Intake(float setpoint){
    
    tower.SetMotor(kIntakeSpeed);
    return Move(setpoint);
    return false;
}



bool Auto::Turn(float setpoint){

    /*turn.SetSetpoint(setpoint);
    if(fabs(turn.GetError())<10) turn.SetOutputRange(-kAutoTurn*0.7,kAutoTurn*0.7);
    else turn.SetOutputRange(-kAutoTurn,kAutoTurn);
    turn.Get();
    turn.Enable();
    return AtAngle();*/
    return true;
    
}

bool Auto::AtDistance(){
    
    return fabs(speed.GetError())<0.1;
}

bool Auto::AtAngle(){
    return true; //fabs(turn.GetError())<0.1;
}

bool Auto::Launch(){

    
    if(timer.Get()>3){
       shooter.Open();
       tower.SetMotor(kTowerSpeed);
      if(timer.Get()>7){
        tower.SetMotor(0);
        shooter.SetMotor(0);
        return true;
      }
      else return false;  
    }
    else{
        return false;
    }
    
}

bool Auto::Start(){
    timer.Reset();
    timer.Start();
    prepare->Schedule();
    return true;
}
void Auto::Disable(){
    speed.SetOutputRange(-kAutoSpeed,kAutoSpeed);
   // turn.SetOutputRange(-kAutoTurn,kAutoTurn);
    speed.Disable();
   // turn.Disable();
}


bool Auto::IsActive(){
    return /*turn.IsEnabled()||*/speed.IsEnabled();
}