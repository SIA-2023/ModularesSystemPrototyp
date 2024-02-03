#include "led_blink.h"

LEDBlink led_blink;

void setup() {
  led_blink.setup(LED_BUILTIN, 500);
}

void loop() {
  led_blink.update();
}