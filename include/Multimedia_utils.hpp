#pragma once

/**
 * @file Multimedia_utils.hpp
 *
 * @brief
 */

#include "Multimedia_config.hpp"

#include <array>
#include <cstdint>


namespace Multimedia
{

class Vector2D
{
public:

  static constexpr uint32_t NUM_ELEMENTS = 2;
  static constexpr uint32_t M_X = 0;
  static constexpr uint32_t M_Y = 1;

public:

  Vector2D();
  Vector2D(uint32_t x, uint32_t y);
  ~Vector2D();

  const uint32_t &operator[](std::size_t index) const;
  uint32_t &operator[](std::size_t index);

private:

  std::array<uint32_t, NUM_ELEMENTS> m_data;
};

typedef std::array<uint8_t, NUM_COLOUR_CHANNELS> Colour;

}   // namespace Multimedia
