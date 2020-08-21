/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "OI.h"
#include "subsystems/Cam.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/Arm.h"
#include "subsystems/Climber.h"
#include "subsystems/Wrist.h"
#include "subsystems/Intake.h"
#include "subsystems/Hatch.h"

class Robot : public frc::TimedRobot {
 public:
  static Hatch hatch;
  static Cam cam;
  static DriveTrain drivetrain;
  static Arm arm;
  static Climber climber;
  static Intake intake;
  static Wrist wrist;
  static OI oi;

 private:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

};
