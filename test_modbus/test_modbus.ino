#include "CRC16_modbus.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  uint8_t buff[4] = {0x01, 0x02, 0x03, 0x04};
  uint16_t temp;
  
  temp = CRC16_ModbusCal (buff, 4);
  Serial.write (temp & 0xFF);
  Serial.write ((temp >> 8) & 0xFF);
}

void loop() {
  // put your main code here, to run repeatedly:

}
