#include "Arduino.h"
#include "SiRFGPS.h"

void SiRFGPS::begin()
{
  // connect initially to the binary protocol
  m_serial.begin(115200, SERIAL_8N1, m_rx, m_tx);
  // toggle the enable pin
  if (m_enable != -1)
  {
    pinMode(m_enable, OUTPUT);
    digitalWrite(m_enable, 0);
    delay(100);
    digitalWrite(m_enable, 1);
    delay(100);
  }
  // switch to NMEA mode at 4800 baud
  uint8_t cmd[] = {0xA0, 0xA2, 0x00, 0x18, 0x81, 0x02, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x05, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x12, 0xC0, 0x01, 0x65, 0xB0, 0xB3};
  m_serial.write(cmd, 32);
  m_serial.flush(true);
  m_serial.end();
  Serial.println("Switched to NMEA mode 4800 baud");

  GPS::begin(4800);
}
