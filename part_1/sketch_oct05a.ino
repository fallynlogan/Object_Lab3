//Fallyn Logan
//object lab 3 part 1 
//10-8-19
int potentiometer = 0;
int photoResistor = 0;
int potPin = A0;
int photoPin = A1;
int redLED = 9;
int yellowLED = 10;
int redBrightness = 0;
int yellowBrightness = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  potentiometer = analogRead(potPin);
  photoResistor = analogRead(photoPin);

  redBrightness = map(potentiometer, 0, 1023, 0, 255);
  analogWrite(redLED, redBrightness);
  analogWrite(yellowLED, yellowBrightness);

  if(photoResistor < 600){
    yellowBrightness = map(photoResistor, 43, 796, 0, 255);
    analogWrite(yellowLED, yellowBrightness);
  }
  else{
    yellowBrightness = map(photoResistor, 0, 0, 0, 0);
  }

  Serial.print("photoResistor value: ");
  Serial.println(photoResistor);
  Serial.println("yellowLED brightness: ");
  Serial.print(yellowBrightness);

}
