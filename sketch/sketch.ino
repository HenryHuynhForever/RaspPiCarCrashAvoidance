#include <Servo.h>

const int ledPin = 13;
const int inOne = 8;
const int inTwo = 7;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(inOne, OUTPUT);
	pinMode(inTwo, OUTPUT);
}

void loop() {
	digitalWrite(ledPin, HIGH);
	digitalWrite(inOne, HIGH);
	digitalWrite(inTwo, LOW);
	delay(2000);
	digitalWrite(ledPin, LOW);
	digitalWrite(inOne, LOW);
	digitalWrite(inTwo, LOW);
	delay(2000);
}
