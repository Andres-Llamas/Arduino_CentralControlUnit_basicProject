#include <Arduino.h>
#include "GUI.h"

const int powerAllPin = 12;
const int lcdBackLightPin = 8;
const int rs = 11, en = 10, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
const int leftButtonPin = 52, rightButtonPin = 53, upButtonPin = 51, downButtonPin = 50, selectButtonPin = 49;
const int relayForLights= 45, relayPositivePin = 44;
ButtonSystem buttonSystem(leftButtonPin, rightButtonPin, upButtonPin, downButtonPin, selectButtonPin);
GUI interface (rs, en, d4, d5, d6, d7, lcdBackLightPin);
Behaviours behaviours(relayForLights);

void setup()
{
  //-------------------- Initialize buttons ------------------------
  pinMode(leftButtonPin, INPUT);
  digitalWrite(leftButtonPin, HIGH);
  pinMode(rightButtonPin, INPUT);
  digitalWrite(rightButtonPin, HIGH);
  pinMode(upButtonPin, INPUT);
  digitalWrite(upButtonPin, HIGH);
  pinMode(downButtonPin, INPUT);
  digitalWrite(downButtonPin, HIGH);
  pinMode(selectButtonPin, INPUT);
  digitalWrite(selectButtonPin, HIGH);
  //-------------------- Initialize buttons ------------------------

  //-------------------- Initialize pins ------------------------
  pinMode(relayForLights, OUTPUT);
  pinMode(relayPositivePin, OUTPUT);
  digitalWrite(relayPositivePin, HIGH);

  pinMode(lcdBackLightPin, OUTPUT);
  digitalWrite(lcdBackLightPin, HIGH);

  pinMode(powerAllPin, OUTPUT);
  digitalWrite(powerAllPin, HIGH);  
  //-------------------- Initialize pins ------------------------

  interface.Initialize();
  Serial.begin(9600);
}

void loop()
{
  if(buttonSystem.CheckDownButton(true)) Serial.print("Down ");
  if(buttonSystem.CheckUpButton(true)) Serial.print("Up ");
  if(buttonSystem.CheckSelectButton()) Serial.print("Select");
}
