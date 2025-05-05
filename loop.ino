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


// code du buzzer

/*
  Melody

  Plays a melody when button D2 is triggered

  circuit:
  - 8 ohm speaker on digital pin A4

  

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"


#define Button 2
#define Buzzer A4

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {

  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(Button, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Buzzer, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(Buzzer);
  }
}

void loop() {
  // no need to repeat the melody.

  //read the pushbutton value into a variable
  int sensorVal = digitalRead(Button);
  //print out the value of the pushbutton
  Serial.println(sensorVal);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Buzzer, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(Buzzer);
  }
  
}

}
