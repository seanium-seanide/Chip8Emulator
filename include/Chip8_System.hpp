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


namespace Chip8
{

class System
{
public:

  System();
  ~System();

private:

  RegisterFile    m_registers;
  Memory          m_memory;
  SystemReserved  m_systemReserved;
  Cartridge       m_cartridge;
  Framebuffer     m_framebuffer;

};  // class System

}   // namespace Chip8
