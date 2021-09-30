//
// Created by piotr233 on 30.09.2021.
//

#include <iostream>
#include <thread>
void OneSecondFunction();

int main() {

  OneSecondFunction();

  return 0;

}

void OneSecondFunction(){std::this_thread::sleep_for(std::chrono::milliseconds(30));}