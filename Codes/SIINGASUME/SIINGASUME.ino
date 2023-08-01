const int E0_STEP_PIN     =   26 ;
const int E0_DIR_PIN       =  28 ;
const int E0_ENABLE_PIN    =  24 ;
const int E_MIN_PIN         = 53 ;
const int E_MAX_PIN         = 40 ;

void setup()
{
  Serial.begin(9600);
  pinMode(E0_STEP_PIN , OUTPUT);
  pinMode(E0_DIR_PIN, OUTPUT);
  pinMode(E0_ENABLE_PIN, OUTPUT);
  pinMode(E_MIN_PIN  , INPUT_PULLUP);
  pinMode(E_MAX_PIN  , INPUT_PULLUP);
  digitalWrite(E0_ENABLE_PIN, LOW);
  digitalWrite(E0_DIR_PIN, HIGH);
}
void loop()
{
int E_UST_taraf = digitalRead(E_MAX_PIN);
int E_ALT_taraf = digitalRead(E_MIN_PIN);
 if (E_ALT_taraf == LOW ) {
    delay(1);
    digitalWrite(E0_STEP_PIN  , HIGH);
    delayMicroseconds(50);
    digitalWrite(E0_STEP_PIN  , LOW);
    delayMicroseconds(50);
  } 
  if (E_ALT_taraf == HIGH ) {
    digitalWrite(E0_DIR_PIN, HIGH);
  }
  if ((E_UST_taraf == LOW ) && (digitalRead(E0_DIR_PIN) == LOW)) {
    delay(1);
    digitalWrite(E0_STEP_PIN  , HIGH);
    delayMicroseconds(50);
    digitalWrite(E0_STEP_PIN  , LOW);
    delayMicroseconds(50);
  } 
   if ((E_UST_taraf == HIGH ) && (digitalRead(E0_DIR_PIN) == LOW)) {
    digitalWrite(E0_DIR_PIN, HIGH);
   // delayMicroseconds(5000);
  }
}
