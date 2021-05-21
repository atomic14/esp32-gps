#include "Arduino.h"
#include "GPS.h"

void nmea_parser(void *param)
{
  GPS *gps = reinterpret_cast<GPS *>(param);
  // work space
  uint8_t buffer[100];
  while (true)
  {
    int bytes_read = gps->m_serial.readBytes(buffer, 99);
    buffer[bytes_read] = '\0';
    if (bytes_read > 0)
    {
      Serial.printf(reinterpret_cast<char *>(buffer));
      gps->m_parser->readBuffer(buffer, bytes_read);
    }
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

GPS::GPS(HardwareSerial &serial, gpio_num_t tx, gpio_num_t rx) : m_serial(serial), m_tx(tx), m_rx(rx)
{
  m_parser = new nmea::NMEAParser();
  m_gps_service = new nmea::GPSService(*m_parser);
}

void GPS::begin(unsigned long baud_rate)
{
  m_serial.begin(baud_rate, SERIAL_8N1, m_rx, m_tx);
  TaskHandle_t task_handle;
  xTaskCreate(nmea_parser, "nmea_parser", 8192, this, 0, &task_handle);
}

void GPS::end()
{
}