//
// Created by studio25 on 02.10.2021.
//

#include "function_stopper_base.h"
#include <thread>
void ComplicatedFunction(function_stopper::FunctionStopperBase &probe);
void DisplayTimings(function_stopper::FunctionStopperBase probe);


int main() {
  function_stopper::FunctionStopperBase probe;
  ComplicatedFunction(probe);
  DisplayTimings(probe);
  return 0;
}

void ComplicatedFunction(function_stopper::FunctionStopperBase &probe) {

  probe.StartClock();
  std::this_thread::sleep_for(std::chrono::milliseconds(90));
  probe.Measure();

  // this one will not be counted
  std::this_thread::sleep_for(std::chrono::milliseconds(120));

  // next two will be combined
  probe.StartClock();
  std::this_thread::sleep_for(std::chrono::milliseconds(50));

  probe.StopClock();
  // this one will not be counted
  std::this_thread::sleep_for(std::chrono::milliseconds(120));
  probe.StartClock();

  std::this_thread::sleep_for(std::chrono::milliseconds(254));
  probe.Measure();

  // at the end measurements should read ~90 and ~304
}

void DisplayTimings(function_stopper::FunctionStopperBase probe){
  for (long long unsigned i = 0; i < probe.GetTimings().size(); i++)
    printf("time\t%llu:\t%lld\n", i, probe.GetTimings()[i].count());
}