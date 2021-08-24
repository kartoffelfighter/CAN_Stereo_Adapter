#include "DigiPot.hpp"

DigiPot::DigiPot(uint8_t csPin, uint8_t upDownPin, uint8_t incPin, uint8_t basePin) {
	this->potentiometer = new MAX5160(csPin, upDownPin, incPin);
	this->basePin = basePin;
}

void DigiPot::begin() {
	pinMode(this->basePin, OUTPUT);
	this->disable();

	this->potentiometer->begin();
}

void DigiPot::enable() {
	digitalWrite(this->basePin, HIGH);
}

void DigiPot::disable() {
	digitalWrite(this->basePin, LOW);
}

void DigiPot::set(MAX5160::Resistance resistance) {
	this->disable();
	this->potentiometer->set(resistance);
	this->enable();
}