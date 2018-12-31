/*
 * Project GarageDoorsAP
 * Description:
 * Author:
 * Date:
 */

const int leftTrigger = A0;
bool leftOpen = false;

void setup() {

Particle.function("leftDoorToogle", leftDoorToogle);

  pinMode(leftTrigger, OUTPUT);
  digitalWrite(leftTrigger, LOW);
  leftOpen = false;

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

}

int leftDoorToogle(String command) {
  // look for the matching argument "coffee" <-- max of 64 characters long
  if(command == "1") {
    
    if (leftOpen == true) {
      digitalWrite(leftTrigger, HIGH);
      delay(500);
      digitalWrite(leftTrigger, LOW);
      leftOpen = false;
    } else if (leftOpen == false) {
      digitalWrite(leftTrigger, HIGH);
      delay(500);
      digitalWrite(leftTrigger, LOW);
      leftOpen = true;
    }
    

    return 1;
  } else return -1;
}