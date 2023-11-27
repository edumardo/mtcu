#ifndef UTILITIES_H
#define UTILITIES_H

#include <Arduino.h>

void setPWMPrescaler(uint8_t pin, uint16_t prescale);
void printDEC(String label, int value, bool newLine = false);
void printLabel(String label);

#endif
