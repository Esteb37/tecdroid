/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/RotatePanel.h"
#include "commands/AlignPanel.h"
#include "commands/Prepare.h"
#include "frc2/command/button/JoystickButton.h"
#include "frc/smartdashboard/SmartDashboard.h"

RobotContainer::RobotContainer(){
  
  ConfigureButtonBindings();
 
}

void RobotContainer::ConfigureButtonBindings() {
  
  bRotatePanel.WhenPressed(new RotatePanel(&panel));
  bAlignPanel.WhenPressed(new AlignPanel(&panel));
  bPrepare.WhenPressed(new Prepare(&shooter,&tower));
}

void RobotContainer::Drive(){
  chasis.Drive();
  tower.Move();
  shooter.Move();
}

Auto* RobotContainer::GetAuto(){
  return auton;
}

void RobotContainer::Reset(){
 shooter.Reset();
 tower.Reset();
}

void RobotContainer::Lower(){
  tower.Lower();
}

void RobotContainer::Test(){
 
}
