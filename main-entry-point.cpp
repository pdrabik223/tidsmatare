//
// Created by piotr233 on 30.09.2021.
//

#include <iostream>
#include <thread>
#include "console_stopper.h"
void OneSecondFunction();

int main() {
  ConsoleStopper time;
  time.StartClock();
  OneSecondFunction();
  time.Measure();
  OneSecondFunction();
  time.Measure();
  OneSecondFunction();
  time.Measure();
  OneSecondFunction();
  time.Measure();
  OneSecondFunction();
  time.Measure();


  time.DisplayTimings();
  int duzo = 100'000'000;
  std::cout<<duzo;
  return 0;

}

void OneSecondFunction(){std::this_thread::sleep_for(std::chrono::milliseconds(30));}