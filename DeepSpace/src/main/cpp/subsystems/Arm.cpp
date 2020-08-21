/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "subsystems/Arm.h"

#include "RobotMap.h"
#include <frc/Encoder.h>
#include <frc/PIDSource.h>
#include "commands/MoveArm.h"

Arm::Arm() : frc::Subsystem("Arm") {
    s_encoder.SetPIDSourceType(frc::PIDSourceType::kDisplacement);
    s_encoder.SetDistancePerPulse(0.00048828125*360);
}

void Arm::InitDefaultCommand() {
    SetDefaultCommand(new MoveArm());
}
void Arm::Set(double value){
  m_arm.Set(value);
}

void Arm::Stop(){
  m_arm.Set(0);
}

frc::Encoder& Arm::GetEncoder() {
	return s_encoder;
    
}

frc::DigitalInput& Arm::GetLimit(int limit) {
    if(limit) return s_limitUp;
    else return s_limitDown;
}

bool Arm::EncoderActive(){
    return false;
}