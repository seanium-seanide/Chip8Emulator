/**
 * @file Chip8_SystemReserved.cpp
 *
 * @brief
 */

#include "Chip8_SystemReserved.hpp"


namespace Chip8
{

SystemReserved::SystemReserved(std::size_t minIndex, std::size_t maxIndex)
: MemoryRegion(minIndex, maxIndex)
{
}

SystemReserved::~SystemReserved()
{
}

}   // namespace Chip8
