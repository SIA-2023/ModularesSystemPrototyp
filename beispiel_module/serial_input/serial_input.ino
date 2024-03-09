#include "serial_input.h"

void setup() {
  serial_input_setup();
}

void loop() {
  if (serial_input_taste_gedrueckt('t')) {
    Serial.println("taste wurde gedrückt");
  }
}