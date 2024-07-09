#pragma once

/**
 * @file Chip8_Framebuffer.hpp
 *
 * @brief
 */

#include <cstdint>

#include "Chip8_config.hpp"
#include "Multimedia_Video.hpp"


namespace Chip8
{

class Framebuffer
{
public:

  Framebuffer();
  ~Framebuffer();


  /**
   * @brief
   */
  void init();

  /**
   * @brief
   */
  void quit();


  // TODO: Move rendering to framebuffer
  /**
   * @brief
   */
  void render();

private:

  Multimedia::Video m_video;

};  // class Framebuffer

}   // namespace Chip8
