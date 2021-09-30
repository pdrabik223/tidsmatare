//
// Created by studio25 on 30.09.2021.
//

#ifndef TIDSMATARE__STOPPER_BASE_H_
#define TIDSMATARE__STOPPER_BASE_H_

#include <chrono>
#include <vector>
enum class ClockResolution{
  SECONDS,
  MILLISECONDS,
  MICROSECONDS,
  NANOSECONDS
};



class StopperBase {

protected:
  virtual void StartClock() = 0;
  virtual void StopClock() = 0;
  virtual void Measure() = 0;

  /// used only in destructor
  virtual void EndClock() = 0;

  std::vector<std::chrono::nanoseconds> timings_;

  std::chrono::nanoseconds off_time_;

  std::chrono::time_point<std::chrono::high_resolution_clock> clock_start_point_;

  std::chrono::high_resolution_clock clock_;


};

#endif // TIDSMATARE__STOPPER_BASE_H_
