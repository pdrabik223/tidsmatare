//
// Created by studio25 on 30.09.2021.
//

#ifndef TIDSMATARE__FUNCTION_TIMER_BASE_H_
#define TIDSMATARE__FUNCTION_TIMER_BASE_H_

enum class ClockResolution{
  SECONDS,
  MILLISECONDS,
  MICROSECONDS,
  NANOSECONDS
};


class FunctionTimerBase {

protected:
  virtual void StartClock() = 0;
  virtual void StopClock() = 0;
  virtual void EndClock() = 0;
  virtual void Measure() = 0;


};

#endif // TIDSMATARE__FUNCTION_TIMER_BASE_H_
