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
#include <frc/WPILib.h>
#include <cscore_oo.h>
class Cam : public frc::Subsystem {
 public:
  Cam();
  void InitDefaultCommand() override;
  cs::UsbCamera c_body;
  cs::UsbCamera c_arm;
  cs::VideoSink server;
 private:
    
};
