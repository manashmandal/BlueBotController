/*
  Author: Manash

*/

byte incomingByte;   // for incoming serial data
int Speed = 230;

#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11);

const int leftMotor[2] = {3,5};
const int rightMotor[2] = {6, 9};


void setMotor(int lsp, int rsp)
{
  if (lsp >= 0 && rsp >= 0){
    analogWrite(leftMotor[0], lsp); // Forward, Left, Right
    analogWrite(leftMotor[1], 0);
    analogWrite(rightMotor[0], rsp);
    analogWrite(rightMotor[1], 0);
  }
  
  if (lsp < 0 && rsp < 0)
  {
    lsp = -lsp;
    rsp = -rsp;
    
    analogWrite(leftMotor[0], 0);
    analogWrite(leftMotor[1], lsp); // Backward
    analogWrite(rightMotor[0], 0);
    analogWrite(rightMotor[1], rsp);
  }
  
}

void setspeed(byte data)
{
  switch(data){
    
       case 'H':
         Speed = 255;
         break;
       case 'h':
         Speed = 255;
         break;
       case 'M':
         Speed = 220;
         break;
       case 'm':
         Speed = 220;
         break;
       case 'l':
         Speed = 190;
         break;
       case 'L':
         Speed = 190;
         break;

     } 
    
}


void setup() {
    bt.begin(9600);
    Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
     
    for (int i = 0; i < 2; i++){
      pinMode(leftMotor[i], OUTPUT);
      pinMode(rightMotor[i], OUTPUT);
  }
}

void loop() {
        // send data only when you receive data:
    if (bt.available() > 0) {
        incomingByte = bt.read();         // read the incoming byte:
                // say what you got:
                bt.print("I received: ");
                bt.println(incomingByte);
        }
        
    if (incomingByte == 'w' || incomingByte == 'W') setMotor(Speed, Speed);
    else if (incomingByte == 's' || incomingByte == 'S') setMotor(-Speed, -Speed);
    else if (incomingByte == 'a' || incomingByte == 'A') setMotor(0, Speed);
    else if (incomingByte == 'd' || incomingByte == 'D') setMotor(Speed, 0);
    else if (incomingByte == 'H' || incomingByte == 'h' || incomingByte == 'L' || incomingByte == 'l' || incomingByte == 'm' || incomingByte == 'M') setspeed(incomingByte);   
    else setMotor(0, 0);      
} 
