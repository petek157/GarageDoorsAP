/*
 * Project GarageDoorsAP
 * Description:
 * Author:
 * Date:
 */

const int tDelay = 500;

//Wash
const int leftTrigger = A0;
bool leftOpen = false;

//Mech
const int rightTrigger = A1;
bool rightOpen = false;



void setup() {

  WiFi.setCredentials("GLF", "abcdef1234");
  WiFi.setCredentials("IHV", "abcdef1234");
  WiFi.setCredentials("PKShop", "abcdef1234");

  //Wash
  Particle.variable("leftopen", leftOpen);
  Particle.function("tleftdoor", tleftdoor);
  pinMode(leftTrigger, OUTPUT);
  digitalWrite(leftTrigger, LOW);
  leftOpen = false;

  //Mech
  Particle.variable("rightopen", rightOpen);
  Particle.function("trightdoor", trightdoor);
  pinMode(rightTrigger, OUTPUT);
  digitalWrite(rightTrigger, LOW);
  rightOpen = false;

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

}

int tleftdoor(String command) {
  // look for the matching argument "coffee" <-- max of 64 characters long
  if(command == "1") {
    
    if (leftOpen == true) {
      digitalWrite(leftTrigger, HIGH);
      delay(tDelay);
      digitalWrite(leftTrigger, LOW);
      leftOpen = false;
    } else if (leftOpen == false) {
      digitalWrite(leftTrigger, HIGH);
      delay(tDelay);
      digitalWrite(leftTrigger, LOW);
      leftOpen = true;
    }
    

    return 1;
  } else return -1;
}

int trightdoor(String command) {
  // look for the matching argument "coffee" <-- max of 64 characters long
  if(command == "1") {
    
    if (rightOpen == true) {
      digitalWrite(rightTrigger, HIGH);
      delay(tDelay);
      digitalWrite(rightTrigger, LOW);
      rightOpen = false;
    } else if (rightOpen == false) {
      digitalWrite(rightTrigger, HIGH);
      delay(tDelay);
      digitalWrite(rightTrigger, LOW);
      rightOpen = true;
    }
    

    return 1;
  } else return -1;
}