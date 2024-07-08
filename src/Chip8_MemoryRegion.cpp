/**
 * @file Chip8_MemoryRegion.cpp
 *
 * @brief
 */

#include "Chip8_MemoryRegion.hpp"


namespace Chip8
{

MemoryRegion::MemoryRegion(std::size_t minIndex, std::size_t maxIndex)
: m_minIndex(minIndex)
, m_maxIndex(maxIndex)
{
  static_cast<void>(m_minIndex);
  static_cast<void>(m_maxIndex);
}

MemoryRegion::~MemoryRegion()
{
}

}   // namespace Chip8
