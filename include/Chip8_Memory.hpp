#pragma once

/**
 * @file Chip8_Memory.hpp
 *
 * @brief
 */

#include "Chip8_MemoryRegion.hpp"

#include <vector>
#include <array>

#include <cstdint>


namespace Chip8
{

template<std::size_t size>
class Memory
{
public:

  Memory();
  ~Memory();

  void mapRegion(const Chip8::MemoryRegion &&memoryRegion);

private:

  std::array<uint8_t, size> m_buffer;

  std::vector<Chip8::MemoryRegion> m_memoryRegions;

};  // class Memory

}   // namespace Chip8

#include "Chip8_Memory.ipp"
