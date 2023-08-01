const int Y_STEP_PIN    =     60 ;
const int Y_DIR_PIN      =    61 ;
const int Y_ENABLE_PIN    =   56 ;
const int X_STEP_PIN    =     54 ;
const int X_DIR_PIN      =    55 ;
const int X_ENABLE_PIN    =   38 ;
const int Z_STEP_PIN    =     46 ;
const int Z_DIR_PIN      =    48 ;
const int Z_ENABLE_PIN    =   62 ;
const int Y_MIN_PIN       =  14 ;
const int Y_MAX_PIN       =  15 ;
const int X_MIN_PIN         = 3 ;
const int X_MAX_PIN         = 2 ;
const int Z_MIN_PIN         = 18 ;
const int Z_MAX_PIN         = 19 ;


void setup()
{
  // Declare pins as Outputs
  Serial.begin(9600);
  pinMode(Y_STEP_PIN , OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(X_STEP_PIN , OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(Z_STEP_PIN , OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Y_MIN_PIN  , INPUT_PULLUP);
  pinMode(Y_MAX_PIN  , INPUT_PULLUP);
  pinMode(X_MIN_PIN  , INPUT_PULLUP);
  pinMode(X_MAX_PIN  , INPUT_PULLUP);
  pinMode(Z_MIN_PIN  , INPUT_PULLUP);
  pinMode(Z_MAX_PIN  , INPUT_PULLUP);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Y_DIR_PIN, HIGH);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(X_DIR_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(Z_DIR_PIN, LOW);  
}
void loop()
{
int y_dis_taraf = digitalRead(Y_MIN_PIN);
int x_dis_taraf = digitalRead(X_MIN_PIN);
int y_ic_taraf = digitalRead(Y_MAX_PIN);
int x_ic_taraf = digitalRead(X_MAX_PIN);
int Z_UST_taraf = digitalRead(Z_MAX_PIN);
int Z_ALT_taraf = digitalRead(Z_MIN_PIN);

  if ((digitalRead(Y_DIR_PIN) == HIGH) && (y_dis_taraf == LOW))
  {
    digitalWrite(Y_STEP_PIN, HIGH);
		delayMicroseconds(200);
		digitalWrite(Y_STEP_PIN, LOW);
		delayMicroseconds(200);
  }
  if ((digitalRead(X_DIR_PIN) == LOW) && (x_dis_taraf == LOW))
  {
    digitalWrite(X_STEP_PIN, HIGH);
		delayMicroseconds(200);
		digitalWrite(X_STEP_PIN, LOW);
		delayMicroseconds(200);
  }
  else if ((digitalRead(Y_DIR_PIN) == HIGH) && (digitalRead(X_DIR_PIN) == LOW) && (y_dis_taraf == HIGH) && (x_dis_taraf == HIGH))
  {
      digitalWrite(Y_DIR_PIN, LOW);
      digitalWrite(X_DIR_PIN, HIGH);
  }
  if ((digitalRead(X_DIR_PIN) == HIGH) && (digitalRead(Y_DIR_PIN) == LOW))
  {
     digitalWrite(X_STEP_PIN, HIGH);
     digitalWrite(Y_STEP_PIN, HIGH);
		 delayMicroseconds(200);
		 digitalWrite(X_STEP_PIN, LOW);
     digitalWrite(Y_STEP_PIN, LOW);
		 delayMicroseconds(200);
  }
  if ((Z_UST_taraf == LOW))
  {
    digitalWrite(Z_STEP_PIN, HIGH);
		delayMicroseconds(100);
		digitalWrite(Z_STEP_PIN, LOW);
		delayMicroseconds(100);
  }
  else if ((Z_UST_taraf == HIGH))
  {
    digitalWrite(Z_DIR_PIN, HIGH);
  }
  if ((digitalRead(Z_DIR_PIN) == HIGH) && (Z_UST_taraf == HIGH) && (y_ic_taraf == HIGH) && (x_ic_taraf == HIGH))
  {
    digitalWrite(Z_STEP_PIN, HIGH);
		delayMicroseconds(100);
		digitalWrite(Z_STEP_PIN, LOW);
		delayMicroseconds(100);
  }
  }
