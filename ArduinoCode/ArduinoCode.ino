void setup() {
  Serial.begin(9600);
  for (int pin = 2; pin <= 12; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int pin = input.toInt();
    if (pin >= 2 && pin <= 12) {
      int state = digitalRead(pin);
      digitalWrite(pin, !state);
      Serial.println(digitalRead(pin));
    }
  }
}
