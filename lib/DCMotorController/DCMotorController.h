#ifndef DCMOTORCONTROLLER_H
#define DCMOTORCONTROLLER_H

#include <Arduino.h>
#include "Config.h"
#include "RadioStickProperties.h"
#include "DCMotorControllerProperties.h"

class DCMotorController {

    private:
        RadioStickProperties radioStickProperties;
        DCMotorControllerProperties motorProperties;
        uint8_t maxVoltagePercent;
        String debugName;

    public:
        DCMotorController();
        void begin(DCMotorControllerProperties motorControllerProperties, RadioStickProperties radioStickProperties, uint8_t maxVoltagePercent = 100);
        void move(int stickValue);
        void enableMotor();
        void disableMotor();
        void setDebugName(String debugName);
};

#endif
