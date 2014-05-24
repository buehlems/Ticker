Ticker(long t): create a new ticker with loop time t. All times are in ms

begin: reset start time to current time

over: finish current cycle

restMillis: get the remaining time of thes cycle (can be negative)

setTicker2NextCycle: start the next cycle. If last cycle was already over for <n> ms, n will be subtraced from the current cycle.

check: returns true if current cycle is over and start starts new cycle

timeout: checks if current cycle is over but does not start a new cycle

sleep: sleeps for the rest of this cycle
