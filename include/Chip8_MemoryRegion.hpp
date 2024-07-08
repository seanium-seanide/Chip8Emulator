#pragma once

/**
 * @file Chip8_MemoryRegion.hpp
 *
 * @brief
 */


#include <cstdint>


namespace Chip8
{

class MemoryRegion
{
public:

  MemoryRegion(std::size_t minIndex, std::size_t maxIndex);
  ~MemoryRegion();

private:

  std::size_t m_minIndex;
  std::size_t m_maxIndex;

};  // class MemoryRegion

}   // namespace Chip8
