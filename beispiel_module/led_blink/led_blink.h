#pragma once

struct LEDBlink {
  int pin = LED_BUILTIN;
  bool state = false;
  unsigned long interval_ms = 250;
  unsigned long prev_millis = 0;

  void setup(int led_pin, unsigned long blink_interval);
  void update();
};

void LEDBlink::setup(int led_pin, unsigned long blink_interval_ms) {
  pin = led_pin;
  pinMode(pin, OUTPUT);
  interval_ms = blink_interval_ms;
}

void LEDBlink::update() {
    unsigned long current_millis = millis();
    if (current_millis - prev_millis >= interval_ms) {
      state = !state;
      digitalWrite(pin, state);
      prev_millis = current_millis;
    }
  }