/*

 Ticker Test
 
 Creates two ticker.
 tn has 5 seconds cycle time
 t1 has 1 seconds cycle time
 Print countdown of tn every second to Serial and to the LCD
 */

#include <SPI.h>
#include <LiquidCrystal.h>

#include <Ticker.h>
      
Ticker tn(5*1000);
Ticker t1(1*1000);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);

void printld(char *str,long v){
  Serial.print(str);
  Serial.print(v);
}


void setup() 
{
  Serial.begin(9600);
  tn.begin();
  delay(10);
  t1.begin();


}

long ts1,ts2,ts3;
long tn1,tn2,tn3;

void loop()
{
  tn1=tn.restMillis();
  long t=tn.rest();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(t);
  tn2=tn.restMillis();
  tn.check();
  tn3=tn.restMillis();
  ts2=t1.restMillis();
  printld("millis=",millis());
  printld(" ts1=",ts1);
  printld(" ts2=",ts2);
  printld(" ts3=",ts3);
  printld(" tn1=",ts1);
  printld(" t1=",tn1);
  printld(" tn2=",tn2);
  printld(" tn3=",tn3);
  Serial.println("");
  printld("countdown=",t);
  Serial.println("");
  if(t==0)
    Serial.println("\n");
  ts3=t1.restMillis();
  t1.sleep();
  ts1=t1.restMillis();
}
