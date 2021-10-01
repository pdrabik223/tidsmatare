//
// Created by studio25 on 30.09.2021.
//

#include "stopper_base.h"

void StopperBase::StartClock() {
  if (clock_state_ == ClockState::STOPPED)
    off_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - clock_stop_point_);
  clock_state_ = ClockState::RUNNING;

  clock_start_point_ = std::chrono::high_resolution_clock::now();
}
void StopperBase::StopClock() {
  clock_stop_point_ = std::chrono::high_resolution_clock::now();
  clock_state_ = ClockState::STOPPED;
}
void StopperBase::Measure() {
  auto now = std::chrono::high_resolution_clock::now();

  if (clock_state_ == ClockState::RUNNING)
    timings_.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(
        now - clock_start_point_ - off_time_));
}
void StopperBase::EndClock() {
  Measure();
  clock_state_ = ClockState::OFFLINE;
}