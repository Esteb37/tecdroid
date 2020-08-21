
#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/util/color.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "frc/VictorSP.h"
#include <frc/DigitalInput.h>
#include "Constants.h"
#include "frc/Timer.h"

using namespace frc;
using namespace rev;
using namespace std;

class Panel : public frc2::SubsystemBase {
 public:
  Panel();

  void Periodic() override;

  void Reset();
  void SetMotor(float speed);
  bool GetLimit();
  string GetColor();
  
  
 private:
  static constexpr auto s_color = frc::I2C::Port::kOnboard;
  ColorSensorV3 m_colorSensor{s_color};
  ColorMatch m_colorMatcher;
  Color currentColor;
  Color tempColor;
  VictorSP motor{mPanel};
  DigitalInput limit{sPanelSwitch};
  double confidence = 0.0;
 public:
  frc::Timer timer;
};
