Very simple example of using a GPS with an ESP32.

Make sure you clone the repository recursively to include all the submodules:

```
git clone --recursive git@github.com:atomic14/esp32-gps.git
```

There's an explanatory video [here](https://youtu.be/LmByilbtBcM)

[![Demo Video](https://img.youtube.com/vi/LmByilbtBcM/0.jpg)](https://www.youtube.com/watch?v=LmByilbtBcM)

Wiring up should be pretty straightforward. The ESP32 has three serial peripherals and you can easily change the RX and TX pins.

The code should support SiRF and NMEA devices.

There are a few settings that you can change:

```
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
```
