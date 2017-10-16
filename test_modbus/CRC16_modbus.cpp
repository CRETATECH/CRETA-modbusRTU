
#include <stdint.h>
#include "CRC16_modbus.h"


uint16_t Modbus_CRC16Cal (uint8_t *pBuff, uint8_t pLen)
{
  uint16_t crc = 0xFFFF;
  for (int pos = 0; pos < pLen; pos++)
  {
    crc ^= (uint16_t) pBuff[pos]; // XOR byte into least sig. byte of crc
    for (int i = 0; i < 8; i++)   // Loop over each bit
    {
      if ((crc & 0x0001) != 0 )   // If the LSB is set
      {
        crc >>= 1;                
        crc ^= 0xA001;
      }
      else
        crc >>= 1;
    }
  }
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
  return crc;
}

