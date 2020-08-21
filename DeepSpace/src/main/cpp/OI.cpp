/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include "OI.h"
#include "commands/Shoot.h"
#include "commands/LevelArm.h"
#include "commands/MoveHatch.h"

#include "Robot.h"
OI::OI() {
   b_shoot.WhenPressed(new Shoot());

   b_top.WhenPressed(new LevelArm(140.0,1));
   b_mid.WhenPressed(new LevelArm(80.0,1));
   b_bot.WhenPressed(new LevelArm(20.0,1));


}


frc::Joystick& OI::GetJoystick(int control) {
    if (control){
        return s_arm;
    }
    else{
	    return s_chasis;
    }
}
