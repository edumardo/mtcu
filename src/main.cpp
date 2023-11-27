#include <Arduino.h>
#include <Mtcu.h>

Mtcu mtcu;
int fired = 0;

void setup() {

    Serial.begin(115200);
    mtcu.begin();
    Serial.println("MTCU started!");

}

void loop() {

    mtcu.update();
    mtcu.readRadio();

    if(mtcu.radio.stickChannels.turn.updated || mtcu.radio.stickChannels.throttle.updated) {
        mtcu.move();
    }

    //if (fired == 0) {
    //    mtcu.fireGun();
    //    fired = fired + 1;
    //}

    delay(200);     // @TODO adjust
    Serial.println();
}