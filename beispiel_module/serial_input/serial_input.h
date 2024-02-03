class SerialInput {
public:
  void setup(char input_taste) {
    taste = input_taste;
    Serial.begin(9600);
  }

  void update() {
    taste_gedrueckt = false;

    if (Serial.available()) {
      switch (Serial.read()) {
        case 't': taste_gedrueckt = true; break;
      }
    }
  }

  char taste = ' ';
  bool taste_gedrueckt = false;
};