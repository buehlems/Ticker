#ifndef TICKER_H
#define TICKER_H

class Ticker {
 public:
  Ticker(long t);
  void begin(); // reset start time to current time
  void over(); // finish current cycle immediatly
  bool timeOut(); // time over?
  bool check(); // time over and set to next cycle?
  long rest(); // rest in seconds
  long restMillis(); // rest in milli seconds
  void sleep(); // wait until next ticker
    
 private:
  long cycle;
  unsigned long lastMillis;
  void setTicker2NextCycle(void);

};

#endif /* TICKER_H */
