const int in1 = 7;
const int in2 = 4;
const int in3 = 5;
const int in4 = 6;
const int ENA = 9;
const int ENB = 8;

const int trig = 3;
const int echo = 2;


const int leftIR  = A5;
const int rightIR = A0;


const int NUM_READINGS      = 5;
const int MOTOR_SPEED       = 255;
const int IR_THRESHOLD      = 150;
const int OBSTACLE_DISTANCE = 50;


long duration;
int distance;
int readings[NUM_READINGS];
int indexReading = 0;


void moveForward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnLeft() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(ENA, 0);
  analogWrite(ENB, MOTOR_SPEED);
}

void turnRight() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, 0);
}


int measureDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH, 30000);
  if (duration == 0) return 0;

  return (duration * 0.034) / 2;
}


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  for (int i = 0; i < NUM_READINGS; i++) readings[i] = 0;

  Serial.begin(9600);
}


void loop() {
  int leftValue  = analogRead(leftIR);
  int rightValue = analogRead(rightIR);

  bool leftBlack  = leftValue  < IR_THRESHOLD;
  bool rightBlack = rightValue < IR_THRESHOLD;

  readings[indexReading] = measureDistance();
  indexReading = (indexReading + 1) % NUM_READINGS;

  long sum = 0;
  for (int i = 0; i < NUM_READINGS; i++) sum += readings[i];
  distance = sum / NUM_READINGS;

  Serial.print("Left IR: ");
  Serial.print(leftValue);
  Serial.print("\tRight IR: ");
  Serial.print(rightValue);
  Serial.print("\tDistance: ");
  Serial.println(distance);

  if (distance > 0 && distance < OBSTACLE_DISTANCE) {
    stopMotors();
    return;
  }

  if (leftBlack && rightBlack) {
    moveForward();      
  }
 else if (leftBlack && !rightBlack) {
    turnLeft();         
  }
  else if (!leftBlack && rightBlack) {
   turnRight();        
  }
  else {
    stopMotors();      
  }
}
