#include "application.h"
#line 1 "/Users/peterkoruga/Documents/p3e/Particle/Projects/WashShop/GarageDoorsAP/src/GarageDoorsAP.ino"
/*
 * Project GarageDoorsAP
 * Description:
 * Author:
 * Date:
 */

//const int tDelay = 500;

//Pins
void setup();
void loop();
int tleftdoor(String command);
int trightdoor(String command);
int testRelay(String command);
#line 11 "/Users/peterkoruga/Documents/p3e/Particle/Projects/WashShop/GarageDoorsAP/src/GarageDoorsAP.ino"
const int powerPin = D13;
const int selectorPin = A5;
const int operatorPin = A4;


//Wash
//const int leftTrigger = A0;
const int leftCheck = D5;
bool leftOpen = false;

//Mech
//const int rightTrigger = A1;
const int rightCheck = D6;
bool rightOpen = false;



void setup() {

  WiFi.setCredentials("GLF", "abcdef1234");
  WiFi.setCredentials("IHV", "abcdef1234");
  WiFi.setCredentials("PKShopNet", "abcdef1234");

  //Wash
  Particle.variable("leftopen", leftOpen);
  Particle.function("tleftdoor", tleftdoor);
  //pinMode(leftTrigger, OUTPUT);
  pinMode(leftCheck, INPUT_PULLUP);
  //digitalWrite(leftTrigger, LOW);
  leftOpen = false;

  //Mech
  Particle.variable("rightopen", rightOpen);
  Particle.function("trightdoor", trightdoor);
  // pinMode(rightTrigger, OUTPUT);
  pinMode(rightCheck, INPUT_PULLUP);
  //digitalWrite(rightTrigger, LOW);
  rightOpen = false;

  //Pins
  pinMode(powerPin, OUTPUT);
  pinMode(selectorPin, OUTPUT);
  pinMode(operatorPin, OUTPUT);
  digitalWrite(powerPin, LOW);
  digitalWrite(selectorPin, LOW);
  digitalWrite(operatorPin, LOW);

  //Test Function
  Particle.function("testRelay", testRelay);
}

void loop() {
  if (digitalRead(leftCheck) == HIGH) {
    leftOpen = true;
  } else {
    leftOpen = false;
  }

  if (digitalRead(rightCheck) == HIGH) {
    rightOpen = true;
  } else {
    rightOpen = false;
  }

}

int tleftdoor(String command) {
  if(command == "1") {//Open Left Door
    
    digitalWrite(operatorPin, LOW);
    delay(150);
    digitalWrite(selectorPin, LOW);
    delay(150);
    digitalWrite(powerPin, HIGH);
    delay(500);
    digitalWrite(powerPin, LOW);
    digitalWrite(selectorPin, LOW);
    digitalWrite(operatorPin, LOW);
    
    

    // digitalWrite(leftTrigger, HIGH);
    // delay(tDelay);
    // digitalWrite(leftTrigger, LOW);

    // if (leftOpen == true) {
    //   digitalWrite(leftTrigger, HIGH);
    //   delay(tDelay);
    //   digitalWrite(leftTrigger, LOW);
    //   leftOpen = false;
    // } else if (leftOpen == false) {
    //   digitalWrite(leftTrigger, HIGH);
    //   delay(tDelay);
    //   digitalWrite(leftTrigger, LOW);
    //   leftOpen = true;
    // }
    

    return 1;
  } else if (command == "0") {//Close Left Door

    digitalWrite(operatorPin, HIGH);
    delay(150);
    digitalWrite(selectorPin, LOW);
    delay(150);
    digitalWrite(powerPin, HIGH);
    delay(500);
    digitalWrite(powerPin, LOW);
    digitalWrite(selectorPin, LOW);
    digitalWrite(operatorPin, LOW);

    return 1;
  } else return -1;
}

int trightdoor(String command) {
  if(command == "1") {//Open Right Door
    
    digitalWrite(operatorPin, LOW);
    delay(150);
    digitalWrite(selectorPin, HIGH);
    delay(150);
    digitalWrite(powerPin, HIGH);
    delay(500);
    digitalWrite(powerPin, LOW);
    digitalWrite(selectorPin, LOW);
    digitalWrite(operatorPin, LOW);

    // digitalWrite(rightTrigger, HIGH);
    // delay(tDelay);
    // digitalWrite(rightTrigger, LOW);
    // if (rightOpen == true) {
    //   digitalWrite(rightTrigger, HIGH);
    //   delay(tDelay);
    //   digitalWrite(rightTrigger, LOW);
    //   rightOpen = false;
    // } else if (rightOpen == false) {
    //   digitalWrite(rightTrigger, HIGH);
    //   delay(tDelay);
    //   digitalWrite(rightTrigger, LOW);
    //   rightOpen = true;
    // }
    

    return 1;
  } else if (command == "0") {// Close left door

    digitalWrite(operatorPin, HIGH);
    delay(150);
    digitalWrite(selectorPin, HIGH);
    delay(150);
    digitalWrite(powerPin, HIGH);
    delay(500);
    digitalWrite(powerPin, LOW);
    digitalWrite(selectorPin, LOW);
    digitalWrite(operatorPin, LOW);
    return 1;
  } else return -1;
}

int testRelay(String command) {

  if (command == "1") {

    digitalWrite(operatorPin, HIGH);
    digitalWrite(selectorPin, HIGH);
    digitalWrite(powerPin, HIGH);

    return 1;
  } else if (command == "0") {
    digitalWrite(powerPin, LOW);
    digitalWrite(selectorPin, LOW);
    digitalWrite(operatorPin, LOW);
    return 1;
  } else return -1;
}