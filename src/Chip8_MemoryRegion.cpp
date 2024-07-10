/**
 * @file Chip8_MemoryRegion.cpp
 *
 * @brief
 */

#include "Chip8_MemoryRegion.hpp"

#include <cstdint>


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


void MemoryRegion::storeBlock(std::size_t regionStart, uint8_t *blockStart, std::size_t blockSize)
{
  //std::memcpy(destination, start, size);
}

}   // namespace Chip8
