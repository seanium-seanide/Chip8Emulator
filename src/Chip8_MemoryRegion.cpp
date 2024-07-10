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
}

MemoryRegion::~MemoryRegion()
{
}


std::size_t MemoryRegion::getMinIndex()
{
  return m_minIndex;
}

std::size_t MemoryRegion::getMaxIndex()
{
  return m_maxIndex;
}

}   // namespace Chip8
