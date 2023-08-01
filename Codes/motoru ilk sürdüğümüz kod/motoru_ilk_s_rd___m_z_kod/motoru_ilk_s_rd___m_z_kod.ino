#define dirPin 2
#define stepPin 5
#define stepsPerRevolution 6400 // çözünürlük 32'de, 10 voltta güç kaynağı, 0.5ampere sabitledik

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // Set the spinning direction clockwise:
  digitalWrite(dirPin, LOW);

  // Spin the stepper motor 0.5 revolution :
  for (int i = 0; i < 4 * stepsPerRevolution; i++) { // tur sayısını burdan hesaplıyoruz
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(50); // hız (arttıkça hızı azalıyor, en hızlı 9.)
    digitalWrite(stepPin, LOW);
    delayMicroseconds(50); // hız (arttıkça hızı azalıyor, en hızlı 9.)
  }
    // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 0.5 revolution :
  for (int i = 0; i < 4 * stepsPerRevolution; i++) { // tur sayısını burdan hesaplıyoruz
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(50); // hız (arttıkça hızı azalıyor, en hızlı 9.)
    digitalWrite(stepPin, LOW);
    delayMicroseconds(50); // hız (arttıkça hızı azalıyor, en hızlı 9.)
  }
}
