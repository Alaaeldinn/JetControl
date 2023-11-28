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
  if (frontLeftSpeed > 0) {
    digitalWrite(frontLeftMotorPin1, HIGH);
    digitalWrite(frontLeftMotorPin2, LOW);
  } else if (frontLeftSpeed < 0) {
    digitalWrite(frontLeftMotorPin1, LOW);
    digitalWrite(frontLeftMotorPin2, HIGH);
  } else {
    digitalWrite(frontLeftMotorPin1, LOW);
    digitalWrite(frontLeftMotorPin2, LOW);
  }

  // Control front right motor
  if (frontRightSpeed > 0) {
    digitalWrite(frontRightMotorPin1, HIGH);
    digitalWrite(frontRightMotorPin2, LOW);
  } else if (frontRightSpeed < 0) {
    digitalWrite(frontRightMotorPin1, LOW);
    digitalWrite(frontRightMotorPin2, HIGH);
  } else {
    digitalWrite(frontRightMotorPin1, LOW);
    digitalWrite(frontRightMotorPin2, LOW);
  }

  // Control rear left motor
  if (rearLeftSpeed > 0) {
    digitalWrite(rearLeftMotorPin1, HIGH);
    digitalWrite(rearLeftMotorPin2, LOW);
  } else if (rearLeftSpeed < 0) {
    digitalWrite(rearLeftMotorPin1, LOW);
    digitalWrite(rearLeftMotorPin2, HIGH);
  } else {
    digitalWrite(rearLeftMotorPin1, LOW);
    digitalWrite(rearLeftMotorPin2, LOW);
  }

  // Control rear right motor
  if (rearRightSpeed > 0) {
    digitalWrite(rearRightMotorPin1, HIGH);
    digitalWrite(rearRightMotorPin2, LOW);
  } else if (rearRightSpeed < 0) {
    digitalWrite(rearRightMotorPin1, LOW);
    digitalWrite(rearRightMotorPin2, HIGH);
  } else {
    digitalWrite(rearRightMotorPin1, LOW);
    digitalWrite(rearRightMotorPin2, LOW);
  }
}
