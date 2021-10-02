//
// Created by studio25 on 02.10.2021.
//

#ifndef TIDSMATARE_FUNCTION_STOPPER_FUNCTION_STOPPER_BASE_H_
#define TIDSMATARE_FUNCTION_STOPPER_FUNCTION_STOPPER_BASE_H_


#include <chrono>
#include <vector>

namespace function_stopper {

enum class ClockResolution { SECONDS, MILLISECONDS, MICROSECONDS, NANOSECONDS };
enum class ClockState { OFFLINE, RUNNING};

class FunctionStopperBase {
public:
  FunctionStopperBase();
  FunctionStopperBase(const FunctionStopperBase& other);
  FunctionStopperBase& operator=(const FunctionStopperBase& other);

  virtual void StartClock();
  virtual void StopClock();
  virtual void Measure();

private:

  std::vector<std::chrono::milliseconds> timings_;


  std::chrono::time_point<std::chrono::high_resolution_clock> clock_start_point_;
  std::chrono::time_point<std::chrono::high_resolution_clock> clock_stop_point_;


  /// current clock state
  ClockState clock_state_ = ClockState::OFFLINE;

  std::chrono::milliseconds off_time_ = std::chrono::milliseconds(0);


};

}
#endif // TIDSMATARE_FUNCTION_STOPPER_FUNCTION_STOPPER_BASE_H_
