#include "Utilities.h"

void setPWMPrescaler(uint8_t pin, uint16_t prescale) {

    byte mode;

    if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
        switch(prescale) {
            case    1: mode = 0b001; break;
            case    8: mode = 0b010; break;
            case   64: mode = 0b011; break;
            case  256: mode = 0b100; break;
            case 1024: mode = 0b101; break;
            default: return;
    }

    } else if(pin == 3 || pin == 11) {
        switch(prescale) {
            case    1: mode = 0b001; break;
            case    8: mode = 0b010; break;
            case   32: mode = 0b011; break;
            case   64: mode = 0b100; break;
            case  128: mode = 0b101; break;
            case  256: mode = 0b110; break;
            case 1024: mode = 0b111; break;
            default: return;
        }
    }

    if(pin == 5 || pin == 6) {
        TCCR0B = TCCR0B & 0b11111000 | mode;
    } else if (pin == 9 || pin == 10) {
        TCCR1B = TCCR1B & 0b11111000 | mode;
    } else if (pin == 3 || pin == 11) {
        TCCR2B = TCCR2B & 0b11111000 | mode;
    }
}

void printDEC(String label, int value, bool newLine = false) {

    Serial.print("[");
    Serial.print(label);
    Serial.print(": ");
    Serial.print(value, DEC);
    Serial.print("]");
    if (newLine)
        Serial.println();
}

void printLabel(String label) {

    Serial.print("[");
    Serial.print(label);
    Serial.print("]");
}
