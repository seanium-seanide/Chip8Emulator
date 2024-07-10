#pragma once

/**
 * @file Chip8_System.hpp
 *
 * @brief
 */


#include "Chip8_RegisterFile.hpp"
#include "Chip8_Memory.hpp"
#include "Chip8_SystemReserved.hpp"
#include "Chip8_Cartridge.hpp"
#include "Chip8_Framebuffer.hpp"
#include "Chip8_Keypad.hpp"

//#include "Multimedia_Input.hpp"

namespace Chip8
{

class System
{
public:

  System();
  ~System();


  /**
   * @brief
   */
  void init();

  /**
   * @brief
   */
  void quit();


  /**
   * @brief
   */
  void mainLoop();

  /**
   * @brief
   */
  void update();

private:

  bool m_running;

  RegisterFile        m_registers;
  Memory<MEMORY_SIZE> m_memory;
  SystemReserved      m_systemReserved;
  Cartridge           m_cartridge;
  Framebuffer         m_framebuffer;
  Keypad              m_keypad;

  //Multimedia::Video m_video;
  Multimedia::Input m_input;

};  // class System

}   // namespace Chip8
