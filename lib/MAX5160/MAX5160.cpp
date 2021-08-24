#include "MAX5160.hpp"

MAX5160::MAX5160(uint8_t csPin, uint8_t upDownPin, uint8_t incPin) {
	this->csPin = csPin;
	this->upDownPin = upDownPin;
	this->incPin = incPin;
}

void MAX5160::begin() {
	pinMode(this->csPin, OUTPUT);
	pinMode(this->upDownPin, OUTPUT);
	pinMode(this->incPin, OUTPUT);

	digitalWrite(this->csPin, HIGH);
	digitalWrite(this->upDownPin, HIGH);
	digitalWrite(this->incPin, HIGH);
}

void MAX5160::increase(uint8_t steps) {
	digitalWrite(this->csPin, LOW); //update value
	delayMicroseconds(1);
	digitalWrite(this->upDownPin, HIGH); //mode: increase
	delayMicroseconds(1);

	for(uint8_t i = 0; i < steps; i++) {
		digitalWrite(this->incPin, HIGH);
		delayMicroseconds(1);
		digitalWrite(this->incPin, LOW); // High->Low transition => change
		delayMicroseconds(1);
	}

	digitalWrite(this->csPin, HIGH); //disable update
	delayMicroseconds(1);
}

void MAX5160::decrease(uint8_t steps) {
	digitalWrite(this->csPin, LOW); //update value
	delayMicroseconds(1);
	digitalWrite(this->upDownPin, LOW); //mode: increase
	delayMicroseconds(1);

	for(uint8_t i = 0; i < steps; i++) {
		digitalWrite(this->incPin, HIGH);
		delayMicroseconds(1);
		digitalWrite(this->incPin, LOW); // High->Low transition => change
		delayMicroseconds(1);
	}
 
	digitalWrite(this->csPin, HIGH); //disable update
	delayMicroseconds(1);
}

void MAX5160::set(MAX5160::Resistance resistance) {
	this->decrease(this->steps); //reset to lowest value possible
	this->increase(resistance);
}