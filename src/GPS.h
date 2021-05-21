#pragma once

#include "NemaTode/include/nmeaparse/nmea.h"

class HardwareSerial;

class GPS
{
protected:
  HardwareSerial &m_serial;
  gpio_num_t m_tx;
  gpio_num_t m_rx;

  nmea::NMEAParser *m_parser;
  nmea::GPSService *m_gps_service;

public:
  GPS(HardwareSerial &serial, gpio_num_t rx, gpio_num_t tx);
  nmea::GPSFix &get_fix() { return m_gps_service->fix; }
  int get_tracking_satellites() { return m_gps_service->fix.trackingSatellites; }
  int get_visibile_satellites() { return m_gps_service->fix.visibleSatellites; }
  char get_status() { return m_gps_service->fix.status; }
  void begin(unsigned long baud_rate);
  void end();
  friend void nmea_parser(void *param);
};