#pragma once

#include "GPS.h"

class SiRFGPS : public GPS
{
private:
  gpio_num_t m_enable;

public:
  SiRFGPS(HardwareSerial &serial, gpio_num_t rx, gpio_num_t tx, gpio_num_t enable) : GPS(serial, rx, tx), m_enable(enable) {}
  void begin();
};