/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"
#include "subsystems/Tower.h"

//@ts-ignore
class Autoshoot: public frc2::CommandHelper<frc2::CommandBase, Autoshoot> {
 public:
  
  explicit Autoshoot(Shooter* Shooter_, Tower* tower_);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
  
 private:
  Shooter* shooter;
  Tower* tower;

};
