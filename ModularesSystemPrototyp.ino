#include "beispiel_module/led_blink/led_blink.h"
#include "beispiel_module/serial_input/serial_input.h"

LEDBlink led_blink;

bool schnelles_blinken = false;

void setup() {
  serial_input_setup();
  led_blink.setup(LED_BUILTIN, 500);
}

void loop() {
  if (serial_input_taste_gedrueckt('t')) {
    schnelles_blinken = !schnelles_blinken;
  }

  led_blink.interval_ms = schnelles_blinken ? 100 : 500;
  led_blink.update();
}