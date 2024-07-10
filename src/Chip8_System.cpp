/**
 * @file Chip8_System.cpp
 *
 * @brief
 */

#include "Chip8_System.hpp"
#include "Chip8_config.hpp"

#include "Multimedia_utils.hpp"


namespace Chip8
{

System::System()
: m_running(false)
, m_registers()
, m_memory()
, m_systemReserved(0x0000, 0x01FF)
, m_cartridge(0x0200,0xFFF)
, m_framebuffer()
, m_keypad()
//, m_input()
{
}

System::~System()
{
  quit();
}


void System::init()
{
  // TODO: Potentially move initialisation into framebuffer constructor
  m_framebuffer.init();

  m_running = true;
}

void System::quit()
{
}


void System::mainLoop()
{
  while (m_running)
  {
    m_keypad.update();
    if (m_keypad.userQuit())
    {
      m_running = false;
    }

    update();

    m_framebuffer.render();
  }
}


void System::update()
{
}

}   // namespace Chip8
