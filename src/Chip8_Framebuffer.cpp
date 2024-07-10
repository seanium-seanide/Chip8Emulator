/**
 * @file Chip8_Framebuffer.cpp
 *
 * @brief
 */

#include "Chip8_Framebuffer.hpp"


namespace Chip8
{

Framebuffer::Framebuffer()
: m_video(WINDOW_TITLE, WINDOW_WIDTH * WINDOW_PIXEL_SIZE, WINDOW_HEIGHT * WINDOW_PIXEL_SIZE)
{
  m_video.setBackgroundColour({0x00, 0x00, 0x00, 0xFF});
}

Framebuffer::~Framebuffer()
{
  quit();
}


void Framebuffer::init()
{
  m_video.init();
}

void Framebuffer::quit()
{
}


void Framebuffer::render()
{
  m_video.drawRect(
    Multimedia::Vector2D(0, 0)
    , Multimedia::Vector2D(WINDOW_PIXEL_SIZE, WINDOW_PIXEL_SIZE)
    , {0xFF, 0xFF, 0xFF, 0xFF}
  );

  m_video.renderBackBuffer();
}

}   // namespace Chip8
