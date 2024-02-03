#include "serial_input.h"

SerialInput serial_input;

void setup() {
  serial_input.setup('t');
}

void loop() {
  serial_input.update();

  if (serial_input.taste_gedrueckt) {
    Serial.println("taste wurde gedrückt");
  }
}