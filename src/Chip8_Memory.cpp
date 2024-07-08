/**
 * @file Chip8_Memory.cpp
 *
 * @brief
 */

#include "Chip8_Memory.hpp"


namespace Chip8
{

Memory::Memory()
{
}

Memory::~Memory()
{
}

void Memory::mapRegion(const Chip8::MemoryRegion &&memoryRegion)
{
  m_memoryRegions.push_back(memoryRegion);
}

}   // namespace Chip8
