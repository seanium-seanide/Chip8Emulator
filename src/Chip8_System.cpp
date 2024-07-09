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
, m_video(WINDOW_TITLE, WINDOW_WIDTH * WINDOW_PIXEL_SIZE, WINDOW_HEIGHT * WINDOW_PIXEL_SIZE)
, m_input()
{
  m_video.setBackgroundColour({0x00, 0x00, 0x00, 0xFF});
}

System::~System()
{
  quit();
}


void System::init()
{
  m_video.init();
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
    renderFramebuffer();
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

void System::renderFramebuffer()
{
  // TODO: Replace with emulator drawing logic. Test code below.
  m_video.drawRect(
    Multimedia::Vector2D(0, 0)
    , Multimedia::Vector2D(WINDOW_PIXEL_SIZE, WINDOW_PIXEL_SIZE)
    , {0xFF, 0xFF, 0xFF, 0xFF}
  );

  m_video.renderBackBuffer();
}

}   // namespace Chip8
