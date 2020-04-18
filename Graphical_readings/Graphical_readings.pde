// Simple processing sketch fro isplaying the values from the sensors on the screen in a gui
// Not a necessary piece of software

import processing.serial.*;

Serial mySerial;

PrintWriter output;

void setup() {
  size(200, 200);
  background(240, 93, 93);

  mySerial = new Serial( this, Serial.list()[1], 9600 );
  output = createWriter( "data.csv" );
}

void draw() {
  if (mySerial.available() > 0 ) {
    String value1 = mySerial.readString();
    if ( value1 != null ) {
      output.println(value1);
      background(240, 93, 93);
      text(value1, 10, height/2); 
      fill(255, 255, 255);
    }
  }
}

void keyPressed() {
  if (key == 'q') {
    output.flush();  
    output.close();  
    exit();
  }
}
