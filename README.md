# vacfludis

ESP8266 / Arduino library for the Samsung HCS-12SS59T vacuum fluorescent [display driver board](https://github.com/sebastius/HCS-12SS59T).

## Pinout

| Pin   | Driver Board |
| ----- | ------------ |
| D0    | RST          |
| D1    | CS           |
| D2    | VFD-ON       |
| MOSI* | PIN          |
| SCK*  | CLK          |

MOSI and SCK pins depend on your specific board. (D7 and D5 respectively for the Wemos D1 mini).
