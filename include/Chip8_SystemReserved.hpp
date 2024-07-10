#pragma once

/**
 * @file Chip8_SystemReserved.hpp
 *
 * @brief
 */


#include "Chip8_MemoryRegion.hpp"
#include "Chip8_config.hpp"

#include <cstdint>


namespace Chip8
{

class SystemReserved: public MemoryRegion
{
public:

  SystemReserved(std::size_t minIndex, std::size_t maxIndex);
  ~SystemReserved();

private:

};  // class SystemReserved

}   // namespace Chip8
