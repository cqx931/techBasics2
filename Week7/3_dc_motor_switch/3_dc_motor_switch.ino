/**
Example to control a DC Motor
with potentiometer to control speed
and a button as toggle switch
**/

const int motorPin = 3; // for pwm ~
const int buttonPin = 2;
const int potPin = A0;
int pwmValue;

bool previous_state = 1;
bool isOn = false;

void setup(){
  pinMode(motorPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  int buttonValue = digitalRead(buttonPin);
  Serial.println(buttonValue);

  if (buttonValue && previous_state == 0) { // on button release
    isOn = !isOn; // toggle on/off
  }

  if(isOn) {
    int reading = analogRead(A0);
    pwmValue = map(reading, 0,1024,128,255);
    analogWrite(motorPin,
  } else {
    digitalWrite(motorPin, LOW);
  }
  
  previous_state = buttonValue;
}