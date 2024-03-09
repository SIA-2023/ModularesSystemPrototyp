#pragma once

void serial_input_setup() {
  Serial.begin(9600);
}

bool serial_input_taste_gedrueckt(char taste) {
  if (Serial.available()) {
    return Serial.read() == taste;
  }
  return false;
}