#include <Stepper.h>

// change this to the number of steps in a full rotation on your motor
#define STEPS 100

// instances of the stepper class, specifying the number of steps of the motor and the pins it's attached to
//TODO these are the pins for the steppers, replace with correct values
Stepper blueStepper(STEPS, 8, 9, 10, 11);
Stepper redStepper(STEPS, 12, 13, 14, 15);
const int stepperSpeed = 60; // 60 RPM
const int stepsPerLoop = 25;  //stepper will make 1/4 rotation per button press
//to make it rotate faster, increase stepperSpeed
//to make it rotate farther per button press, increase stepsPerLoop


//TODO these are the pins for the buttons, replace with correct values
const int buttonHiBlue =    2;
const int buttonLoBlue =  3;
const int buttonHiRed =    4;
const int buttonLoRed =    5;


void setup() {
  // initialize the pushbutton pins as inputs:
  pinMode(buttonHiBlue, INPUT);
  pinMode(buttonLoBlue, INPUT);
  pinMode(buttonHiRed, INPUT);
  pinMode(buttonLoRed, INPUT);

  blueStepper.setSpeed(stepperSpeed);
  redStepper.setSpeed(stepperSpeed);

}

void loop() {
  // read the state of the pushbuttons
  buttonStateHiBlue = digitalRead(buttonHiBlue);
  buttonStateLoBlue = digitalRead(buttonLoBlue);
  buttonStateHiRed = digitalRead(buttonHiRed);
  buttonStateLoRed = digitalRead(buttonLoRed);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  //due to real-world positioning the buttons are mutually exclusive per red/blue team.
  // Meaning we could decide to only read the Lo button state after checking if the Hi button is not pressed -- for now assuming this is not an expensive operation and checking anyway

  //still making the cases mutually exclusive just because I think it reads better and is reduces risk if this code is used some other way
  //the step method doesn't finish until the rotation is complete, so no need to explicitly stop the stepper
  // if the pushbutton is pressed, the buttonState is HIGH:
  if (buttonStateHiBlue == HIGH) {
    blueStepper.step(stepsPerLoop);
  } else if (buttonStateLoBlue == HIGH) {
    blueStepper.step(-stepsPerLoop); //negative and positive may need to be reversed
  }

//the step function is blocking, so redStepper will not rotate until blueStepper is complete

  if (buttonStateHiRed == HIGH) {
    redStepper.step(stepsPerLoop);
  } else if (buttonStateLoRed == HIGH) {
    redStepper.step(-stepsPerLoop); //negative and positive may need to be reversed
  }

}
