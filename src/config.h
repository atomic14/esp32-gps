#include "Arduino.h"

// Are you using a GPS that uses the SiRF protocol and needs switching to NMEA?
#define USES_SIRF 1

// Does your SiRF GPS need to be enabled? Set to -1 if not required
#define GPS_ENABLE GPIO_NUM_27

// GPS baud rate - only required for NMEA GPS boards
#define GPS_BAUD 9600

// Which pins have you got your TX and RX lines connected to?
#define GPS_RX GPIO_NUM_13
#define GPS_TX GPIO_NUM_12

// which hardware serial do you want to use? Serial1, Serial2, Serial3
#define GPS_SERIAL Serial1

// enable the TTGO display
#define ENABLE_DISPLAY