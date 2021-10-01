//
// Created by studio25 on 30.09.2021.
//

#include "console_stopper.h"

void ConsoleStopper::DisplayTimings() {
  for (long long unsigned i = 0; i < timings_.size(); i++)
    printf("time\t%llu:\t%lld\n", i, timings_[i].count());
}
void ConsoleStopper::DisplayLastTime() {
  printf("time\t%llu:\t%lld\n", timings_.size() - 1, timings_.back().count());
}

void ConsoleStopper::StartClock() { StopperBase::StartClock(); }
void ConsoleStopper::StopClock() { StopperBase::StopClock(); }
void ConsoleStopper::Measure() { StopperBase::Measure(); }
void ConsoleStopper::EndClock() { StopperBase::EndClock(); }

ConsoleStopper::ConsoleStopper(const ConsoleStopper &other) {
  for (auto &t : other.timings_)
    timings_.emplace_back(t);
  clock_stop_point_ = other.clock_stop_point_;
  clock_state_ = other.clock_state_;
  off_time_ = other.off_time_;
}
