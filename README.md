## Arduino Uno / Nano Timers, PWMs and Servos

|Registrer | Pin        | Timer  | Frequency | PWM Freq | Prescaler (* default)         | Effect               |
|-------   |----------- |--------|-----------|----------|-------------------------------|----------------------|
|          | 5, 6       | Timer0 | 62500 Hz  | 977 Hz   | 1, 8, 64*, 256, 1024          | delay() and millis() |
|          | 9, 10      | Timer1 | 31250 Hz  | 490 Hz   | 1, 8, 64*, 256, 1024          | [Servo library](https://www.arduino.cc/reference/en/libraries/servo/) |
|          | 3, 11      | Timer2 | 31250 Hz  | 490 Hz   | 1, 8, 32, 64*, 128, 256, 1024 |                      |
