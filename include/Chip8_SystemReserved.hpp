#pragma once


#include "Chip8_MemoryRegion.hpp"


namespace Chip8
{

class SystemReserved: public MemoryRegion
{
public:

  SystemReserved();
  ~SystemReserved();

protected:

private:

};  // class SystemReserved

}   // namespace Chip8
