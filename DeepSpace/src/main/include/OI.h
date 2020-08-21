/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/

#pragma once

#include <frc/Buttons/JoystickButton.h>
#include <frc/Joystick.h>
#include <frc/DigitalInput.h>
#include "RobotMap.h"
class OI {
public:
	OI();
	
	frc::Joystick& GetJoystick(int control);

private:

    //Setup one joystic for each part
	frc::Joystick s_chasis{0};
    frc::Joystick s_arm{1};
    
    //Buttons for the three different levels of the Arm
    frc::JoystickButton b_top{&s_arm,j_buttonY};
    frc::JoystickButton b_bot{&s_arm,j_buttonB};
    frc::JoystickButton b_mid{&s_arm,j_buttonA};

    //Button to activate the Shoot function
	frc::JoystickButton b_shoot{&s_chasis,j_rightBumper};



};