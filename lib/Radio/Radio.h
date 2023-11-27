#ifndef RADIO_H
#define RADIO_H

#include "Config.h"
#include <PPMReader.h>

enum SwitchPositions : uint8_t {
    NullPosition = 0,
    Pos1,
    Pos2,
    Pos3
};

class Channel {
    public:
        bool                   present;
        bool                   updated;
        uint16_t               pulse;
};

class ChannelProperties {
    public:
        uint8_t  channelNumber;
        uint16_t minPulse;
        uint16_t maxPulse;
        uint16_t centerPulse;
        bool     reversed;
};

class StickChannelProperties : public ChannelProperties {
    public:
        uint8_t  deadband;
};

class AuxChannelProperties : public ChannelProperties {
    public:
        bool     isDigital;         // digital channel (switch) or analog knob
        uint8_t  numPositions;      // If digital, how many positions does this switch have
};

class StickChannel : public Channel {
    public:
        StickChannelProperties properties;
        bool pulseInDeadband() {
            if ((pulse > properties.centerPulse + properties.deadband) && (pulse < properties.centerPulse - properties.deadband)) {
                return true;
            } else {
                return false;
            }
        }
};

class AuxChannel : public Channel {
    public:
        AuxChannelProperties properties;
        SwitchPositions      switchPosition;        // Current switch position
        bool pulseInDeadband() {return true;}
};

class SticksChannels {
    public:
        StickChannel throttle;
        StickChannel turn;
        StickChannel elevation;
        StickChannel azimut;
};

class CommonChannel {
    public:
        uint8_t  * channelNumber;
        bool     * present;
        bool     * updated;
        uint16_t * pulse;
};

class Radio {

    public:
        SticksChannels stickChannels;

    private:

        static const uint16_t pulseInDelay = 20000;
        //const uint8_t radioPins[NUMCHANNELS] = { RADIO_TURN_PIN, RADIO_THROTTLE_PIN};
        AuxChannel fireGun;
        CommonChannel allChannels[NUMCHANNELS];
        PPMReader * ppmReader;

        uint16_t readChannel(int channel);
        void initStickChannels();
        void initAuxChannels();
        void initAllChannels();
        void printChannels();

    public:
        Radio();
        void begin();
        void readChannels();
};

#endif
