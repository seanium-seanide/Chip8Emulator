/**
 * @file Chip8_Memory.cpp
 *
 * @brief
 */

#include "Chip8_Memory.hpp"


namespace Chip8
{

template<std::size_t size>
Memory<size>::Memory()
: m_buffer{}
, m_memoryRegions{}
{
}

template<std::size_t size>
Memory<size>::~Memory()
{
}

template<std::size_t size>
void Memory<size>::mapRegion(const Chip8::MemoryRegion &&memoryRegion)
{
  m_memoryRegions.push_back(memoryRegion);
}

}   // namespace Chip8
