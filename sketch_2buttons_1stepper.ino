#include <Stepper.h>

// change this to the number of steps in a full rotation on your motor
#define STEPS 100

// instances of the stepper class, specifying the number of steps of the motor and the pins it's attached to
//TODO these are the pins for the steppers, replace with correct values
Stepper stepper(STEPS, 8, 9, 10, 11);
const int stepperSpeed = 60; // 60 RPM
const int stepsPerLoop = 25;  //stepper will make 1/4 rotation per button press
//to make it rotate faster, increase stepperSpeed
//to make it rotate farther per button press, increase stepsPerLoop


//TODO these are the pins for the buttons, replace with correct values
const int buttonHi =  2;
const int buttonLo =  3;


void setup() {
  // initialize the pushbutton pins as inputs:
  pinMode(buttonHi, INPUT);
  pinMode(buttonLo, INPUT);

  stepper.setSpeed(stepperSpeed);
}

void loop() {
  // read the state of the pushbuttons
  buttonStateHi = digitalRead(buttonHi);
  buttonStateLo = digitalRead(buttonLo);

  //due to real-world positioning the buttons are mutually exclusive
  // Meaning we could decide to only read the Lo button state after checking if the Hi button is not pressed -- for now assuming this is not an expensive operation and checking anyway

  //still making the cases mutually exclusive just because I think it reads better and is reduces risk if this code is used some other way
  //the step method doesn't finish until the rotation is complete, so no need to explicitly stop the stepper
  // if the pushbutton is pressed, the buttonState is HIGH:
  if (buttonStateHi == HIGH) {
    stepper.step(stepsPerLoop);
  } else if (buttonStateLo == HIGH) {
    stepper.step(-stepsPerLoop); //negative and positive may need to be reversed
  }

}
