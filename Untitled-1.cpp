#include <Servo.h> // Include the Servo library

Servo servo1; // Create a servo object called servo1

const int flexPin = A0; // Define the analog input pin for the flex sensor
const float VCC = 5.08; // Define the supply voltage (VCC) as 5.08V (Measured)

void setup() { 
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  servo1.attach(9);    // Attach the servo to pin 9
} 

void loop() 
{ 
  
  int flexPosition;    // Variable to hold the flex sensor reading
  int servoPosition;   // Variable to hold the servo position

  // Read the position of the flex sensor (0 to 1023):
  flexPosition = analogRead(flexPin);

  // Convert analog value to voltage:
  float voltage = flexPosition * (VCC / 1023.0);

  // Map the flex position to a servo angle (0 to 180 degrees):
  servoPosition = map(flexPosition, 750, 940, 0, 180); //Analog value for this sensor is approx 750-940
  servoPosition = constrain(servoPosition, 0, 180);

  // Command the servo to move to the calculated position:
  servo1.write(servoPosition);

  // Print flex sensor position, voltage, and servo angle to the Serial Monitor:
  Serial.print("Flex Position: ");
  Serial.print(flexPosition);

  Serial.print("  Voltage (V): ");
  Serial.print(voltage);

  Serial.print("  Servo Angle: ");
  Serial.println(servoPosition);

  delay(20); // Delay for readability and servo response
}