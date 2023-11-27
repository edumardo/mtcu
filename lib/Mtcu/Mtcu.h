#ifndef MTCU_H
#define MTCU_H

#include "Config.h"
#include "Radio.h"
#include "DriveDirection.h"
#include "RadioStickProperties.h"
#include "GunRecoil.h"

class Mtcu
{
    public:
        Radio radio;

    private:
        DriveDirection driveDirection;
        GunRecoil gunRecoil;
        static RadioStickProperties radioStickProperties;
        static DCMotorControllerProperties motorControllerProperties[2];

    public:
        Mtcu();
        void begin();
        void update();
        void readRadio();
        void move();
        void fireGun();
};

#endif
