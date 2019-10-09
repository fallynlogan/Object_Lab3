//Fallyn Logan 10-8-19
//object lab part 3
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// pin that the strip is connected to
#define PIN 7

Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 7, NEO_GRB + NEO_KHZ800);
int photo1 = 0; //stores value of light in photoresisitor circuit 1
int photo2 = 0;//stores values being brouhg
t in from photo circuit 2

int photoPin1 = A5; //analog input 
int photoPin2 = A4;          


float sound = 0; // frequency variable 
int speakerPin = 8; //speaker output

int potentiometer = 0;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  // initialize the strip
  strip.begin();
  // sets all pixels to 'off'
  strip.show(); 

  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  potentiometer = analogRead(potPin);
  photo1 = analogRead(photoPin1);
  photo2 = analogRead(photoPin2);
  
  Serial.print("range: ");
  Serial.println(potentiometer);
  //circuit 1
  if(200 <= photo1 && photo1<=300 ){
  sound = map(photo1, 80, 919, 100, 1000);
  tone(8,sound);
  }
  if(750 <= photo1 && photo1<=850 ){
  sound = map(photo1, 80, 919, 100, 1000);
  tone(8,sound);
  }
  //second circuit
    if(200 <= photo2 && photo2<=300 ){
  sound = map(photo2, 80, 919, 100, 1000);
  tone(8,sound);
  }
  if(750 <= photo2 && photo2<=850 ){
  sound = map(photo2, 80, 919, 100, 1000);
  tone(8,sound);
  }

  if(300 < photo1 && 300 < photo2 && photo1 < 750 && photo2 < 750){
     sound = map(photo2, 0, 0, 0, 0);
  noTone(8);
  }
  
//red
  if(potentiometer < 100){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 255, 0, 0);
      strip.show();
      //delay(500);
    }
  }
  //orange
  if(100 <= potentiometer && potentiometer < 200){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 255, 115, 0);
      strip.show();
      //delay(500);
    }
     
  }
  //yellow
  if(200 <= potentiometer && potentiometer < 300){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 255, 255, 0);
      strip.show();
      //delay(500);
    }
     
  }
  //green
    if(400 <= potentiometer && potentiometer < 500){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 0, 255, 0);
      strip.show();
      //delay(500);
    }
     
  }
  
  //blue
    if(500 <= potentiometer && potentiometer < 600){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 0, 0, 255);
      strip.show();
      //delay(500);
    }
     
  }
  
  //indigo
    if(600 <= potentiometer && potentiometer < 700){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 75, 0, 130);
      strip.show();
      //delay(500);
    }
     
  }
  
  //violet
    if(700 <= potentiometer && potentiometer < 800){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 238, 130, 238);
      strip.show();
      //delay(500);
    }
     
  }

}
  
