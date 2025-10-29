/*
Use Serial.readString() to control on-board LED
* use Serial.parseInt() for integer
*/

int readingValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  delay(1000); // wait for serial to be created
  Serial.println("Type either on or off:");
}

void loop() {

  if(Serial.available()) {     // wait for data available

    String str = Serial.readString();  // read until timeout

    str.trim();                        // remove any \r \n whitespace at the end of the String
    
    Serial.print("Data Input: ");
    Serial.println(str);

    if (str == "on") {
      digitalWrite(13, HIGH);
    } else if (str == "off") {
      digitalWrite(13, LOW);
    } else {
      Serial.println("Wrong value, try again");
    }
  }

}