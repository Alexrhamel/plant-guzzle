#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int val = 0;
const int soilPin = A0;
const int soilPower = 7;

int val2 = 0;
const int lightPin = A1;
const int lightPower = 8;

float value1;
float value2;
float value3;

int motorPin = 9;

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11");
  Serial.println("Light Snesor");
  Serial.println("Soil Humidity Snesor");

  dht.begin();

  pinMode(soilPower, OUTPUT);
  digitalWrite(soilPower, LOW);

  pinMode(lightPower, OUTPUT);
  digitalWrite(lightPower, LOW);

  pinMode(motorPin, OUTPUT);
}


void loop() {
  delay(2000);
  value1 = tempHumid();
  value2 = soilRead();
  value3 = lightRead();

  Serial.print(value1);
  Serial.print(" ");
  Serial.print(value2);
  Serial.print(" ");
  Serial.println(value3);

  //  int butread = digitalRead(buttonPin);
  //  if (value2 > 600){
  //    motorGo();
  //  }
}


float tempHumid() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);
  return t;
}


float soilRead() {
  digitalWrite(soilPower, HIGH);
  delay(10);
  val = analogRead(soilPin);
  digitalWrite(soilPower, LOW);
  return val;
}


float lightRead() {
  digitalWrite(lightPower, HIGH);
  delay(10);
  val2 = analogRead(lightPin);
  digitalWrite(lightPower, LOW);
  return val2;
}

void motorGo() {
  int onTime = 2500;
  int offTime = 1000;

  digitalWrite(motorPin, HIGH);
  delay(onTime);
  digitalWrite(motorPin, LOW);
}
