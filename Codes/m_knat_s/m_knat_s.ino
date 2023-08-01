//NC şeklinde bağlandığında  LS e değdiğinde mıknatıs çalışıyor
#define EM         32
#define LS1         16




void setup() {
  Serial.begin(9600);
  pinMode(LS1, INPUT_PULLUP);
  pinMode(EM  , OUTPUT);

  
}

void loop() {
  
 int val=0;
val=digitalRead(LS1);

if (val==1) {
  digitalWrite(EM    , HIGH);
}
 else {
  digitalWrite(EM , LOW);
}
 

}
