
#include <stdint.h>
#include "UART.h"
#include "CRC16_modbus.h"

void Modbus_ReadFunc (uint8_t ID, uint8_t func, uint16_t reg_addr, uint16_t reg_num)
{
  uint8_t TxBuff[8];
  TxBuff[0] = ID;
  TxBuff[1] = func;
  TxBuff[2] = (reg_addr >> 8) & 0xFF;
  TxBuff[3] = reg_addr & 0xFF;
  TxBuff[4] = (reg_num >> 8) & 0xFF;
  TxBuff[5] = reg_num & 0xFF;
  uint16_t temp;
  temp = Modbus_CRC16Cal(TxBuff, 6);
  TxBuff[6] = temp & 0xFF;
  TxBuff[7] = (temp >> 8) & 0xFF;
  for (int i = 0; i < 8; i++)
  {
    Serial.write (TxBuff[i]);
  }
}

