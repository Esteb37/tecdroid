
#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/VictorSP.h"
#include "frc/XboxController.h"
#include "Constants.h"
#include "frc/DigitalInput.h"

using namespace frc;


class Elevator : public frc2::SubsystemBase {
 public:
  Elevator();

  void Periodic() override;
  
  void Elevate(float speed);
  void Slide(float speed);
  void Climb(float speed);

 private:
  XboxController control{0};
  VictorSP elevator{mElevator};
  VictorSP balancer{mBalancer};
  VictorSP climber{mClimber};
  DigitalInput limit{sElevatorSwitch};
};
