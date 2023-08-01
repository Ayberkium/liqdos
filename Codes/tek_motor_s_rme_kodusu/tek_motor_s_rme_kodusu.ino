const int stepPin = 5; 
const int dirPin = 2; 
const int enPin = 8;


#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2
void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
}

void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(50); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(50); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the direction of rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(50);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(50);
  }
  delay(1000); 
}
