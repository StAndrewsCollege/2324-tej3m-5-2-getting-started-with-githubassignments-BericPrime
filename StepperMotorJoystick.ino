// SETUP OF CONSTS (i dont like #define)
const int StepX = 2; //sets up the stepper motor Step Pins
const int StepY = 3;
const int StepZ = 4;

const int DirX = 5; //sets up the stepper motor Direction Pins
const int DirY = 6;
const int DirZ = 7;

const int LeftButton = 6; //sets up the joystick button pins
const int RightButton = 7;


void setup() {
  pinMode(StepX, OUTPUT); // adjusts the pin mode of the respective pins
  pinMode(DirX, OUTPUT);
  pinMode(StepY, OUTPUT);
  pinMode(DirY, OUTPUT);
  pinMode(StepZ, OUTPUT);
  pinMode(DirZ, OUTPUT);
  Serial.begin(9600); //b begins serial monitor
}

void loop() {

  if (analogRead(8) == 0 || analogRead(8) == 1023) { //checks to see if X joystick is at MAX or MIN
    XMove(); //if it is at either extreme (0, or 1023), then begin the "XMove()" function
  }
  if (analogRead(9) == 0 || analogRead(9) == 1023) { //checks to see if Y joystick is at MAX or MIN
    YMove(); //if it is at either extreme (0, or 1023), then begin the "YMove()" function
  }
  if (analogRead(11) == 0 || analogRead(11) == 1023) { //checks to see if Z joystick is at MAX or MIN
    ZMove(); //if it is at either extreme (0, or 1023), then begin the "ZMove()" function
  }
  // missing code for servo as it is not added yet
}
void XMove() { 
  if (analogRead(8) == 0) { //Checks to see if joystick is at MIN (Left most position)
    digitalWrite(DirX, HIGH); //sets stepper direction to spin proper way if its at MIN
  } else {
    digitalWrite(DirX, LOW); //sets stepper direction to spin other way if its at not MIN (MAX)
  }
  //stepper movement
  digitalWrite(StepX, HIGH); //sets one phase of motor to high
  delayMicroseconds(1600); //for 1600 MICRO seconds
  digitalWrite(StepX, LOW); //sets one phase of motor to low
  delayMicroseconds(1600); //for 1600 MICRO seconds
}
void YMove() {
  if (analogRead(9) == 0) { //Checks to see if joystick is at MIN (Left most position)
    digitalWrite(DirY, HIGH); //sets stepper direction to spin proper way if its at MIN
  } else {
    digitalWrite(DirY, LOW); //sets stepper direction to spin other way if its at not MIN (MAX)
  }
  //stepper movement
  digitalWrite(StepY, HIGH); //sets one phase of motor to high
  delayMicroseconds(1600); //for 1600 MICRO seconds
  digitalWrite(StepY, LOW); //sets one phase of motor to low
  delayMicroseconds(1600); //for 1600 MICRO seconds
}
void ZMove() {
  //DIRECTIONAL NON FUNCTIONAL FOR UNIPOLAR
  if (analogRead(11) == 0) { //Checks to see if joystick is at MIN (Left most position)
    digitalWrite(DirZ, HIGH); //sets stepper direction to spin proper way if its at MIN
  } else {
    digitalWrite(DirZ, LOW); //sets stepper direction to spin other way if its at not MIN (MAX)
  }
  //stepper movement
  digitalWrite(StepZ, HIGH); //sets one phase of motor to high
  delayMicroseconds(400); //for 400 MICRO seconds (Less as it needs to go faster as it has a high gear ratio)
  digitalWrite(StepZ, LOW); //sets one phase of motor to low
  delayMicroseconds(400); //for 400 MICRO seconds
}

//servo code is missing as it is not added yet
