//
// Created by studio25 on 02.10.2021.
//

#ifndef TIDSMATARE_FUNCTION_STOPPER_TIME_PROFILER_H_
#define TIDSMATARE_FUNCTION_STOPPER_TIME_PROFILER_H_
#include "function_stopper_base.h"
namespace function_stopper {
class TimeProfiler : public function_stopper::FunctionStopperBase{

public:
  void StartClock() override;
  void StopClock() override;
  void Measure(const std::string label);
  void Output() override = delete;
  const std::vector<std::chrono::milliseconds> &GetTimings();

};
}
#endif // TIDSMATARE_FUNCTION_STOPPER_TIME_PROFILER_H_
