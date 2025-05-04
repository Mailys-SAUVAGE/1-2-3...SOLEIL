#include <Adafruit_NeoPixel.h>

// Branchements
const int pinCapteurMouvement = 3;
const int pinBandeauLED = 6;
const int nombreLEDs = 4; // A modifier en fonction des leds du prof

// Paramètres du jeu (en ms)
const unsigned long dureeOrange = 4000; // Durée de la phase orange
const unsigned long dureeRouge = 3000; // Durée indépendante de la phase rouge
const unsigned long delaiRemplissageLED = 500; // Temps entre chaque LED qui s’allume

// Varibles de phases de jeu
enum PhaseJeu { PHASE_REMPLISSAGE, PHASE_ORANGE, PHASE_ROUGE };
PhaseJeu phaseJeu = PHASE_REMPLISSAGE;
unsigned long dernierTempsPhase = 0;

// Bandeau de leds
Adafruit_NeoPixel leds = Adafruit_NeoPixel(nombreLEDs, pinBandeauLED, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(pinCapteurMouvement, INPUT);
  leds.begin();
  leds.show();
  Serial.begin(9600);
  eteindreLEDs();
}

void loop() {
  // Récupérer le temps depuis lancement du code pour reference
  unsigned long tempsActuel = millis();

  switch (phaseJeu) {
    
    // 1,2,3...
    case PHASE_REMPLISSAGE:
      remplissageProgressif();
      dernierTempsPhase = millis();
      phaseJeu = PHASE_ORANGE;
      break;
    
    // ...SOLEIL
    case PHASE_ORANGE:
      if (digitalRead(pinCapteurMouvement) == HIGH) {
        Serial.println("Mouvement détecté !");
        definirCouleurLEDs(255, 0, 0); // Rouge
        dernierTempsPhase = tempsActuel;
        phaseJeu = PHASE_ROUGE;
      } else if (tempsActuel - dernierTempsPhase >= dureeOrange) {
        phaseJeu = PHASE_REMPLISSAGE;
      }
      break;
    
    // MOUVEMENT DETECTE !
    case PHASE_ROUGE:
      if (tempsActuel - dernierTempsPhase >= dureeRouge) { 
        phaseJeu = PHASE_REMPLISSAGE;
      }
      break;
  }
}

// Remplissage LED une à une en vert
void remplissageProgressif() {
  eteindreLEDs();
  for (int i = 0; i < nombreLEDs; i++) {
    leds.setPixelColor(i, leds.Color(0, 255, 0)); // Vert
    leds.show();
    delay(delaiRemplissageLED);
  }
  // Remplissage final orange
  definirCouleurLEDs(255, 165, 0);
}

// Définir la couleur des LEDs
void definirCouleurLEDs(int rouge, int vert, int bleu) {
  for (int i = 0; i < nombreLEDs; i++) {
    leds.setPixelColor(i, leds.Color(rouge, vert, bleu));
  }
  leds.show();
}

// Éteindre les LEDs
void eteindreLEDs() {
  definirCouleurLEDs(0, 0, 0);
}
