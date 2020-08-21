
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Panel.h"

class PanelColor{
   public:
      char op,der,iz;
   PanelColor(char op_,char der_,char iz_){
      op = op_;
      der = der_;
      iz = iz_;
   }
   PanelColor();
};

class AlignPanel
    : public frc2::CommandHelper<frc2::CommandBase, AlignPanel> {
 public:
  
  explicit AlignPanel(Panel* subsystem);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
  
 private:
   Panel* panel;
   char goalColor;
   PanelColor currentColor;
   PanelColor red{'B','G','Y'};
   PanelColor blue{'R','Y','G'};
   PanelColor yellow{'G','R','B'};
   PanelColor green{'Y','B','R'};
};


