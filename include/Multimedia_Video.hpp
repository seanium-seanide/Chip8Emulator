#pragma once

/**
 * @file Multimedia_Video.hpp
 *
 * @brief
 */

#include "Multimedia_utils.hpp"

#include <SDL2/SDL.h>

#include <string>
#include <cstdint>


namespace Multimedia
{

class Video
{
public:

  Video(std::string title, uint32_t width, uint32_t height);
  ~Video();


  /**
   * @brief
   */
  void init();
  
  /**
   * @brief
   */
  void quit();

  /**
   * @brief Copy the back buffer to the device framebuffer.
   */
  void renderBackBuffer();

  /**
   * @brief Set the clear colour for the background
   */
  void setBackgroundColour(const Colour &colour);

  /**
   * @brief Clear the back buffer with the class preset clear colour.
   *
   * @param Colour background colour
   */
  void clearBackBuffer();

  /**
   * @brief Clear the back buffer with a given colour.
   *
   * @param Colour background colour
   */
  void clearBackBuffer(const Colour &colour);

  /**
   * @brief Draw a rectangle to the framebuffer with given position, dimensions,
   *   and color.
   *
   * @param position  Position to draw top left corner, (x, y)
   * @param dimension Size of rectangle, (width, height)
   * @param colour    Colour of rectangle, (red, green, blue, alpha)
   *
   */
  void drawRect(const Vector2D &position, const Vector2D &dimension, const Colour &colour, bool fill = true);

private:

  bool m_drawingBackBuffer;
  Colour *m_pBackgroundColour;

  std::string m_windowTitle;
  uint32_t m_width;
  uint32_t m_height;

  SDL_Window *m_pWindow;
  SDL_Renderer *m_pRenderer;

};  // class Video

}   // namespace Multimedia
