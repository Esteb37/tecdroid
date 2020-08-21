
#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/VictorSP.h"
#include "Constants.h"
#include "frc/Timer.h"
#include "frc/XboxController.h"
#include "frc/DoubleSolenoid.h"
#include "frc/Solenoid.h"

using namespace frc;

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void Periodic() override;
  void SetMotor(float speed);
  void Reset();
  void Open();
  void Light(bool on);
  void Move();

 private:
  VictorSP motor{mShooter};
  XboxController control{0};
  DoubleSolenoid stopper{pStopperFront,pStopperBack};
 // Solenoid light{5};
 public:
    frc::Timer timer;
  
};
