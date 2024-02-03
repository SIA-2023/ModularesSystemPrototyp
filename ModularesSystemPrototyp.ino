#include "beispiel_module/led_blink/led_blink.h"
#include "beispiel_module/serial_input/serial_input.h"

LEDBlink led_blink;
SerialInput serial_input;

bool schnelles_blinken = false;

void setup() {
  led_blink.setup(LED_BUILTIN, 500);
  serial_input.setup('t');
}

void loop() {
  serial_input.update();

  if (serial_input.taste_gedrueckt)
    schnelles_blinken = !schnelles_blinken;

  led_blink.set_interval(schnelles_blinken ? 100 : 500);
  led_blink.update();
}