/**
 * @file Chip8_Cartridge.cpp
 *
 * @brief
 */

#include "Chip8_Cartridge.hpp"


namespace Chip8
{

Cartridge::Cartridge(std::size_t minIndex, std::size_t maxIndex)
: MemoryRegion(minIndex, maxIndex)
{
}

Cartridge::~Cartridge()
{
}

}   // namespace Chip8
