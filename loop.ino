#include <FastLED.h>

// leds
#define NUM_LEDS 21
#define DATA_PIN 4

// boutton
#define BUTTON_PIN 2
#define LED_BUILTIN 13

// capteur ultrason
#define TRIG_PIN 8
#define ECHO_PIN 7

// capteur de mouvement
#define PIR_PIN 6  

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
  eteindreLeds();

  // Bouton + LED intégrée
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  // Capteur ultrason
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Capteur de mouvement PIR
  pinMode(PIR_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Lecture bouton
  int bouton = digitalRead(BUTTON_PIN);
  digitalWrite(LED_BUILTIN, bouton == LOW ? HIGH : LOW);

  // Lecture ultrason
  float distance = lireDistanceUltrason();
  Serial.print("Distance (cm) : ");
  Serial.println(distance);

  // Lecture capteur de mouvement PIR
  int mouvement = digitalRead(PIR_PIN);
  allumerLeds(CRGB::Green, 1000);
  if (mouvement == HIGH) {
    Serial.println("Mouvement détecté !");
  } else {
    Serial.println("Pas de mouvement.");
  }
  eteindreLeds();
  delay(500);
}

void allumerLeds(CRGB couleur, int delai) {
  eteindreLeds();  // Réinitialise d’abord les LED
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

float lireDistanceUltrason() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // calcul en cm
  return distance;
}
