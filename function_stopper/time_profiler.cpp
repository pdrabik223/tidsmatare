//
// Created by studio25 on 02.10.2021.
//

#include "time_profiler.h"
void function_stopper::TimeProfiler::StartClock() {
  FunctionStopperBase::StartClock();
}
void function_stopper::TimeProfiler::StopClock() {
  FunctionStopperBase::StopClock();
}
void function_stopper::TimeProfiler::Measure() {
  FunctionStopperBase::Measure();
}

const std::vector<std::chrono::milliseconds> &
function_stopper::TimeProfiler::GetTimings() {
  return FunctionStopperBase::GetTimings();
}
