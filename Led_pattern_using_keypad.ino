#include <Key.h>
#include <Keypad.h>

#include <AnalogKeypad.h>

#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>


int ledPin;
void ledpatern1();
void ledpatern2();
void ledpatern3();
void ledpatern4();

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};
byte rowPins[ROWS]={2,3,4,5};
byte colPins[COLS]={6,7,8,9};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);
void setup() {  
  Serial.begin(9600);
  for(ledPin=10;ledPin<=14;ledPin++)
  {
    pinMode(ledPin,OUTPUT);
    }
    Serial.println("Enter the pattern number (1,2,3,4)");
}
void ledpatern1()
{
 for(ledPin=2;ledPin<=6;ledPin++)
  {
    digitalWrite(ledPin,HIGH);
    } 
    for(ledPin=2;ledPin<=6;ledPin++)
  {
    digitalWrite(ledPin,LOW);
    } 
  }
void ledpatern2()
{
  for(ledPin=2;ledPin<=6;ledPin++)
  {
    digitalWrite(ledPin,HIGH);
    delay(1000);
    digitalWrite(ledPin,LOW);
    delay(1000);
    } 
  
  }
void ledpatern3()
{
  for(ledPin=5;ledPin<=0;ledPin--)
  {
    digitalWrite(ledPin,HIGH);
    delay(1000);
    } 
    for(ledPin=5;ledPin<=0;ledPin--)
  {
    digitalWrite(ledPin,LOW);
    delay(1000);
    } 

  }
void ledpatern4()
{
  for(ledPin=1;ledPin<=6;ledPin +2)
  {
    digitalWrite(ledPin,HIGH);
    delay(1000);
    } 
    for(ledPin=2;ledPin<=6;ledPin +2)
  {
    digitalWrite(ledPin,LOW);
    delay(1000);
    }
  for(ledPin=1;ledPin<=6;ledPin +2)
  {
    digitalWrite(ledPin,HIGH);
    delay(1000);
    } 
    for(ledPin=2;ledPin<=6;ledPin +2)
  {
    digitalWrite(ledPin,LOW);
    delay(1000);
    }  
  
  }
void loop() {
  char customKey = customKeypad.getKey();
  if(customKey)
  {
    
    if(customKey =='1')
    ledpatern1();
    else if(customKey =='2')
    ledpatern2();
    else if(customKey =='3')
    ledpatern3();
    else if(customKey =='4')
    ledpatern4();
    
    }
}
