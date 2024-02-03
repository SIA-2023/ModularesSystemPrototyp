class LEDBlink {
public:  
  void setup(int led_pin, unsigned long blink_interval) {
    pin = led_pin;
    pinMode(pin, OUTPUT);
    
    interval = blink_interval;
  }

  void set_interval(unsigned long new_interval) {
    interval = new_interval;
  }

  void update() {
    unsigned long current_millis = millis();
    if (current_millis - prev_millis >= interval) {
      state = !state;
      digitalWrite(pin, state);
      prev_millis = current_millis;
    }
  }

private:
  int pin = LED_BUILTIN;
  bool state = false;
  unsigned long interval = 250;
  unsigned long prev_millis = 0;
};