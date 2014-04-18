//~~~~Flynntes.me/WeHub~~~~~~//

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
int ledPin = 13; 
int state = 0;
int flag = 0; 
 
void setup() {
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
 Serial.begin(9600);
 
 dht.begin();
}
 
void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
   
 }

 if(Serial.available() > 0){
 state = Serial.read();
 flag=0;
 }

 if (state == '0') {
 digitalWrite(ledPin, LOW);
 if(flag == 0){
 Serial.println("WeHub: OFF");
 flag = 1;
 }
 }

 else if (state == '1') {
 Serial.println("WeHub: ON");
 digitalWrite(ledPin, HIGH);
 if(flag == 0){
 Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
 flag = 1;
 }
 }
}
