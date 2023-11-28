#include <Arduino.h>

// Define motor control pins
const int frontLeftMotorPin1 = 2;
const int frontLeftMotorPin2 = 3;
const int frontRightMotorPin1 = 4;
const int frontRightMotorPin2 = 5;
const int rearLeftMotorPin1 = 6;
const int rearLeftMotorPin2 = 7;
const int rearRightMotorPin1 = 8;
const int rearRightMotorPin2 = 9;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set motor control pins as outputs
  pinMode(frontLeftMotorPin1, OUTPUT);
  pinMode(frontLeftMotorPin2, OUTPUT);
  pinMode(frontRightMotorPin1, OUTPUT);
  pinMode(frontRightMotorPin2, OUTPUT);
  pinMode(rearLeftMotorPin1, OUTPUT);
  pinMode(rearLeftMotorPin2, OUTPUT);
  pinMode(rearRightMotorPin1, OUTPUT);
  pinMode(rearRightMotorPin2, OUTPUT);
}

void loop() {
  // Check if data is available to read from serial
  if (Serial.available() > 0) {
    // Read the command from serial
    String command = Serial.readStringUntil('\n');

    // Parse the command and control motors
    int frontLeftSpeed = command.substring(2, 5).toInt();
    int frontRightSpeed = command.substring(7, 10).toInt();
    int rearLeftSpeed = command.substring(12, 15).toInt();
    int rearRightSpeed = command.substring(18, 21).toInt();

    controlMotors(frontLeftSpeed, frontRightSpeed, rearLeftSpeed, rearRightSpeed);
  }
}

// Function to control motors based on speed values
void controlMotors(int frontLeftSpeed, int frontRightSpeed, int rearLeftSpeed, int rearRightSpeed) {
  // Control front left motor
  digitalWrite(frontLeftMotorPin1, (frontLeftSpeed > 0) ? HIGH : LOW);
  digitalWrite(frontLeftMotorPin2, (frontLeftSpeed < 0) ? HIGH : LOW);

  // Control front right motor
  digitalWrite(frontRightMotorPin1, (frontRightSpeed > 0) ? HIGH : LOW);
  digitalWrite(frontRightMotorPin2, (frontRightSpeed < 0) ? HIGH : LOW);

  // Control rear left motor
  digitalWrite(rearLeftMotorPin1, (rearLeftSpeed > 0) ? HIGH : LOW);
  digitalWrite(rearLeftMotorPin2, (rearLeftSpeed < 0) ? HIGH : LOW);

  // Control rear right motor
  digitalWrite(rearRightMotorPin1, (rearRightSpeed > 0) ? HIGH : LOW);
  digitalWrite(rearRightMotorPin2, (rearRightSpeed < 0) ? HIGH : LOW);
}
