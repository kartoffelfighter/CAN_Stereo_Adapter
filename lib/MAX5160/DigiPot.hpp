#pragma once

#include <Arduino.h>
#include "MAX5160.hpp"

class DigiPot {
	MAX5160* potentiometer;
	uint8_t basePin;

public:
	DigiPot(uint8_t csPin, uint8_t upDownPin, uint8_t incPin, uint8_t basePin);
	void begin();

	void enable();
	void disable(); 

	void set(MAX5160::Resistance resistance);
};
