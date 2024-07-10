/**
 * @file Chip8_Keypad.cpp
 *
 * @brief
 */

#include "Chip8_Keypad.hpp"
#include "Chip8_config.hpp"

#include <iostream>


namespace Chip8
{

Keypad::Keypad()
{
}

Keypad::~Keypad()
{
  quit();
}


void Keypad::init()
{
}

void Keypad::quit()
{
}


void Keypad::update()
{
  m_input.update();
}


bool Keypad::keyPressed(uint8_t key)
{
  bool retval = false;

  if (KEYMAP.find(key) == KEYMAP.end())
  {
    std::cerr << "Invalid Chip8 key!\n";
    retval = false;
  }
  else
  {
    retval = m_input.keyPressed(KEYMAP.at(key));
  }

  return retval;
}

bool Keypad::keyReleased(uint8_t key)
{
  bool retval = false;

  if (KEYMAP.find(key) == KEYMAP.end())
  {
    std::cerr << "Invalid Chip8 key!\n";
    retval = false;
  }
  else
  {
    retval = m_input.keyReleased(KEYMAP.at(key));
  }

  return retval;
}

bool Keypad::userQuit()
{
  bool retval = false;

  if (m_input.quitPressed() || m_input.keyPressed(Multimedia::KEY_ESCAPE))
  {
    retval = true;
  }

  return retval;
}

}   // namespace Chip8
