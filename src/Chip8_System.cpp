/**
 * @file Chip8_System.cpp
 *
 * @brief
 */

// TODO: Remove commented lines due to rendering refactor

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
, m_input()
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
    getInput();
    updateState();
    m_framebuffer.render();
  }
}

void System::getInput()
{
  m_input.update();

  if (m_input.quitPressed() || m_input.keyPressed(Multimedia::KEY_ESCAPE))
  {
    m_running = false;
  }
}

void System::updateState()
{
}

}   // namespace Chip8
