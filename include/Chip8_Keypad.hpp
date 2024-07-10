#pragma once

/**
 * @file Chip8_Keypad.hpp
 *
 * @brief
 */

#include "Multimedia_Input.hpp"


namespace Chip8
{

class Keypad
{
public:

  Keypad();
  ~Keypad();


  /**
   * @brief
   */
  void init();

  /**
   * @brief
   */
  void quit();


  // TODO: Move input to kepyad
  /**
   * @brief Update keypad state
   */
  void update();

  
  /**
   * @brief Get keypad state
   */
  bool keyPressed(uint8_t key);

  /**
   * @brief Get keypad state
   */
  bool keyReleased(uint8_t key);
  
  /**
   * @brief
   */
  bool userQuit();

private:

  Multimedia::Input m_input;
};  // class Keypad

}   // namespace Chip8
