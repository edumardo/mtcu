#include "DCMotorController.h"
#include "Utilities.h"

DCMotorController::DCMotorController() {

    /* Default name for debug output */
    debugName = "DC Motor";
}

void DCMotorController::begin(DCMotorControllerProperties motorControllerProperties, RadioStickProperties radioStickProperties, uint8_t maxVoltagePercent = 100) {

    motorProperties = motorControllerProperties;
    radioStickProperties = radioStickProperties;
    maxVoltagePercent = (maxVoltagePercent <= 0 || maxVoltagePercent > 100) ? 100 : maxVoltagePercent;

    pinMode(motorProperties.pwmPin, OUTPUT);
    pinMode(motorProperties.in1Pin, OUTPUT);
    pinMode(motorProperties.in2Pin, OUTPUT);
    pinMode(motorProperties.standbyPin, OUTPUT);
    disableMotor();
    setPWMPrescaler(motorProperties.pwmPin, motorProperties.pwmPrescaler);
}

void DCMotorController::enableMotor() {

    digitalWrite(motorProperties.standbyPin, HIGH);
}

void DCMotorController::disableMotor() {

    digitalWrite(motorProperties.pwmPin, 0);
    digitalWrite(motorProperties.in1Pin, LOW);
    digitalWrite(motorProperties.in2Pin, LOW);
    digitalWrite(motorProperties.standbyPin, LOW);
}

void DCMotorController::move(int stickValue) {

    if (stickValue == radioStickProperties.centerPulse) return;

    digitalWrite(motorProperties.in1Pin, (stickValue < radioStickProperties.centerPulse) ? LOW : HIGH);
    digitalWrite(motorProperties.in2Pin, (stickValue < radioStickProperties.centerPulse) ? HIGH : LOW);
    int pwmSpeed = abs(map(stickValue, radioStickProperties.minPulse , radioStickProperties.maxPulse , -255, 255));
    int pwmSpeedPercent = pwmSpeed * maxVoltagePercent / 100;

    enableMotor();
    analogWrite(motorProperties.pwmPin, pwmSpeedPercent);

    if (DCMOTORCONTROLLER_DEBUG) {

        printDEC("stickValue", stickValue);
        if (stickValue < radioStickProperties.centerPulse)
            printLabel(debugName + " left");
        else
            printLabel(debugName + " right");
        printDEC("pwmSpeedPercent", pwmSpeedPercent);
        Serial.println();
    }
}

void DCMotorController::setDebugName(String name) {

    debugName = name;
}

