  extern bool jeuEnCours; // variable de loop.ino

  bool gererBouton() {
    int etat = digitalRead(BUTTON_PIN);

    if (etat == LOW) {
      return true;
    } else {
      return false;
    }
  }

  // Vérifie bouton, interrompt le jeu si appuyé
  bool verifierFin() {
    if (gererBouton()){
        sonVictoire();
        Serial.println("VICTOIRE !!!");
        allumerTout(CRGB(255, 215, 0));
        jeuEnCours = false;
        return true;
    }
    return false;
  }
