#include <FastLED.h>

// Bandeau LED
#define NUM_LEDS 21
#define DATA_PIN 4

// Bouton poussoir
#define BUTTON_PIN 3
#define LED_BUILTIN 13

// Capteur ultrason
#define TRIG_PIN 8
#define ECHO_PIN 7

// Capteur de mouvement PIR
#define PIR_PIN 5

// Capteur buzzer
#define BUZZER_PIN A4

// Tableau LED
CRGB leds[NUM_LEDS];

void setup() {
  // Initialisation du bandeau LED
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
  eteindreLeds();

  // Initialisation des entrées/sorties
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);

  Serial.begin(9600);

  unsigned long t0 = millis();
  while (millis() - t0 < 1000) {
    // Attente active pendant 1 seconde pour ignorer les glitchs initiaux
    delay(10);
  }
  Serial.println("Cliquez sur le bouton pour démarrer le jeu");
}

bool jeuEnCours = false;
bool pretAPartir = false;  // devient true après avoir détecté distance > 1.5m
int dureeSoleil = 1000; // 1 seconde de capteur de mouvement

void loop() {
  // Appui bouton : démarrage ou arrêt
  if (gererBouton() && !jeuEnCours) {
    // 👉 On démarre le jeu uniquement si pas déjà en cours
    jeuEnCours = true;
    pretAPartir = false;
    eteindreLeds();
    delay(500);  // anti-rebond
  }


  if (!jeuEnCours) return;

  // 🔹 Étape 1 : attendre que le joueur soit à + de 1.5m
  if (!pretAPartir) {
    float d = lireDistanceUltrason();
    Serial.print("Distance avant départ : ");
    Serial.println(d);
    if (d > 150) {
      pretAPartir = true;
      Serial.println("✅ Distance suffisante. Le jeu commence !");
      delay(1000);
    } else {
      Serial.println("⛔ Reculez à plus de 1.5m");
      delay(500);
    }
    return;
  }

  // 🔹 Étape 2 : allumage LED progressif
  allumerLeds(CRGB::Green, 300);
  delay(300);
  if(!jeuEnCours){
    return;
  }

  // 🔹 Étape 3 : observation (ne pas bouger)
  Serial.println("🟡 Observation : ne bougez plus !");
  bool mouvementDetecte = false;
  allumerTout(CRGB(255, 80, 0));
  unsigned long t0 = millis();

  while (millis() - t0 < dureeSoleil) {
    if (detecterMouvement()) {
      mouvementDetecte = true;
      break;
    }
    delay(100);
  }

  // 🔹 Étape 4 : résultat
  if (mouvementDetecte) {
    Serial.println("🔴 MOUVEMENT DÉTECTÉ : PERDU !");
    sonPerdu();
    allumerTout(CRGB::Red);
    eteindreLeds();

    // Attente que le joueur recule à nouveau
    pretAPartir = false;
  } else {
    Serial.println("✅ Aucun mouvement, on continue !");
    eteindreLeds();
    delay(500);
  }
}

