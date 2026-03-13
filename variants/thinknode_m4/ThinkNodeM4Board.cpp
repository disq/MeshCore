#include <Arduino.h>
#include "ThinkNodeM4Board.h"
#include <Wire.h>

#include <bluefruit.h>

void ThinkNodeM4Board::begin() {
  NRF52Board::begin();
  btn_prev_state = HIGH;

  Wire.begin();

  delay(10);   // give LR1110 some time to power up
}

uint16_t ThinkNodeM4Board::getBattMilliVolts() {
  analogReference(AR_INTERNAL_3_0);
  analogReadResolution(ADC_RESOLUTION);
  delay(10);

  int adcvalue = analogRead(PIN_VBAT_READ);
  return (uint16_t)((float)adcvalue * REAL_VBAT_MV_PER_LSB);
}
