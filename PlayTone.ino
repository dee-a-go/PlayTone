int buzzerPin = 5;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  delay(200);
}

void loop() {
  for (int semitone = 0; semitone <= 12; semitone += 1) {
    float frequency = 440 * pow(2, semitone/12.);
    playTone(frequency, 1000);
  }
  delay(200);
  for (int i = 5000; i >= 0; i -= 100) {
    playTone(i, 50);
  }
  delay(200);
}

void playTone(long frequency, long duration) {
  long halfPeriod = (1000000L / frequency) / 2.; // calculate the period in microseconds and divide by two to obtain the midpoint.
  long cycles = frequency * (duration / 1000.); // calculate the number of cycles (time given in ms).

  for (long i = 0; i < cycles; i++) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(halfPeriod); // set the high duration
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(halfPeriod); // set the low duration
  }
}
