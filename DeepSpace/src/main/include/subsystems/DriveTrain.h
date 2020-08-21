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
#include <frc/Drive/DifferentialDrive.h>
#include <frc/VictorSP.h>
#include <frc/AnalogInput.h>
#include <frc/SpeedControllerGroup.h>
#include "RobotMap.h"


namespace frc {
class Joystick;
}  

class DriveTrain : public frc::Subsystem {
 public:
  DriveTrain();
  void InitDefaultCommand() override;

  //Function to drive the chasis
  void Drive(double leftAxis, double rightAxis, bool active);
   
 private:

    //Left motors
  	frc::VictorSP m_leftBack{p_leftBack};
    frc::VictorSP m_leftFront{p_leftFront};
    frc::SpeedControllerGroup m_left{m_leftBack,m_leftFront};

    //Right motors
   	frc::VictorSP m_rightBack{p_rightBack};
    frc::VictorSP m_rightFront{p_rightFront};
    frc::SpeedControllerGroup m_right{m_rightBack,m_rightFront};       

    //Drivetrain with Differential Drive
	frc::DifferentialDrive m_robotDrive{m_left,m_right};
};


