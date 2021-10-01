//
// Created by studio25 on 30.09.2021.
//

#ifndef TIDSMATARE__CONSOLESTOPPER_H_
#define TIDSMATARE__CONSOLESTOPPER_H_

#include "stopper_base.h"
class ConsoleStopper: public StopperBase  {
public:
  ConsoleStopper() = default;
  ConsoleStopper(const ConsoleStopper& other);
  ConsoleStopper& operator=(const ConsoleStopper& other);

  void StartClock() override;
  void StopClock() override;
  void Measure() override;

  void DisplayTimings();
  void DisplayLastTime();

  ~ConsoleStopper() = default;
private:
  void EndClock() override;
};

#endif // TIDSMATARE__CONSOLESTOPPER_H_
