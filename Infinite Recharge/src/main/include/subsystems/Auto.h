
#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/Timer.h"
#include "frc/Encoder.h"
#include "Constants.h"
#include <adi/ADIS16448_IMU.h>
#include <frc/BuiltInAccelerometer.h>
#include "Drivetrain.h"
#include "Shooter.h"
#include "Tower.h"
#include "commands/Prepare.h"
#include "commands/Shoot.h"
#include "frc/PIDController.h"
#include "frc/PIDOutput.h"
#include "frc/PIDSource.h"
#include "frc/Timer.h"
#include "frc/smartdashboard/SmartDashboard.h"

using namespace frc;

class GyroOutput : public frc::PIDOutput {
  public:
    explicit GyroOutput(Drivetrain& r)
    :m_rd(r) {
      m_rd.SetSafetyEnabled(false);
    }

    void PIDWrite(double output) override {
      
      m_rd.Drive(0, output);
    }

  private:
    Drivetrain& m_rd;
};

class EncoderOutput : public frc::PIDOutput {
  public:
    explicit EncoderOutput(Drivetrain& r)
    :m_rd(r) {
      m_rd.SetSafetyEnabled(false);
    }

    void PIDWrite(double output) override {
      
      m_rd.Drive(-output, 0);
    }

  private:
    Drivetrain& m_rd;
};


class PixyOutput : public frc::PIDOutput {
  public:
    explicit PixyOutput(Drivetrain& r)
    :m_rd(r) {
      m_rd.SetSafetyEnabled(false);
    }

    void PIDWrite(double output) override {
      
      m_rd.Align(output);
    }

  private:
    Drivetrain& m_rd;
};

class PixySource : public frc::PIDSource{
  public:
    explicit PixySource(){
      
    };

    double PIDGet(){
      pixy.Read(data,7);
      pixy.EnableTermination();
        float val = atoi(data);
        
        return val;
      
      
    }
  private:
    SerialPort pixy{115200,SerialPort::kUSB};
    char data[7];
};

class Auto : public frc2::SubsystemBase {
 public:
  explicit Auto(Drivetrain& drivetrain_,Tower& tower_, Shooter& shooter_);

  void Periodic() override;

  void Reset();
  void Disable();
  bool IsActive();

  bool Move(float setpoint);
  bool MoveLoad(float setpoint);
  bool Turn(float setpoint);
  bool Intake(float setpoint);
  bool Launch();
  bool Start();

  bool AtDistance();
  bool AtAngle();
  

 private:
    //ADIS16448_IMU gyro;
    BuiltInAccelerometer accelerometer;
    Encoder encoder{sEncoderA, sEncoderB,true,Encoder::EncodingType::k4X};
    PixySource source;
    
    Drivetrain& chasis;
    Tower& tower;
    Shooter& shooter;

    //PixyOutput *pixyOutput = new PixyOutput(chasis);
    //GyroOutput *turnOutput = new GyroOutput(chasis);
    EncoderOutput *speedOutput = new EncoderOutput(chasis);

    //PIDController turn { kTurnP, kTurnI, kTurnD, &gyro,turnOutput};
    PIDController speed { kSpeedP, kSpeedI, kSpeedD, &encoder,speedOutput};
    //PIDController aligner{ kTurnP, kTurnI, kTurnD, &source,pixyOutput};

    Prepare* prepare = new Prepare(&shooter,&tower);
    Shoot* shoot = new Shoot(&shooter,&tower);

    frc::Timer timer;


};

  