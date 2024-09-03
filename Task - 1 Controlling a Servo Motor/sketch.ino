#include <Servo.h>

int servoPin = 9;        
int ledPin = 10;          
int servoPos = 0;        
Servo PMVservo;          

void setup() {
  Serial.begin(9600);           
  PMVservo.attach(servoPin);    
  pinMode(ledPin, OUTPUT);      
  Serial.println("Enter a servo angle between 0 and 180:");
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    // Read the input as an integer
    int inputAngle = Serial.parseInt();

    if (inputAngle >= 0 && inputAngle <= 180) {
      servoPos = inputAngle;
      PMVservo.write(servoPos);  
      Serial.print("Servo moved to: ");
      Serial.println(servoPos);
      
      int ledBrightness = map(servoPos, 0, 180, 0, 255);
      analogWrite(ledPin, ledBrightness); 
    } else {
      Serial.println("Please enter a value between 0 and 180.");
    }
  }
}
