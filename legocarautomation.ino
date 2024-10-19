// motor A
int motorA1 = 5;
int motorA2 = 6;
//motor B
int motorB1 = 7;
int motorB2 = 8;

// Define ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// Variables to store distance
long duration;
int distance;

void setup() {
  // Set motor pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Begin serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Get distance from ultrasonic sensor
  distance = getDistance();

  // If the distance is more than 3 cm, move forward
  if (distance > 3) {
    moveForward();
  }
  // If the distance is 3 cm or less, stop the car
  else {
    stopCar();
  }
  
  // Small delay to avoid excessive readings
  delay(100);
}

int getDistance() {
  // Send a 10us pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the pulse duration from the echo pin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance (duration in microseconds, speed of sound is 34300 cm/s)
  return duration * 0.034 / 2;
}

void moveForward() {
  // Turn on motors to move forward
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void stopCar() {
  // Turn off motors
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
