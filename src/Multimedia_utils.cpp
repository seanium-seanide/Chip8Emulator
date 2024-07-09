/**
 * @file Multimedia_utils.cpp
 *
 * @brief
 */

#include "Multimedia_utils.hpp"

#include <stdexcept>


namespace Multimedia
{

Vector2D::Vector2D()
: m_data()
{
}

Vector2D::Vector2D(uint32_t x, uint32_t y)
: m_data()
{
  m_data[M_X] = x;
  m_data[M_Y] = y;
}

Vector2D::~Vector2D()
{
}


const uint32_t &Vector2D::operator[](std::size_t index) const
{
  if (index != M_X && index != M_Y)
  {
    throw std::out_of_range("Invalid index into a 2D vector");
  }

  return m_data[index];
}

uint32_t &Vector2D::operator[](std::size_t index)
{
  return const_cast<uint32_t &>(
      static_cast<const Vector2D &>(*this)[index]
  );
}

}   // namespace Multimedia
