#include <Wire.h>
#include <IRremote.h>
IRsend irsend;
String command;
void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 //Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial for debug */
}

void loop() {
if (command.equals("off")){ 
 delay(200);
 irsend.sendNEC(0x10EF906, 32);
 }
if (command.equals("on")){ 
 delay(200);
 irsend.sendNEC(0x10E03FC, 32);
 } 
delay(1000);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 command = "";
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    command += c;
    //Serial.print(c);           /* print the character */
  }
 
 
 
 Serial.println("cmd");
 Serial.println(command); 
 
}
