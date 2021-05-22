#include "config.h"
#include <Arduino.h>
#ifdef ENABLE_DISPLAY
#include <TFT_eSPI.h>
#endif
#include "SiRFGPS.h"

#ifdef USES_SIRF
SiRFGPS *gps;
#else
GPS *gps;
#endif
#ifdef ENABLE_DISPLAY
TFT_eSPI display;
#endif

void setup()
{
  Serial.begin(115200);
#ifdef ENABLE_DISPLAY
  display.begin();
  display.setRotation(1);
  display.fillScreen(0);
  display.setCursor(0, 0, 2);
  display.setTextColor(TFT_WHITE, TFT_BLACK);
  display.setTextSize(1);
#endif
#ifdef USES_SIRF
  gps = new SiRFGPS(GPS_SERIAL, GPS_TX, GPS_RX, GPS_ENABLE);
  gps->begin();
#else
  gps = new GPS(GPS_SERIAL, GPS_TX, GPS_RX);
  gps->begin(GPS_BAUD);
#endif
}

void loop()
{
  Serial.printf("%s\n", gps->get_fix().toString().c_str());
#ifdef ENABLE_DISPLAY
  display.fillScreen(0);
  display.setCursor(0, 0, 2);
  Serial.printf(gps->get_fix().toString().c_str());
  display.println(gps->get_fix().toString().c_str());
  display.fillScreen(0);
  display.setCursor(0, 0, 2);
  display.printf("Tracking %d of %d visible\n", gps->get_tracking_satellites(), gps->get_visibile_satellites());
  display.printf("Status: %s\n", gps->get_status() == 'A' ? "LOCK!" : "SEARCHING...");
  display.printf("Time: %s\n", gps->get_fix().timestamp.toString().c_str());
  display.printf("Lat: %f\n", gps->get_fix().latitude);
  display.printf("Lng: %f\n", gps->get_fix().longitude);
  display.printf("Speed: %f\n", gps->get_fix().speed);
  display.printf("Almanac: %.1f%% complete\n", gps->get_fix().almanac.percentComplete());
#endif
  delay(5000);
}