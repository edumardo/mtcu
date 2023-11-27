#ifndef GUNRECOIL_H
#define GUNRECOILH

#include <arduino-timer.h>
#include <AsyncServoLib.h>

class GunRecoil {
    
    private:
        static bool readyToFire;
        static Timer<> * recoilTimer;
        static AsyncServo recoilServo;
        static void returnBarrel();
        static bool gunReadyTofire(void *);

    public:
        GunRecoil();
        void begin();
        void update();
        void fire();
};

#endif
