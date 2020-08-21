/*------------------------------------------------------------
   ___________  _______
  |___     ___||  ____  \
      |   |    | |    \  |      Property of TecDroid 3354
      |   |    | |     | |      Written by Esteban Padilla
      |   |    | |____/  |      April 23, 2019
      |___|    |________/
-------------------------------------------------------------*/
#include <frc/Preferences.h>

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//----------------Sensitivities---------------------   
           
           constexpr float s_arm = 1.0;
           constexpr float s_chasisX = 1.0;
           constexpr float s_chasisY = 1.0;
           constexpr float s_wrist = 1.0;
           constexpr float s_auto = 1.0;
           constexpr float s_autowrist = 1.0;
           constexpr float s_take = 0.5;
           constexpr float s_shoot = -1.0;

//---------------Sensor Preferences------------------

            constexpr float s_encoder = false;
            constexpr float s_limitArmUp = true;
            constexpr float s_limitArmDown = true;
            constexpr float s_limitWristUp = false;
            constexpr float s_limitWristDown = false;

//----------------PWM Ports---------------------

        //------DriveTrain-------

            constexpr int p_rightFront = 3;            
            constexpr int p_rightBack = 4;            
            constexpr int p_leftFront = 10;
            constexpr int p_leftBack = 7;

        //----------Arm-----------
            
            constexpr int p_arm = 9;
            constexpr int p_wrist = 0;
            constexpr int p_intake = 5;
            constexpr int p_hatch = 2;

        //---------Climber--------

            constexpr int p_elevator = 1;
            constexpr int p_slider = 8;

//----------------DIO Ports---------------------

        //--------Limits--------
            
            constexpr int p_limitArmUp = 5;
            constexpr int p_limitArmDown = 6;
                        
        //-------Encoders-------
            
            constexpr int p_encoderArmA = 0;
            constexpr int p_encoderArmB = 1;            
            

//----------------USB Ports---------------------

            constexpr int p_camFront = 0;
            constexpr int p_camBody = 1;
            
//--------------Joystick Ports------------------

         //-------------Buttons------------   
            constexpr int j_buttonA = 1;
            constexpr int j_buttonB = 2;
            constexpr int j_buttonX = 3;
            constexpr int j_buttonY = 4;
            constexpr int j_leftBumper = 5;
            constexpr int j_rightBumper = 6;
            constexpr int j_back = 7;            
            constexpr int j_start = 8;            
            constexpr int j_leftClick = 9;            
            constexpr int j_rightClick = 10;    

         //---------------Axes-------------   
            constexpr int j_leftX = 0;
            constexpr int j_leftY = 1;
            constexpr int j_leftTrigger = 2;
            constexpr int j_rightTrigger = 3;
            constexpr int j_rightX = 4;            
            constexpr int j_rightY = 5;       
                 
#endif