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
const int eight_KG_MAGNETS       = 10 ;
const int thee_KG_MAGNET        = 9 ; //24V
const int PISTON_MAGNET      = 8 ; //24V

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
  pinMode(eight_KG_MAGNETS, OUTPUT);
  pinMode(thee_KG_MAGNET , OUTPUT);
  pinMode(PISTON_MAGNET , OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Y_DIR_PIN, HIGH);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(X_DIR_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(Z_DIR_PIN, LOW); 
  digitalWrite(eight_KG_MAGNETS, LOW);
  digitalWrite(thee_KG_MAGNET, LOW);
  digitalWrite(PISTON_MAGNET, LOW);
  
}
void loop()
{
int y_dis_taraf = digitalRead(Y_MIN_PIN);
int x_dis_taraf = digitalRead(X_MIN_PIN);
int y_ic_taraf = digitalRead(Y_MAX_PIN);
int x_ic_taraf = digitalRead(X_MAX_PIN);
int Z_UST_taraf = digitalRead(Z_MAX_PIN);
int Z_ALT_taraf = digitalRead(Z_MIN_PIN);
int x = 0;

while (x == 0) {
  if ((digitalRead(Y_DIR_PIN) == HIGH) && (x_dis_taraf == LOW))
  {
    digitalWrite(Y_STEP_PIN, HIGH);
		delayMicroseconds(50);
		digitalWrite(Y_STEP_PIN, LOW);
		delayMicroseconds(50);
  }
  if ((digitalRead(X_DIR_PIN) == LOW) && (y_dis_taraf == LOW))
  {
    digitalWrite(X_STEP_PIN, HIGH);
		delayMicroseconds(50);
		digitalWrite(X_STEP_PIN, LOW);
		delayMicroseconds(50);
  }
  if ((digitalRead(Y_DIR_PIN) == HIGH) && (digitalRead(X_DIR_PIN) == LOW) && (y_dis_taraf == HIGH) && (x_dis_taraf == HIGH) && (digitalRead(Z_DIR_PIN) == HIGH) && (digitalRead(eight_KG_MAGNETS) == LOW) && (digitalRead(thee_KG_MAGNET) == LOW))
  {
      digitalWrite(Y_DIR_PIN, LOW);
      digitalWrite(X_DIR_PIN, HIGH);
  }
    if ((digitalRead(Y_DIR_PIN) == LOW) && (x_ic_taraf == LOW))
  {
     digitalWrite(Y_STEP_PIN, HIGH);
		 delayMicroseconds(50);
     digitalWrite(Y_STEP_PIN, LOW);
		 delayMicroseconds(50);
  }
  if ((digitalRead(X_DIR_PIN) == HIGH) && (y_ic_taraf == LOW))
  {
     digitalWrite(X_STEP_PIN, HIGH);
		 delayMicroseconds(50);
		 digitalWrite(X_STEP_PIN, LOW);
		 delayMicroseconds(50);
  }
  if ((Z_UST_taraf == LOW) && (digitalRead(eight_KG_MAGNETS) == LOW) && (digitalRead(thee_KG_MAGNET) == LOW)) 
  {
    delay(1); 
    digitalWrite(Z_STEP_PIN, HIGH);
		delayMicroseconds(10);
    delay(1);
		digitalWrite(Z_STEP_PIN, LOW);
    delayMicroseconds(10);
  }
  if ((Z_UST_taraf == HIGH))
  {
    digitalWrite(Z_DIR_PIN, HIGH);
  }
  // BAŞLANGIÇ DURUMU KODUNUN SONU

  if ((digitalRead(Z_DIR_PIN) == HIGH) && (Z_UST_taraf == HIGH) && (y_ic_taraf == HIGH) && (x_ic_taraf == HIGH))
  {
    delay(1);
    digitalWrite(thee_KG_MAGNET, HIGH);
    delayMicroseconds(10000000);
    digitalWrite(eight_KG_MAGNETS, HIGH);
    delayMicroseconds(10000000);
    digitalWrite(Y_DIR_PIN, HIGH);
    digitalWrite(X_DIR_PIN, LOW);  
  }

  if ((y_dis_taraf == HIGH) && (x_dis_taraf == HIGH) && (Z_ALT_taraf == LOW) && (digitalRead(eight_KG_MAGNETS) == HIGH) && (digitalRead(thee_KG_MAGNET) == HIGH))
  {
    delay(1);
    digitalWrite(Z_STEP_PIN, HIGH);
		delayMicroseconds(10);
		digitalWrite(Z_STEP_PIN, LOW);
		delayMicroseconds(10);
  }
    if ((Z_ALT_taraf == HIGH))
  {
    digitalWrite(Z_DIR_PIN, LOW);
  }
    if ((digitalRead(eight_KG_MAGNETS) == HIGH) && (digitalRead(thee_KG_MAGNET) == HIGH)  && (y_dis_taraf == HIGH) && (x_dis_taraf == HIGH) && (Z_ALT_taraf == HIGH))
  {
      digitalWrite(Y_DIR_PIN, LOW);
      digitalWrite(X_DIR_PIN, HIGH);
  }
  if ((digitalRead(eight_KG_MAGNETS) == HIGH) && (digitalRead(thee_KG_MAGNET) == HIGH)  && (y_dis_taraf == HIGH) && (x_dis_taraf == HIGH) && (Z_ALT_taraf == HIGH) && (digitalRead(X_DIR_PIN) == HIGH) && (digitalRead(Y_DIR_PIN) == LOW))
  {
    x = 1;
  }
}
while (x == 1)
{
  if ((digitalRead(X_DIR_PIN) == HIGH) && (y_ic_taraf == LOW))
  {
     digitalWrite(X_STEP_PIN, HIGH);
		 delayMicroseconds(50);
		 digitalWrite(X_STEP_PIN, LOW);
		 delayMicroseconds(50);
  }
}
 }