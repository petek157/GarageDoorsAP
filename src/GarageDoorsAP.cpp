/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

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
int openLeft();
int closeLeft();
int openRight();
int closeRight();
int tleftdoor(String command);
int trightdoor(String command);
#line 11 "/Users/peterkoruga/Documents/p3e/Particle/Projects/WashShop/GarageDoorsAP/src/GarageDoorsAP.ino"
const int powerPin = D13;
const int selectorPin = A5;
const int operatorPin = A4;


//Wash
const int leftCheck = A0;
int leftPrevStatus = 0;//0 Closed, 1 Open
int leftStatus = 0;

//Mech
const int rightCheck = A2;
int rightPrevStatus = 0;
int rightStatus = 0;

ApplicationWatchdog wd(60000, System.reset);

void setup() {

  WiFi.setCredentials("GLF", "abcdef1234");
  WiFi.setCredentials("IHV", "abcdef1234");
  WiFi.setCredentials("PKShopNet", "abcdef1234");

  //Wash
  Particle.variable("leftopen", leftStatus);
  Particle.function("tleftdoor", tleftdoor);
  pinMode(leftCheck, INPUT_PULLUP);
  leftStatus = 0;

  //Mech
  Particle.variable("rightopen", rightStatus);
  Particle.function("trightdoor", trightdoor);
  pinMode(rightCheck, INPUT_PULLUP);
  rightStatus = 0;

  //Pins
  pinMode(powerPin, OUTPUT);
  pinMode(selectorPin, OUTPUT);
  pinMode(operatorPin, OUTPUT);
  digitalWrite(powerPin, LOW);
  digitalWrite(selectorPin, LOW);
  digitalWrite(operatorPin, LOW);

}

void loop() {

  leftStatus = digitalRead(leftCheck);
  rightStatus = digitalRead(rightCheck);

  if (leftStatus != leftPrevStatus) {
    if (leftStatus == 1) {
      Particle.publish("door", "left,open", PRIVATE);
    } else {
      Particle.publish("door", "left,close", PRIVATE);
    }
    leftPrevStatus = leftStatus;
  }

  if (rightStatus != rightPrevStatus) {
    if (rightStatus == 1) {
      Particle.publish("door", "right,open", PRIVATE);
    } else {
      Particle.publish("door", "right,close", PRIVATE);
    }
    rightPrevStatus = rightStatus;
  }

}

int openLeft() {
  digitalWrite(powerPin, HIGH);
  delay(1000);

  digitalWrite(powerPin, LOW);

  return 1;
}

int closeLeft() {
  digitalWrite(operatorPin, HIGH);
  delay(150);
  digitalWrite(powerPin, HIGH);
  delay(1000);

  digitalWrite(operatorPin, LOW);
  digitalWrite(powerPin, LOW);

  return 0;
}

int openRight() {
  digitalWrite(operatorPin, HIGH);
  delay(150);
  digitalWrite(selectorPin, HIGH);
  delay(150);
  digitalWrite(powerPin, HIGH);
  delay(1000);

  digitalWrite(powerPin, LOW);
  digitalWrite(selectorPin, LOW);
  digitalWrite(operatorPin, LOW);

  return 1;
}

int closeRight() {
  digitalWrite(selectorPin, HIGH);
  delay(150);
  digitalWrite(powerPin, HIGH);
  delay(1000);

  digitalWrite(powerPin, LOW);
  digitalWrite(selectorPin, LOW);

  return 0;

}

int tleftdoor(String command) {

  if (leftStatus == 1) {
    return closeLeft();
  } else if (leftStatus == 0) {
    return openLeft();
  } else {
    return -1;
  }

}

int trightdoor(String command) {

  if (rightStatus == 1) {
    return closeRight();
  } else if (rightStatus == 0) {
    return openRight();
  } else {
    return -1;
  }
}