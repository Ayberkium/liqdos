const int Z_STEP_PIN    =     46 ;
const int Z_DIR_PIN      =    48 ;
const int Z_ENABLE_PIN    =   62 ;
const int Z_MIN_PIN        =  18 ;
const int Z_MAX_PIN        = 19 ;


void setup()
{
  // Declare pins as Outputs
  Serial.begin(9600);
  pinMode(Z_STEP_PIN , OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_MIN_PIN , INPUT_PULLUP);
  pinMode(Z_MAX_PIN , INPUT_PULLUP);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(Z_DIR_PIN, HIGH);
}
void loop()
{
  int fwdend = digitalRead(Z_MIN_PIN);
  int backend = digitalRead(Z_MAX_PIN);
  if (fwdend == LOW ) {
    digitalWrite(Z_STEP_PIN  , HIGH);
    delayMicroseconds(50);
    digitalWrite(Z_STEP_PIN  , LOW);
    delayMicroseconds(50);
  } else if (fwdend == HIGH ) {
    digitalWrite(Z_DIR_PIN, LOW);
  }
  if ((backend == LOW ) && (digitalRead(Z_DIR_PIN) == LOW)) {
    digitalWrite(Z_STEP_PIN  , HIGH);
    delayMicroseconds(50);
    digitalWrite(Z_STEP_PIN  , LOW);
    delayMicroseconds(50);
  } else if ((backend == HIGH ) && (digitalRead(Z_DIR_PIN) == LOW)) {
    digitalWrite(Z_DIR_PIN, HIGH);
   // delayMicroseconds(5000);
  }
}
