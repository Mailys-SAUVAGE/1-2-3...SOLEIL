extern bool jeuEnCours; // variable de loop.ino

void allumerLeds(CRGB couleur, int delai) {
  eteindreLeds();

  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = couleur;

    // Afficher toutes les 5 LEDs ou à la fin
    if ((i - 1) % 5 == 4 || i == NUM_LEDS - 1) {
      FastLED.show();
      sonAllumageLED();

      // ⏳ Attente divisée en petits pas pour pouvoir interrompre
      int pas = 10;  // 10 ms d'attente
      int attente = 0;
      while (attente < delai) {
        if (verifierFin()){
          return;  // 👈 interrompt l'allumage proprement
        }
        delay(pas);
        attente += pas;
      }
      delay(250);
    }
  }
}


void allumerTout(CRGB couleur) {
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = couleur;
  }
  FastLED.show();
  delay(1000);
}

void eteindreLeds() {
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}
