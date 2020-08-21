/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "subsystems/Intake.h"

#include "RobotMap.h"
#include "commands/Take.h"

Intake::Intake() : frc::Subsystem("Intake") {}

void Intake::InitDefaultCommand() {
  SetDefaultCommand(new Take());
}

void Intake::Set(double value){
  m_intake.Set(value);
}
void Intake::Stop(){
	m_intake.Set(0.0);
}

void Intake::StartTime(){
  timer.Start();
}
void Intake::StopTime(){
  timer.Stop();
  timer.Reset();
}

double Intake::GetTime(){
  return timer.Get();
}