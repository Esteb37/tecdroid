
#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/VictorSP.h"
#include "frc/XboxController.h"
#include "Constants.h"
#include "frc/DoubleSolenoid.h"

using namespace frc;



class Tower : public frc2::SubsystemBase {
 public:
  Tower();

  void Periodic() override;
  void SetMotor(float speed);
  void Lower();
  void Reset();
  void Move();
  
 private:
 
  XboxController control{0};
  VictorSP motor{mIntake};
  DoubleSolenoid intake{pIntakeFront,pIntakeBack};
};
