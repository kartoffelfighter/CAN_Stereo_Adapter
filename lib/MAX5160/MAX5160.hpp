#pragma once

#include <Arduino.h>

class MAX5160 {
	uint8_t csPin;
	uint8_t upDownPin;
	uint8_t incPin;
	uint8_t basePin;
	const uint8_t steps = 32;
	
	void increase(uint8_t steps);
	void decrease(uint8_t steps);

public:
	enum Resistance { 
		R570,	R2K,	R3K6,	R5K2,	R6K8,	R8K4,	R9K9,	R11K4,
		R13K,	R14K5,	R16K,	R17K5,	R19K,	R20K5,	R22K,	R23K4,
		R24K8,	R26K1,	R27K5,	R28K8,	R30K1,	R31K5,	R32K8,	R34K1,
		R35K3,	R36K5,	R37K7,	R38K9,	R40K1,	R41K2,	R42K5,	R43K8,
	};

	MAX5160(uint8_t csPin, uint8_t upDownPin, uint8_t incPin);
	void begin();
	void set(MAX5160::Resistance resistance);
};