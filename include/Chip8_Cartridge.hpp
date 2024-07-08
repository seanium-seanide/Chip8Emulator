#pragma once

/**
 * @file Chip8_Cartridge.hpp
 *
 * @brief
 */


#include "Chip8_MemoryRegion.hpp"

#include <cstdint>


namespace Chip8
{

class Cartridge: public MemoryRegion
{
public:

  Cartridge(std::size_t minIndex, std::size_t maxIndex);
  ~Cartridge();

private:

};  // class Cartridge

}   // namespace Chip8
