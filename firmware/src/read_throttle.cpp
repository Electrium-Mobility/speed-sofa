// Process: Connect throttle to ESP32's power, ground, and an analog pin (choose which pin to use)

int throttleValue;
int throttlePin;
float voltageOutput;
int voltageInput;

void setup() {
    // Establish a serial connection
    // Serial.begin(????)
    // voltageInput = 3.3
}


void loop() {
    throttleValue = analogRead(throttlePin);
    voltageOutput = (throttleValue / 4095.0) * voltageInput;
    delay(100);
}