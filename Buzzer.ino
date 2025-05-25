void sonAllumageLED() {
  tone(A4, 1000, 80);
}

void sonPerdu() {
  tone(A4, 200, 500);
}

void sonVictoire() {
  int notes[] = { 523, 659, 784, 988 };  // Do - Mi - Sol - Si aigu
  int duration = 150;

  for (int i = 0; i < 4; i++) {
    tone(BUZZER_PIN, notes[i], duration);
    delay(duration + 50);  // petit espace entre les notes
  }

  noTone(BUZZER_PIN);
}
