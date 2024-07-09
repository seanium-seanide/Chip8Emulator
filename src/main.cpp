/**
 * @file main.cpp
 *
 * @brief
 */


#include <iostream>

#include "Chip8_System.hpp"


int main(int argc, char **argv)
{
  Chip8::System system;

  system.init();
  system.mainLoop();

  return 0;
}
