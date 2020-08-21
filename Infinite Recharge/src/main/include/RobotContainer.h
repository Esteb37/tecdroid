/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>


#include "subsystems/Panel.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Auto.h"
#include "subsystems/Shooter.h"
#include "subsystems/Tower.h"
#include "subsystems/Elevator.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "frc/XboxController.h"
#include "frc2/command/button/Button.h"
#include "frc/Timer.h"

using namespace frc2;
using namespace frc;



class RobotContainer {
 public:
  RobotContainer();
  
  Command* GetAutonomousCommand();

  void Drive();
  Auto* GetAuto();
  void Reset();
  void Lower();
  void Disable();
  void Test();
  frc::Timer timer;

private:
  // The robot's subsystems and commands are defined here...
  Panel panel;
  XboxController control{0};
  Drivetrain chasis;
  Shooter shooter;
  Elevator elevator;
  Tower tower;
  Auto *auton = new Auto(chasis,tower,shooter);  
  

  Button bRotatePanel{[&] { return control.GetRawButton(cButtonA); }};
  Button bAlignPanel{[&] { return control.GetRawButton(cButtonB); }};
  Button bPrepare{[&] { return control.GetRawButton(cRightBumper); }};

  void ConfigureButtonBindings();
};



