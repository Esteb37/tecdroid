
#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/VictorSP.h"
#include "frc/Timer.h"
#include "frc/Encoder.h"
#include "Constants.h"
#include "frc/drive/DifferentialDrive.h"
#include "frc/XboxController.h"
#include <adi/ADIS16448_IMU.h>
#include <frc/BuiltInAccelerometer.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/SerialPort.h>
#include <frc/PIDSource.h>

using namespace frc;




class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  void Periodic() override;
  void Drive();
  void Drive(float y,float x);
  void SetSafetyEnabled(bool state);
  void Align(float speed);

 private:
  VictorSP frontRight{mChasisFrontRight};
  VictorSP frontLeft{mChasisFrontLeft};
  VictorSP backRight{mChasisBackRight};
  VictorSP backLeft{mChasisBackLeft};
  SpeedControllerGroup right{frontRight,backRight};
  SpeedControllerGroup left{frontLeft,backLeft};
  XboxController control{0};
  DifferentialDrive chasis{right,left};

  bool flag = true;
  bool climbMode = false;
};

  