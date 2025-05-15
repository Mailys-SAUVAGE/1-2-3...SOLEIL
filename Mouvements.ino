bool detecterMouvement() {
  int etat = digitalRead(PIR_PIN);
  if (etat == HIGH) {
    return true;
  } else {
    return false;
  }
}