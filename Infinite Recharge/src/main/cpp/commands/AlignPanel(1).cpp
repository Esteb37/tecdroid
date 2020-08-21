/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AlignPanel.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/DriverStation.h>



AlignPanel::AlignPanel(Panel* subsystem): panel{subsystem} {
    AddRequirements({subsystem});

}

void AlignPanel::Initialize(){

    char current = panel->GetColor();
    currentColor;
    switch(current){
        case 'R':
            currentColor = red;
            break;
        case 'B':
            currentColor = blue;
            break;
        case 'Y':
            currentColor = yellow;
            break;
        case 'G':
            currentColor = green;
            break;
    }
    goalColor = DriverStation::GetInstance().GetGameSpecificMessage().at(0);
    
    
}

void AlignPanel::Execute(){
    
}

bool AlignPanel::IsFinished(){
    return false;
}

void AlignPanel::End(bool interrupted){
   
}