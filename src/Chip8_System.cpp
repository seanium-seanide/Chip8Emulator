/**
 * @file Chip8_System.cpp
 *
 * @brief
 */

#include "Chip8_System.hpp"


namespace Chip8
{

System::System()
: m_registers()
, m_memory()
, m_systemReserved(0x0000, 0x01FF)
, m_cartridge(0x0200,0xFFF)
, m_framebuffer()
{
}

System::~System()
{
}

}   // namespace Chip8
