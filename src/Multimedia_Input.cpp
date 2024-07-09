/**
 * @file Multimedia_Input.cpp
 *
 * @brief
 */

// TODO: Write a tool to generate the bodies of handleKeyPress and handleKeyRelease at the same time

#include "Multimedia_Input.hpp"

#include <iostream>
#include <cstring>


namespace Multimedia
{

Input::Input()
: m_quitPressed(false)
, m_keyboardState{}
, m_previousKeyboardState{}
{
  // TODO: Testing purposes. Remove.
  std::cout << "Keyboard state size:          " << sizeof(m_keyboardState) << '\n';
  std::cout << "Previous keyboard state size: " << sizeof(m_previousKeyboardState) << '\n';
}

Input::~Input()
{
}


void Input::update()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT: {
      m_quitPressed = true;
      break;
    }

    case SDL_KEYDOWN: {
      handleKeyPress(event);
      break;
    }

    case SDL_KEYUP: {
      handleKeyRelease(event);
      break;
    }

    default: {
      break;
    }
    }
  }
}


bool Input::quitPressed()
{
  bool retVal = m_quitPressed;

  // Reset quit flag
  if (m_quitPressed)
  {
    m_quitPressed = false;
  }

  return retVal;
}

bool Input::keyPressed(char character)
{
  return m_keyboardState[character];
}

bool Input::keyReleased(char character)
{
  return (m_previousKeyboardState[character]) && !(m_keyboardState[character]);
}


void Input::handleKeyPress(SDL_Event &event)
{
  // Copy previous key state
  std::memcpy(m_keyboardState.data(), m_previousKeyboardState.data(), sizeof(m_keyboardState));

  switch (event.key.keysym.sym)
  {
  case SDLK_ESCAPE: {
    m_keyboardState[KEY_ESCAPE] = true;
    break;
  }

  case SDLK_1: {
    m_keyboardState[KEY_1] = true;
  }

  case SDLK_2: {
    m_keyboardState[KEY_2] = true;
  }

  case SDLK_3: {
    m_keyboardState[KEY_3] = true;
  }

  case SDLK_4: {
    m_keyboardState[KEY_4] = true;
  }

  case SDLK_q: {
    m_keyboardState[KEY_Q] = true;
  }

  case SDLK_w: {
    m_keyboardState[KEY_W] = true;
  }

  case SDLK_e: {
    m_keyboardState[KEY_E] = true;
  }

  case SDLK_r: {
    m_keyboardState[KEY_R] = true;
  }

  case SDLK_a: {
    m_keyboardState[KEY_A] = true;
  }

  case SDLK_s: {
    m_keyboardState[KEY_S] = true;
  }

  case SDLK_d: {
    m_keyboardState[KEY_D] = true;
  }

  case SDLK_f: {
    m_keyboardState[KEY_F] = true;
  }

  case SDLK_z: {
    m_keyboardState[KEY_Z] = true;
  }

  case SDLK_x: {
    m_keyboardState[KEY_X] = true;
  }

  case SDLK_c: {
    m_keyboardState[KEY_C] = true;
  }

  case SDLK_v: {
    m_keyboardState[KEY_V] = true;
    break;
  }

  default: {
    // TODO: Handle exceptional case more elegantly
    std::cerr << "Unmapped key pressed'\n";
    break;
  }
  }
}

void Input::handleKeyRelease(SDL_Event &event)
{
  // Copy previous key state
  std::memcpy(m_keyboardState.data(), m_previousKeyboardState.data(), sizeof(m_keyboardState));

  switch (event.key.keysym.sym)
  {
  case SDLK_ESCAPE: {
    m_keyboardState[KEY_ESCAPE] = false;
    break;
  }
  
  case SDLK_1: {
    m_keyboardState[KEY_1] = false;
  }

  case SDLK_2: {
    m_keyboardState[KEY_2] = false;
  }

  case SDLK_3: {
    m_keyboardState[KEY_3] = false;
  }

  case SDLK_4: {
    m_keyboardState[KEY_4] = false;
  }

  case SDLK_q: {
    m_keyboardState[KEY_Q] = false;
  }

  case SDLK_w: {
    m_keyboardState[KEY_W] = false;
  }

  case SDLK_e: {
    m_keyboardState[KEY_E] = false;
  }

  case SDLK_r: {
    m_keyboardState[KEY_R] = false;
  }

  case SDLK_a: {
    m_keyboardState[KEY_A] = false;
  }

  case SDLK_s: {
    m_keyboardState[KEY_S] = false;
  }

  case SDLK_d: {
    m_keyboardState[KEY_D] = false;
  }

  case SDLK_f: {
    m_keyboardState[KEY_F] = false;
  }

  case SDLK_z: {
    m_keyboardState[KEY_Z] = false;
  }

  case SDLK_x: {
    m_keyboardState[KEY_X] = false;
  }

  case SDLK_c: {
    m_keyboardState[KEY_C] = false;
  }

  case SDLK_v: {
    m_keyboardState[KEY_V] = false;
    break;
  }

  default: {
    // TODO: Handle exceptional case more elegantly
    std::cerr << "Unmapped key released'\n";
    break;
  }
  }
}

}   // namespace Multimedia
