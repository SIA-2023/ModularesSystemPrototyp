# ModularesSystemPrototyp
Arduino program welches mehrere Module kombiniert und individuell getested werden kann

## Idee:
- Module können einfach kombiniert werden
- Module können seperat getested werden
- Module können miteinander verwendet werden (Bsp: LED blinkt schneller wenn `t` im Seriellen Input gedrückt wird)

## Struktur
```
└── Hauptprogram
  ├── Hauptprogram.ino
  └── module
    ├── led_blink
      ├── led_blink.h
      └── led_blink.ino
    └── serial_input
      ├── serial_input.h
      └── serial_input.ino
```



### Hauptprogram [ModularesSystemPrototyp.ino](ModularesSystemPrototyp.ino)
```c++
#include "module/led_blink/led_blink.h"
#include "module/serial_input/serial_input.h"

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
```

### Einzelne Module testen
#### [led_blink.ino](beispiel_module/led_blink/led_blink.ino):
```c++
#include "led_blink.h"

LEDBlink led_blink;

void setup() {
  led_blink.setup(LED_BUILTIN, 500);
}

void loop() {
  led_blink.update();
}
```
#### [serial_input.ino](beispiel_module/serial_input/serial_input.ino):
```c++
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
```