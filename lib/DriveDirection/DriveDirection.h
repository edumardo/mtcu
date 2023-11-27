#ifndef DRIVEDIRECTION_H
#define DRIVEDIRECTION_H

#include "Config.h"
#include "DCMotorController.h"
#include <DifferentialSteering.h>
#include "RadioStickProperties.h"
#include "DCMotorControllerProperties.h"

class DriveDirection {

    private:
        DCMotorController leftMotor;
        DCMotorController rightMotor;
        DifferentialSteering diffSteer;
        byte diffSteerComputeRange;
        static const byte pivotYLimit = 32;
        RadioStickProperties radioStickProperties;
        byte analogMovePercent;

    public:
        DriveDirection();
        void begin(DCMotorControllerProperties leftMotorConfig, DCMotorControllerProperties rightMotorConfig, RadioStickProperties radioStickProperties);
        void move(uint16_t stickValueX, uint16_t stickValueY);
        void setMaxVoltagePercentAnalogMove(byte percent);
        void disableMotors();
};

#endif
