/**
 * @file Multimedia_Video.cpp
 *
 * @brief
 */

// TODO: Abstract away SDL (e.g. maybe colours, positions etc should be packaged
//   together)
// TODO: Make thread-safe - drawing currently relies on a flag to state whether
//   the back buffer is being drawn. For example, could the flag be an atomic?
//   Would each flag set need to be rethought?

#include "Multimedia_Video.hpp"

#include <stdexcept>
#include <iostream>


namespace Multimedia
{

Video::Video(std::string title, uint32_t width, uint32_t height)
: m_drawingBackBuffer(false)
, m_pBackgroundColour(nullptr)
, m_windowTitle(title)
, m_width(width)
, m_height(height)
, m_pWindow(nullptr)
, m_pRenderer(nullptr)
{
  m_pBackgroundColour = new Colour({0x00, 0x00, 0x00});
}

Video::~Video()
{
  delete m_pBackgroundColour;

  quit();
}


void Video::init()
{
  // Initialise SDL video

  // TODO: Remove. Only present for debug.
  std::cerr << "Initialising video...\n";

  if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
  {
    throw std::runtime_error("Failed to initialse SDL");
  }

  // Create window

  // TODO: Remove. Only present for debug.
  std::cerr << "Creating a window...\n";

  m_pWindow = SDL_CreateWindow(
    m_windowTitle.c_str()
    , SDL_WINDOWPOS_UNDEFINED
    , SDL_WINDOWPOS_UNDEFINED
    , static_cast<int>(m_width)
    , static_cast<int>(m_height)
    , SDL_WINDOW_SHOWN
  );

  if (m_pWindow == nullptr)
  {
    throw std::runtime_error("Failed to create an SDL window");
  }

  // Create renderer

  // TODO: Remove. Only present for debug.
  std::cerr << "Creating a renderer...\n";

  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

  if (m_pRenderer == nullptr)
  {
    throw std::runtime_error("Failed to create an SDL renderer");
  }
}

void Video::quit()
{
  if (m_pRenderer != nullptr)
  {
    // TODO: Remove. Only present for debug.
    std::cerr << "Freeing renderer...\n";

    SDL_DestroyRenderer(m_pRenderer);
  }

  if (m_pWindow != nullptr)
  {
    // TODO: Remove. Only present for debug.
    std::cerr << "Freeing window...\n";

    SDL_DestroyWindow(m_pWindow);
  }

  if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
  {
    // TODO: Remove. Only present for debug.
    std::cerr << "Closing SDL...\n";

    SDL_Quit();
  }
}


void Video::renderBackBuffer()
{
  if (!m_drawingBackBuffer)
  {
    // TODO: Check whether the compiler optimises this out. Surely it must?
    m_drawingBackBuffer = true;
    clearBackBuffer();
  }

  m_drawingBackBuffer = false;

  SDL_RenderPresent(m_pRenderer);
}

// TODO: Move construct *m_pBackgroundColour maybe?
void Video::setBackgroundColour(const Colour &colour)
{
  (*m_pBackgroundColour)[COLOUR_R] = colour[COLOUR_R];
  (*m_pBackgroundColour)[COLOUR_G] = colour[COLOUR_G];
  (*m_pBackgroundColour)[COLOUR_B] = colour[COLOUR_B];
  (*m_pBackgroundColour)[COLOUR_A] = colour[COLOUR_A];
}

void Video::clearBackBuffer()
{
  clearBackBuffer(*m_pBackgroundColour);
}

void Video::clearBackBuffer(const Colour &colour)
{
  SDL_SetRenderDrawColor(m_pRenderer, colour[COLOUR_R], colour[COLOUR_G], colour[COLOUR_B], colour[COLOUR_A]);
  SDL_RenderClear(m_pRenderer);
}

void Video::drawRect(const Vector2D &position, const Vector2D &dimension, const Colour &colour, bool fill)
{
  if (!m_drawingBackBuffer)
  {
    m_drawingBackBuffer = true;
    clearBackBuffer();
  }

  // TODO: Set pixel colour
  SDL_SetRenderDrawColor(m_pRenderer, colour[COLOUR_R], colour[COLOUR_G], colour[COLOUR_B], colour[COLOUR_A]);

  SDL_Rect rect = {
    static_cast<int>(position[Vector2D::M_X])
    , static_cast<int>(position[Vector2D::M_Y])
    , static_cast<int>(dimension[Vector2D::M_X])
    , static_cast<int>(dimension[Vector2D::M_Y])
  };

  if (fill)
  {
    SDL_RenderFillRect(m_pRenderer, &rect);
  }
  else
  {
    SDL_RenderDrawRect(m_pRenderer, &rect);
  }
}

}   // namespace Multimedia
