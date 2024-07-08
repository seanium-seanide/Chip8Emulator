#pragma once

/**
 * @file Chip8_Memory.hpp
 *
 * @brief
 */

#include "Chip8_MemoryRegion.hpp"

#include <vector>
#include <cstdint>


namespace Chip8
{

class Memory
{
public:

  Memory();
  ~Memory();

  void mapRegion(const Chip8::MemoryRegion &&memoryRegion);

private:

  std::vector<Chip8::MemoryRegion> m_memoryRegions;

};  // class Memory

}   // namespace Chip8
