#include "GunRecoil.h"
#include "Config.h"

Timer<> * GunRecoil::recoilTimer;
AsyncServo GunRecoil::recoilServo;
bool GunRecoil::readyToFire;

GunRecoil::GunRecoil() {

    if (GUNRECOIL_DEBUG)
    {
        Serial.println("GunRecoil::GunRecoil");
    }
    readyToFire = true;
    recoilTimer = new Timer<>();
}

void GunRecoil::begin() {

    if (GUNRECOIL_DEBUG)
    {
        Serial.println("GunRecoil::begin");
    }
    recoilServo.Attach(GUNRECOIL_SERVO_PIN);
    recoilServo.write(GUNRECOIL_DEGREES_IDLE);
}

void GunRecoil::update() {

    //if (GUNRECOIL_DEBUG)
    //{
    //    Serial.println("GunRecoil::update");
    //}
    recoilTimer->tick();
    recoilServo.Update();
}

void GunRecoil::fire() {

    if (GUNRECOIL_DEBUG)
    {
        Serial.println("GunRecoil::fire");
    }
    readyToFire = false;
    recoilServo.MoveDegrees(GUNRECOIL_DEGREES_RECOIL, GUNRECOIL_RECOIL_MS, returnBarrel);
}

void GunRecoil::returnBarrel() {
        
    if (GUNRECOIL_DEBUG)
    {
        Serial.println("GunRecoil::returnBarrel");
    }

    recoilServo.MoveDegrees(GUNRECOIL_DEGREES_IDLE, GUNRECOIL_RETURN_MS);
    recoilTimer->in(GUNRECOIL_RELOAD_MS, gunReadyTofire);
}

bool GunRecoil::gunReadyTofire(void *) {

    if (GUNRECOIL_DEBUG)
    {
        Serial.println("GunRecoil::gunReadyTofire");
    }
    readyToFire = true;
    return true;
}
