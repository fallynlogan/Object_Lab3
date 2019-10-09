//Fallyn Logan 10-8-19
//object lab part 2
int photoResistor = 0;
int sensorPin = A0;
float sound =0;
int speakerPin = 8;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  photoResistor = analogRead(sensorPin);

  Serial.println(photoResistor);

  sound = map(photoResistor, 80, 919, 100, 1000);

  tone(8,sound);
  delay(500);

}
