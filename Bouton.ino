bool gererBouton() {
  int etat = digitalRead(BUTTON_PIN);

  if (etat == LOW) {
    return true;
  } else {
    return false;
  }
}
