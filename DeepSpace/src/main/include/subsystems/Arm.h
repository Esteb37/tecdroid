/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/VictorSp.h>
#include <frc/Encoder.h>
#include <frc/DigitalInput.h>

#include "RobotMap.h"

class Arm : public frc::Subsystem {
 public:
  Arm();
  void InitDefaultCommand() override;

  //Set motor value
  void Set(double value);

  //Stop motor
  void Stop();


  //Get angle of encoder
  frc::Encoder& GetEncoder();

  //Get if the encoder is active
  bool EncoderActive();

  //Get value of limit switches
  frc::DigitalInput& GetLimit(int limit);
  
 private: 

  //Motor for the armcontrolled by a VictorSP
  frc::VictorSP m_arm{p_arm};

  //Encoder to control the autonomous level
  frc::Encoder s_encoder{p_encoderArmA, p_encoderArmB, false, frc::Encoder::k4X};

  //Limit switches for safety
  frc::DigitalInput s_limitUp{p_limitArmUp};
  frc::DigitalInput s_limitDown{p_limitArmDown};
};
