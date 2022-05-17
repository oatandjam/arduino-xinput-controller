#include <XInput.h>

//joystick
const uint8_t Pin_JoystickLX = A1;
const uint8_t Pin_JoystickLY = A2;
const uint8_t Pin_JoystickRX = A4;
const uint8_t Pin_JoystickRY = A5;
//buttons
const uint8_t Pin_ButtonA= 3;
const uint8_t Pin_ButtonB= 4;
const uint8_t Pin_ButtonX= 5;
const uint8_t Pin_ButtonY= 6;
//shoulder buttons
const uint8_t Pin_ButtonLB= 7;
const uint8_t Pin_ButtonRB= 8;
const uint8_t Pin_TriggerL= 11;
const uint8_t Pin_TriggerR= 12;
//dpad buttons
const uint8_t Pin_DpadL= 2;
const uint8_t Pin_DpadR= A0;
const uint8_t Pin_DpadU= 0;
const uint8_t Pin_DpadD= 1;
//other buttons
const uint8_t Pin_ButtonStart= 9;
const uint8_t Pin_ButtonBack= 10;

const uint8_t Pin_LED = LED_BUILTIN;

const int AnalogRead_Max = 1023;

void setup() {
  pinMode(Pin_ButtonA, INPUT_PULLUP);
  pinMode(Pin_ButtonB, INPUT_PULLUP);
  pinMode(Pin_ButtonX, INPUT_PULLUP);
  pinMode(Pin_ButtonLB, INPUT_PULLUP);
  pinMode(Pin_ButtonRB, INPUT_PULLUP);
  pinMode(Pin_ButtonStart, INPUT_PULLUP);
  pinMode(Pin_ButtonBack, INPUT_PULLUP);
  pinMode(Pin_TriggerL, INPUT_PULLUP);
  pinMode(Pin_TriggerR, INPUT_PULLUP);
  pinMode(Pin_DpadL, INPUT_PULLUP);
  pinMode(Pin_DpadR, INPUT_PULLUP);
  pinMode(Pin_DpadU, INPUT_PULLUP);
  pinMode(Pin_DpadD, INPUT_PULLUP);
  
  pinMode(Pin_LED, OUTPUT);
  digitalWrite(Pin_LED, LOW);

  XInput.setRange(JOY_LEFT, 0, AnalogRead_Max);
  XInput.setRange(JOY_RIGHT, 0, AnalogRead_Max);
  XInput.begin();
}

void loop() {
  boolean pressA =!digitalRead(Pin_ButtonA);
  boolean pressB =!digitalRead(Pin_ButtonB);
  boolean pressX =!digitalRead(Pin_ButtonX);
  boolean pressY =!digitalRead(Pin_ButtonY);
  boolean pressLB =!digitalRead(Pin_ButtonLB);
  boolean pressRB =!digitalRead(Pin_ButtonRB);
  boolean pressStart =!digitalRead(Pin_ButtonStart);
  boolean pressBack =!digitalRead(Pin_ButtonBack);
  boolean pressTriggerL=!digitalRead(Pin_TriggerL);
  boolean pressTriggerR =!digitalRead(Pin_TriggerR);
  boolean pressDpadL=!digitalRead(Pin_DpadL);
  boolean pressDpadR =!digitalRead(Pin_DpadR);
  boolean pressDpadU=!digitalRead(Pin_DpadU);
  boolean pressDpadD =!digitalRead(Pin_DpadD);

  int joystickLXValue = analogRead(Pin_JoystickLX);
  int joystickLYValue = analogRead(Pin_JoystickLY);
  int joystickRXValue = analogRead(Pin_JoystickRX);
  int joystickRYValue = analogRead(Pin_JoystickRY);
  joystickRXValue = AnalogRead_Max - joystickRXValue;
  joystickRYValue = AnalogRead_Max - joystickRYValue;

  XInput.setButton(BUTTON_A, pressA);
  XInput.setButton(BUTTON_B, pressB);
  XInput.setButton(BUTTON_X, pressX);
  XInput.setButton(BUTTON_Y, pressY);
  XInput.setButton(BUTTON_LB, pressLB);
  XInput.setButton(BUTTON_RB, pressRB);
  XInput.setButton(BUTTON_START, pressStart);
  XInput.setButton(BUTTON_BACK, pressBack); 
  XInput.setButton(TRIGGER_LEFT, pressTriggerL);
  XInput.setButton(TRIGGER_RIGHT, pressTriggerR);  
  XInput.setButton(DPAD_LEFT, pressDpadL);
  XInput.setButton(DPAD_RIGHT, pressDpadR);   
  XInput.setButton(DPAD_UP, pressDpadU);
  XInput.setButton(DPAD_DOWN, pressDpadD);    


    
  
  XInput.setJoystick(JOY_LEFT, joystickLXValue, joystickLYValue);
  XInput.setJoystick(JOY_RIGHT, joystickRXValue, joystickRYValue);
}
