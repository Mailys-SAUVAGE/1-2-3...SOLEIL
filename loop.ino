#include <FastLED.h>
#include "Leds.ino"
#include "Ultrason.ino"
#include "Buzzer.ino"

// Bandeau LED
#define NUM_LEDS 21
#define DATA_PIN 4

// Bouton poussoir
#define BUTTON_PIN 2
#define LED_BUILTIN 13

// Capteur ultrason
#define TRIG_PIN 8
#define ECHO_PIN 7

// Capteur de mouvement PIR
#define PIR_PIN 6

// Tableau LED
CRGB leds[NUM_LEDS];

void setup() {
  // Initialisation du bandeau LED
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
  eteindreLeds();

  // Initialisation des entrées/sorties
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(PIR_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Lecture état bouton
  int bouton = digitalRead(BUTTON_PIN);
  digitalWrite(LED_BUILTIN, bouton == LOW ? HIGH : LOW);

  // Mesure distance
  float distance = lireDistanceUltrason();
  Serial.print("Distance (cm) : ");
  Serial.println(distance);

  // Lecture capteur de mouvement PIR
  int mouvement = digitalRead(PIR_PIN);

  // Allumage progressif des LEDs
  allumerLeds(CRGB::Green, 1000);

  if (mouvement == HIGH) {
    Serial.println("Mouvement détecté !");
  } else {
    Serial.println("Pas de mouvement.");
  }

  eteindreLeds();
  delay(500);      // pause avant la boucle suivante
}
