#include <frc/Encoder.h>
#include <frc/VictorSP.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc2/command/PIDSubsystem.h>
#include <units/units.h>
#include <adi/ADIS16448_IMU.h>
#include "Constants.h"
#include "frc/drive/DifferentialDrive.h"
#include <adi/ADIS16448_IMU.h>
#include <frc/BuiltInAccelerometer.h>

using namespace frc;

class Autodrive : public frc2::PIDSubsystem {
 public:
  Autodrive();

  void UseOutput(double output, double setpoint) override;

  double GetMeasurement() override;

  bool AtSetpoint();

  void RunFeeder();

  void StopFeeder();

 private:
     
  VictorSP right{mChasisRight};
  VictorSP left{mChasisLeft};
  ADIS16448_IMU gyro;
  Encoder encoderRight{4, 5,false,Encoder::EncodingType::k4X};
  Encoder encoderLeft{2, 3,true,Encoder::EncodingType::k4X};
  DifferentialDrive chasis{right,left};
  
};