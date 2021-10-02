//
// Created by piotr233 on 30.09.2021.
//


#include "function_stopper_base.h"
#include <thread>
void OneSecondFunction();
int main() {
  //  ConsoleStopper time;
  //  time.StartClock();
  //  OneSecondFunction();
  //  time.Measure();
  //
  //  OneSecondFunction();
  //  time.Measure();
  //
  //  OneSecondFunction();
  //  time.Measure();
  //
  //  OneSecondFunction();
  //  time.Measure();
  //
  //  OneSecondFunction();
  //  time.Measure();
  //
  //  time.DisplayTimings();




  return 0;
}

void OneSecondFunction() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
}
