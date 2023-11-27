#include "Radio.h"

Radio::Radio() {

}

void Radio::begin() {

    ppmReader = new PPMReader(PPM_INTERRUPT, 8);
    initStickChannels();
    initAuxChannels();
    initAllChannels();
}

uint16_t Radio::readChannel(int channel) {
    
    //return pulseIn(radioPins[channel - 1], HIGH, pulseInDelay);
    return 0;

}

void Radio::readChannels() {

    for (int i = 0; i < NUMCHANNELS; i++) {

        //uint16_t pulse = readChannel(*(allChannels[i].channelNumber));
        uint16_t pulse = ppmReader->latestValidChannelValue(*(allChannels[i].channelNumber), 0);
        if (*allChannels[i].pulse == pulse) {
            *allChannels[i].updated = false;
        } else {
            *allChannels[i].updated = true;
            *allChannels[i].pulse = pulse;
        }

    }
    if (RADIO_DEBUG) {
        printChannels();
    }

}

void Radio::initStickChannels() {

    stickChannels.throttle.properties.channelNumber = THROTTLE_CHANNEL;
    stickChannels.throttle.properties.minPulse    = RADIO_MIN_PULSE;
    stickChannels.throttle.properties.maxPulse    = RADIO_MAX_PULSE;
    stickChannels.throttle.properties.centerPulse = RADIO_CENTER_PULSE;
    stickChannels.throttle.properties.deadband    = RADIO_DEADBAND;
    stickChannels.throttle.properties.reversed    = false;
    stickChannels.throttle.present                = true;
    stickChannels.throttle.updated                = false;
    stickChannels.throttle.pulse                  = RADIO_CENTER_PULSE;

    stickChannels.turn.properties.channelNumber = TURN_CHANNEL;
    stickChannels.turn.properties.minPulse      = RADIO_MIN_PULSE;
    stickChannels.turn.properties.maxPulse      = RADIO_MAX_PULSE;
    stickChannels.turn.properties.centerPulse   = RADIO_CENTER_PULSE;
    stickChannels.turn.properties.deadband      = RADIO_DEADBAND;
    stickChannels.turn.properties.reversed      = false;
    stickChannels.turn.present                  = true;
    stickChannels.turn.updated                  = false;
    stickChannels.turn.pulse                    = RADIO_CENTER_PULSE;
}

void Radio::initAuxChannels() {

    //fireGun.properties.channelNumber = GUNFIRE_CHANNEL;
//
    //fireGun.present = true;
    //fireGun.updated = false;
    //fireGun.pulse = RADIO_MIN_PULSE;
    //fireGun.switchPosition = NullPosition;
    //fireGun.properties.minPulse = RADIO_MIN_PULSE;
    //fireGun.properties.maxPulse = RADIO_MAX_PULSE;
    //fireGun.properties.centerPulse = RADIO_MIN_PULSE;
    //fireGun.properties.reversed = false;
    //fireGun.properties.isDigital = true;
    //fireGun.properties.numPositions = 2;
}

void Radio::initAllChannels() {

    // Turn
    allChannels[0].channelNumber = &stickChannels.turn.properties.channelNumber;
    allChannels[0].present       = &stickChannels.turn.present;
    allChannels[0].updated       = &stickChannels.turn.updated;
    allChannels[0].pulse         = &stickChannels.turn.pulse;

    // Throttle
    allChannels[1].channelNumber = &stickChannels.throttle.properties.channelNumber;
    allChannels[1].present       = &stickChannels.throttle.present;
    allChannels[1].updated       = &stickChannels.throttle.updated;
    allChannels[1].pulse         = &stickChannels.throttle.pulse;

    // Gun fire
    //allChannels[2].channelNumber = &fireGun.properties.channelNumber;
    //allChannels[2].present       = &fireGun.present;
    //allChannels[2].updated       = &fireGun.updated;
    //allChannels[2].pulse         = &fireGun.pulse;
}

void Radio::printChannels() {

    Serial.print("Radio::readChannels - ");
    for (int i = 0; i < NUMCHANNELS; i++) {
        
        Serial.print(*allChannels[i].pulse);
        Serial.print(" ");
    }
    Serial.println();
}
