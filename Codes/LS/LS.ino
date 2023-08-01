int LS1 = 17;
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(LS1, INPUT_PULLUP);
  pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN    , OUTPUT);
  digitalWrite(X_ENABLE_PIN    , LOW);
  
}

void loop() {
  //if (millis() %2000 <1000) {
int val=0;
val=digitalRead(LS1);
  if (digitalRead(X_DIR_PIN)==1){
    if (val==1){
    delay(500);
    digitalWrite(X_DIR_PIN    , LOW);
    //delay(500);
    }
  }
 else {
  if (digitalRead(X_DIR_PIN)==0){
    if (val==1){
    delay(500);
    digitalWrite(X_DIR_PIN    , HIGH);
    //delay(500);
    }
  }
  
  }

  digitalWrite(X_STEP_PIN    , HIGH);
  delayMicroseconds(1000);
  digitalWrite(X_STEP_PIN    , LOW);
  
  //Serial.print("DIR ");Serial.print(digitalRead(X_DIR_PIN));
  //Serial.print("   LS1 ");Serial.println(digitalRead(LS1));
  
  //Serial.println(digitalRead(LS1));
  //delay(5);  // delay in between reads for stability
  }
