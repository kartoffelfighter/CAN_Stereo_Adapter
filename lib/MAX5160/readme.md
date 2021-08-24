# MAX5160 digital potentiometer library
Library providing higher level of abstraction for MAX5160LEUA (50KΩ) digipot.

Other MAX5160xxx and MAX5161xxx variants are also supported, ```enum Resistance``` values should be replaced with measured ones.

## Supported resistances:
Measured using ANENG AN8009 multimeter. Values are approximate and can vary up to 25% (manufacturer spec). 

```cpp
enum Resistance { 
  R570,   R2K,    R3K6,   R5K2,   R6K8,   R8K4,   R9K9,   R11K4,
  R13K,   R14K5,  R16K,   R17K5,  R19K,   R20K5,  R22K,   R23K4,
  R24K8,  R26K1,  R27K5,  R28K8,  R30K1,  R31K5,  R32K8,  R34K1,
  R35K3,  R36K5,  R37K7,  R38K9,  R40K1,  R41K2,  R42K5,  R43K8,
};

```
Constructor:\
```csPin``` - Chip select / slave select\
```upDownPin``` - Up/down trigger pin (U/D)\
```incPin``` - Increment pin (INC)

```cpp
MAX5160(uint8_t csPin, uint8_t upDownPin, uint8_t incPin);
```

Digipot setup:
```cpp
void MAX5160::begin();
```

Setting resistance:
```cpp
void MAX5160::set(MAX5160::Resistance resistance);
```


## Optional wrapper:
Files DigiPot.* contains MAX5160 wrapper class providing functionality of switched digipot. This allows the output to be set or switched on/off with single method call.

Constructor:\
```csPin``` - Chip select / slave select\
```upDownPin``` - Up/down trigger pin (U/D)\
```incPin``` - Increment pin (INC)\
```basePin``` - NPN Transistor base pin

```cpp
DigiPot(uint8_t csPin, uint8_t upDownPin, uint8_t incPin, uint8_t basePin);
```

Additional functionality:
```cpp
void DigiPot::enable();
void DigiPot::disable(); 
```
