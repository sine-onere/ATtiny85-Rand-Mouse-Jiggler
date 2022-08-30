/*
  Mouse jiggler that moves in a semi random interval.
  Must be used with a ATtiny85 Digistump unless modified.

  Use the following url in the Boards Manager
  http://digistump.com/package_digistump_index.json

  Then make sure to install Digistump AVR Boards from the Boards Manager

  Finally editing the usbconfig.h in the digistump files and the url
  devicehunt.com you can pick your mouse already connected to the computer.

  Any questions can be resolved using the excellent tutorial at 
  https://ericdraken.com/usb-mouse-jiggler/
*/
#include <Mouse.h>

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Mouse.begin();
}

void loop() {
  //Produce the xMoves and distances to be done in a loop at semi random
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  
  int xMoves = random(1, 5);
  for (int count = 0; count < xMoves; count++) {
    int distance = random(200, 1000);
    int wait = random(100, 1000);
    Mouse.move(distance, 0, 0);
    delay(wait);
  }
  
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a half second
  
  //Produce the yMoves and distances to be done in a loop at semi random
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  
  int yMoves = random(1, 5);
  for (int count = 0; count < xMoves; count++) {
    int distance = random(200, 1000);
    int wait = random(100, 1000);
    Mouse.move(distance, 0, 0);
    delay(wait);
  }
  
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a half second
}
