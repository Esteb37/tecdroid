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
#include "frc/controller/PIDController.h"
#include "frc/PIDOutput.h"
#include "frc/PIDSource.h"
#include "frc/PIDController.h"

using namespace frc;


class GyroOutput : public PIDOutput {
  public:
    explicit GyroOutput(Drivetrain& r)
    :m_rd(r) {
      
    }

    void PIDWrite(double output) override {
      m_rd.Drive(0, output);
    }

  private:
    Drivetrain& m_rd;
};

class EncoderOutput : public PIDOutput {
  public:
    explicit EncoderOutput(Drivetrain& r)
      : m_rd2(r) {
      
    }

    void PIDWrite(double output) override {
      m_rd2.Drive(output, 0);
    }

  private:
    Drivetrain& m_rd2;
};

class Autodriver : public frc2::SubsystemBase {
 public:
  Autodriver(Drivetrain chasis_){
    chasis = chasis_;
  }

  void Periodic() override;

 private:
  ADIS16448_IMU gyro;
  Encoder encoderRight{4, 5,false,Encoder::EncodingType::k4X};
  Encoder encoderLeft{2, 3,true,Encoder::EncodingType::k4X};
  BuiltInAccelerometer accelerometer;
  EncoderOutput *mEncoderOutput = new EncoderOutput(chasis);
  GyroOutput *mGyroOutput = new GyroOutput(chasis);
  Drivetrain chasis;
  frc::PIDController pidControllerGyro { 1,0.8, 0.5, &gyro,mGyroOutput};
  frc::PIDController pidControllerEncoder { 1, 0.8, 0.5, &encoderRight,mEncoderOutput};

};

  