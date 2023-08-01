const int Z_STEP_PIN    =     46 ;
const int Z_DIR_PIN      =    48 ;
const int Z_ENABLE_PIN    =   62 ;
void setup()
{
  Serial.begin(9600);
  pinMode(Z_STEP_PIN , OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(Z_DIR_PIN, LOW); 

}
void loop()
{
  if ((digitalRead(Z_DIR_PIN) == LOW))
  {
  delay(1);
  digitalWrite(Z_STEP_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(Z_STEP_PIN, LOW);
  delayMicroseconds(10); 
  }
}