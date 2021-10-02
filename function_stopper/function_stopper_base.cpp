//
// Created by studio25 on 02.10.2021.
//

#include "function_stopper_base.h"
function_stopper::FunctionStopperBase::FunctionStopperBase(
    const function_stopper::FunctionStopperBase &other) {

  for (auto &t : other.timings_)
    timings_.emplace_back(t);
  clock_stop_point_ = other.clock_stop_point_;
  clock_state_ = other.clock_state_;
  off_time_ = other.off_time_;

}
function_stopper::FunctionStopperBase &
function_stopper::FunctionStopperBase::operator=(
    const function_stopper::FunctionStopperBase &other) {
if(this == &other) return *this;

for (auto &t : other.timings_)
  timings_.emplace_back(t);
clock_stop_point_ = other.clock_stop_point_;
clock_state_ = other.clock_state_;
off_time_ = other.off_time_;

return *this;
}
void function_stopper::FunctionStopperBase::StartClock() {
  if (clock_state_ == ClockState::STOPPED) {
    off_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - clock_stop_point_);

    clock_state_ = ClockState::RUNNING;
    return;
  }


  clock_state_ = ClockState::RUNNING;
  clock_start_point_ = std::chrono::high_resolution_clock::now();

}
void function_stopper::FunctionStopperBase::StopClock() {
  clock_stop_point_ = std::chrono::high_resolution_clock::now();
  clock_state_ = ClockState::STOPPED;
}
void function_stopper::FunctionStopperBase::Measure() {
  auto now = std::chrono::high_resolution_clock::now();

  if (clock_state_ == ClockState::RUNNING)
    timings_.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(
        now - clock_start_point_ - off_time_));

  clock_state_ = ClockState::OFFLINE;
}
