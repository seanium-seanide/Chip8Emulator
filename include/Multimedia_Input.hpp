#pragma once

/**
 * @file Multimedia_Input.hpp
 *
 * @brief
 */

#include <array>
#include <cstdint>

#include <SDL2/SDL.h>

#include "Input_config.hpp"


namespace Multimedia
{

class Input
{
public:

  Input();
  ~Input();


  /**
   * @brief
   */
  void update();


  /**
   * @brief
   */
  bool quitPressed();

  /**
   * @brief
   */
  bool keyPressed(char character);

  /**
   * @brief
   */
  bool keyReleased(char character);

private:

  bool m_quitPressed;

  std::array<bool, NUM_KEYS> m_keyboardState;
  std::array<bool, NUM_KEYS> m_previousKeyboardState;


  /**
   * @brief
   */
  void handleKeyPress(SDL_Event &event);

  /**
   * @brief
   */
  void handleKeyRelease(SDL_Event &event);
};  // class Input

}   // namespace Multimedia
