//
// Created by studio25 on 30.09.2021.
//

#include "console_stopper.h"
void ConsoleStopper::StartClock() {
  if (clock_state_ == ClockState::STOPPED)
    off_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - clock_stop_point_);
  clock_state_ = ClockState::RUNNING;

  clock_start_point_ = std::chrono::high_resolution_clock::now();
}
void ConsoleStopper::StopClock() {
  clock_stop_point_ = std::chrono::high_resolution_clock::now();
  clock_state_ = ClockState::STOPPED;
}
void ConsoleStopper::Measure() {
  auto now = std::chrono::high_resolution_clock::now();

  if (clock_state_ == ClockState::RUNNING)
    timings_.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(
        now - clock_start_point_ - off_time_));
}
void ConsoleStopper::EndClock() {
  Measure();
  clock_state_ = ClockState::OFFLINE;
}

void ConsoleStopper::DisplayTimings() {
  for (int i = 0; i < timings_.size(); i++)
    printf("time\t%d:\t%lld\n", i, timings_[i].count());
}
