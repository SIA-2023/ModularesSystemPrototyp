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

void setup() {
  serial_input_setup();
}

void loop() {
  if (serial_input_taste_gedrueckt('t')) {
    Serial.println("taste wurde gedrückt");
  }
}
```

### Module implementieren
#### [led_blink.h](beispiel_module/led_blink/led_blink.h):
```c++
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
```

#### [serial_input.h](beispiel_module/serial_input/serial_input.h)
```c++
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
```