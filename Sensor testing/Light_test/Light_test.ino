

int val = 0; //value for storing light value 
int lightPin = A0;//Declare a variable for the light sensor 
int soilPower = 7;//Variable for light Power


void setup() 
{
  Serial.begin(9600);   // open serial over USB

  pinMode(lightPin, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(lightPower, LOW);//Set to LOW so no power is flowing through the sensor
}

void loop() 
{
Serial.print("Light = ");    
//print the value taken by the sensor
Serial.println(readLight());

delay(1000);//take a reading every second
}
//This is a function used to get the light moisture content
int readLight()
{

    digitalWrite(lightPin, HIGH);//turn D7 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(lightPin);//Read the SIG value form sensor 
    digitalWrite(lightPower, LOW);//turn D7 "Off"
    return val;//send current light value
}
