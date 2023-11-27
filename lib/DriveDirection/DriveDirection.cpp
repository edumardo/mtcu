#include "DriveDirection.h"
#include "Utilities.h"


DriveDirection::DriveDirection() {

    analogMovePercent = 100;
    diffSteer.begin(pivotYLimit);
    diffSteerComputeRange = diffSteer.getComputeRange();
}


void DriveDirection::begin(DCMotorControllerProperties leftMotorConfig, DCMotorControllerProperties rightMotorConfig, RadioStickProperties radioStickProperties){

    radioStickProperties = radioStickProperties;

    RadioStickProperties leftMotorStickProperties = {-diffSteerComputeRange, 0, diffSteerComputeRange};
    leftMotor.begin(leftMotorConfig, leftMotorStickProperties);
    leftMotor.setDebugName("left motor");
    
    RadioStickProperties rightMotorStickProperties = {-diffSteerComputeRange, 0, diffSteerComputeRange};
    rightMotor.begin(rightMotorConfig, rightMotorStickProperties);
    rightMotor.setDebugName("right motor");
}

void DriveDirection::move(uint16_t stickValueX, uint16_t stickValueY) {



    long mappedXToSteerComputeRange = map(
        stickValueX, 
        radioStickProperties.minPulse, 
        radioStickProperties.maxPulse, 
        -diffSteerComputeRange, 
        diffSteerComputeRange);

    long mappedYToSteerComputeRange = map(
        stickValueY, 
        radioStickProperties.minPulse, 
        radioStickProperties.maxPulse, 
        -diffSteerComputeRange, 
        diffSteerComputeRange);

    if (DRIVEDIRECTION_DEBUG) {
        printLabel("DriveDirection::move");
        printDEC("stickValueX", stickValueX);
        printDEC("stickValueY", stickValueY);
        printDEC("radioStickProperties.minPulse", radioStickProperties.minPulse);
        printDEC("radioStickProperties.maxPulse", radioStickProperties.maxPulse);

        //printDEC("mappedXToSteerComputeRange", mappedXToSteerComputeRange);
        //printDEC("mappedYToSteerComputeRange", mappedYToSteerComputeRange, true);
    }

    diffSteer.computeMotors(mappedXToSteerComputeRange, mappedYToSteerComputeRange);

    leftMotor.move(diffSteer.computedLeftMotor());
    rightMotor.move(diffSteer.computedRightMotor());

    if (DRIVEDIRECTION_DEBUG) {
    }
}

void DriveDirection::setMaxVoltagePercentAnalogMove(byte analogMovePercent) {

    analogMovePercent = analogMovePercent;
}

void DriveDirection::disableMotors() {

    leftMotor.disableMotor();
    rightMotor.disableMotor();
}
