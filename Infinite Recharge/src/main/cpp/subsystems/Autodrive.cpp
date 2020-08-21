#include "subsystems/Autodrive.h"

#include <frc/controller/PIDController.h>

#include "Constants.h"


Autodrive::Autodrive(): PIDSubsystem(frc2::PIDController(1, 0.8,0.5)){
    gyro.Reset();
    gyro.Calibrate();
    encoderRight.Reset();
    encoderRight.SetDistancePerPulse(3.141592*6./2048.);
    encoderLeft.Reset();
    encoderLeft.SetDistancePerPulse(3.141592*6./2048.);
    SetSetpoint(140);
}

void Autodrive::UseOutput(double output, double setpoint) {
 
}

bool Autodrive::AtSetpoint() { return m_controller.AtSetpoint(); }

double Autodrive::GetMeasurement() { return (encoderRight.GetDistance()+encoderRight.GetDistance())/2; }

void Autodrive::RunFeeder() { chasis.ArcadeDrive(0.6,0);}

void Autodrive::StopFeeder() { chasis.ArcadeDrive(0,0); }