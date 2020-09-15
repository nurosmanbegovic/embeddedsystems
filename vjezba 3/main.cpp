#include "mbed.h"
#include "N5110.h"
#include "string"
#include <Dht11.h>
#define dp23 P0_0


DigitalOut enable(dp14);

N5110 lcd(dp4, dp24, dp23, dp25, dp2, dp6, dp18);
Dht11 tempsensor(dp14); //dht11

int main(){
    int upali=0, ugasi=0;
    lcd.init();
    enable=0;
    string s1, s2;
    while(1){
    lcd.clear();
    tempsensor.read();
    char buf[10];
    char buf1[10];
int a = tempsensor.getCelsius();
sprintf(buf, "%d", a);
lcd.printString(buf,10,1);


a=tempsensor.getHumidity();
sprintf(buf1, "%d", a);
lcd.printString(buf1,10,5);

/*
    s1=to_string(tempsensor.getCelsius());
    s2=to_string(tempsensor.getHumidity());
    lcd.printString(s1.begin(), 10, 1);
    lcd.printString(s2.begin(), 10, 3);
    */
    wait(1);
    }
    
}



/*


const int ledPin = 13; //pin 13 built-in led
const int soundPin = A0; //voice sensor attach to A0

void setup()
{
  pinMode(ledPin,OUTPUT); ////set pin13 as OUTPUT
  Serial.begin(9600); //initialize serial monitor
}

void loop()
{
  int value = analogRead(soundPin); //read the value of voice sensor
  Serial.println(value); //print the value
  if(value > 25) //if the value is greater than 25
  {
    digitalWrite(ledPin,HIGH); //turn on the led
    delay(2000); //delay 2s
  }
  else
  {
    digitalWrite(ledPin,LOW); //turn off the led
  }
}

*/









