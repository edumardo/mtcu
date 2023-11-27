#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

//--------------------------------------------------------------------------------------------------------------------------------------------------
// Debug
//--------------------------------------------------------------------------------------------------------------------------------------------------
const bool MTCU_DEBUG              = true;
const bool RADIO_DEBUG             = false;
const bool GUNRECOIL_DEBUG         = false;
const bool DRIVEDIRECTION_DEBUG    = true;
const bool DCMOTORCONTROLLER_DEBUG = false;

//--------------------------------------------------------------------------------------------------------------------------------------------------
// Radio pulses
//--------------------------------------------------------------------------------------------------------------------------------------------------
const int16_t RADIO_MIN_PULSE    = 1000;
const int16_t RADIO_CENTER_PULSE = 1500;
const int16_t RADIO_MAX_PULSE    = 2000;
const uint8_t RADIO_DEADBAND     =   15;

//--------------------------------------------------------------------------------------------------------------------------------------------------
// Radio pins
//--------------------------------------------------------------------------------------------------------------------------------------------------
const uint8_t PPM_INTERRUPT      =  3;

//--------------------------------------------------------------------------------------------------------------------------------------------------
// Radio channels
//--------------------------------------------------------------------------------------------------------------------------------------------------
const uint8_t NUMCHANNELS = 2;
const uint8_t TURN_CHANNEL             = 1;
const uint8_t THROTTLE_CHANNEL         = 2;
const uint8_t GUNFIRE_CHANNEL          = 5;
//const uint8_t BARREL_ELEVATION_CHANNEL = 3;
//const uint8_t TURRET_ROTATION_CHANNEL  = 4;

//--------------------------------------------------------------------------------------------------------------------------------------------------
// TB6612FNG Drive pins and prescaler
//--------------------------------------------------------------------------------------------------------------------------------------------------
const uint8_t  TB_DRIVE_APWM_PRESCALER =  1;
const uint8_t  TB_DRIVE_APWM           =  6;
const uint8_t  TB_DRIVE_AIN2           =  7;
const uint8_t  TB_DRIVE_AIN1           =  8;
const uint8_t  TB_DRIVE_BIN1           =  9;
const uint8_t  TB_DRIVE_BIN2           = 10;
const uint8_t  TB_DRIVE_BPWM           = 11;
const uint8_t  TB_DRIVE_STBY           = 12;
const uint16_t TB_DRIVE_BPWM_PRESCALER =  1;

//--------------------------------------------------------------------------------------------------------------------------------------------------
// Gun recoil
//--------------------------------------------------------------------------------------------------------------------------------------------------
const uint8_t  GUNRECOIL_SERVO_PIN      =    5;
const uint8_t  GUNRECOIL_DEGREES_IDLE   =   75;
const uint8_t  GUNRECOIL_DEGREES_RECOIL =    0;
const uint16_t GUNRECOIL_RECOIL_MS      =  100;
const uint16_t GUNRECOIL_RETURN_MS      = 1250;
const uint16_t GUNRECOIL_RELOAD_MS      = 5000;

#endif
