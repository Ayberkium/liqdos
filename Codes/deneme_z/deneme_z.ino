
#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

void setup() {
  Serial.begin(9600);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);
//  pinMode(Z_MIN_PIN, INPUT_PULLUP);
  pinMode(Z_STEP_PIN  , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN    , OUTPUT);
  digitalWrite(Z_ENABLE_PIN    , LOW);

}

void loop() {
 int val=0;
val=digitalRead(Z_MAX_PIN);
  if (digitalRead(Z_DIR_PIN)==1){
    if (val==1){
    delay(500);
    digitalWrite(Z_DIR_PIN    , LOW);
    //delay(500);
    }
}
 else {
  if (digitalRead(Z_DIR_PIN)==0){
    if (val==1){
    delay(500);
    digitalWrite(Z_DIR_PIN    , HIGH);
    }
  }

//  int val1=0;
//val1=digitalRead(Z_MIN_PIN);
//  if (digitalRead(Z_DIR_PIN)==1){
//    if (val1==1){
//    delay(500);
//    digitalWrite(Z_DIR_PIN    , LOW);
//    //delay(500);
//    }
//}
// else {
//  if (digitalRead(Z_DIR_PIN)==0){
//    if (val1==1){
//    delay(500);
//    digitalWrite(Z_DIR_PIN    , HIGH);
//    }
//  }
//  
//  }

  digitalWrite(Z_STEP_PIN    , HIGH);
  delayMicroseconds(100);
  digitalWrite(Z_STEP_PIN    , LOW);
}
}
