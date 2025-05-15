void allumerLeds(CRGB couleur, int delai) {
  eteindreLeds();
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = couleur;
    if ((i - 1) % 5 == 4 || i == NUM_LEDS - 1) {
      FastLED.show();
      delay(delai);
    }
  }
}

void eteindreLeds() {
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}
