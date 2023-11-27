#include "Mtcu.h"
#include "Utilities.h"

RadioStickProperties Mtcu::radioStickProperties;
DCMotorControllerProperties Mtcu::motorControllerProperties[2];

Mtcu::Mtcu() {

    radioStickProperties = 
    {
        RADIO_MIN_PULSE,
        RADIO_CENTER_PULSE,
        RADIO_MAX_PULSE
    };

    // Left
    motorControllerProperties[0] =
    {
        TB_DRIVE_APWM_PRESCALER,
        TB_DRIVE_APWM,
        TB_DRIVE_AIN1,
        TB_DRIVE_AIN2,
        TB_DRIVE_STBY
    };

    // Right
    motorControllerProperties[1] =
    {
        TB_DRIVE_BPWM_PRESCALER,
        TB_DRIVE_BPWM,
        TB_DRIVE_BIN1,
        TB_DRIVE_BIN2,
        TB_DRIVE_STBY
    };
}

void Mtcu::begin() {

    radio.begin();
    gunRecoil.begin();
    //driveDirection.begin(motorControllerProperties[0], motorControllerProperties[1], radioStickProperties);
}

void Mtcu::update() {

    gunRecoil.update();
}

void Mtcu::readRadio() {

    radio.readChannels();
}

void Mtcu::move() {

    if (MTCU_DEBUG) {
        printLabel("Mtcu::move");
        printDEC("throttle", radio.stickChannels.throttle.pulse);
        printDEC("turn", radio.stickChannels.turn.pulse, true);

    }

    driveDirection.move(radio.stickChannels.throttle.pulse, radio.stickChannels.turn.pulse);
}

void Mtcu::fireGun() {
    gunRecoil.fire();
}
