#include <Arduino.h>
#include <Ticker.h>

Ticker::Ticker(long t){
  cycle=t;
  begin();
}

void Ticker::begin(){
  lastMillis=millis();
}

void Ticker::over(){
  lastMillis -= cycle;
}

long Ticker::restMillis() {
  unsigned long t=millis();
  /* if(cycle>1000){
    Serial.print("t=");Serial.println(t);
    Serial.print("lastMillis=");Serial.println(lastMillis);
    Serial.print("t-lastMillis=");Serial.println((long)(t-lastMillis));
    Serial.print("rest=");Serial.println((long) (cycle-(long)(t-lastMillis)));
    Serial.println("");
    }*/ 
  long rest=(long) (cycle-(long)(t-lastMillis));
  return(rest);
}

long Ticker::rest() {
  return((restMillis()+500)/1000);
}

void Ticker::setTicker2NextCycle(){
  long overtime=-restMillis();

  // Serial.print("overtime="); Serial.println(overtime);

  // cycle is over?
  if(overtime<0)
    return; // no

  // adjust to next cycle
  long n=(overtime+cycle-1)/cycle;
  // Serial.print("n="); Serial.println(n);

  lastMillis += n*cycle;
  // Serial.print("new lastMillis="); Serial.println(lastMillis);

}

bool Ticker::check() {
  long t=restMillis();
  if(!timeOut()){
    return false;
  }
  setTicker2NextCycle();
  return true;
}

bool Ticker::timeOut(){
  long t=restMillis();
  if(t>0L){
    return false;
  }else{
    return true;
  }
}
  

void Ticker::sleep(){
  long t=restMillis();
  // Serial.print("sleep t="); Serial.println(t);
  setTicker2NextCycle();
  if(t>0){
    delay(t);
  }
}
