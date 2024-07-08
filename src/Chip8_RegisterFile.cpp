/**
 * @file Chip8_RegisterFile.cpp
 *
 * @brief
 */

#include "Chip8_RegisterFile.hpp"

#include <stdexcept>
#include <cstring>


namespace Chip8
{

RegisterFile::RegisterFile()
: m_generalPurposeRegisters()
, m_delayTimer(0x0000)
, m_soundTimer(0x0000)
, m_programCounter(0x0000)
, m_stackPointer(0x00)
{
  std::memset(m_generalPurposeRegisters.data(), 0x00, NUM_GENERAL_PURPOSE_REGISTERS);

  static_cast<void>(m_delayTimer);
  static_cast<void>(m_soundTimer);
  static_cast<void>(m_programCounter);
  static_cast<void>(m_stackPointer);
}

RegisterFile::~RegisterFile()
{
}


const uint8_t &RegisterFile::operator[](std::size_t index) const
{
  if (index > NUM_GENERAL_PURPOSE_REGISTERS)
  {
    throw std::out_of_range("Invalid register index");
  }

  return m_generalPurposeRegisters[index];
}

uint8_t &RegisterFile::operator[](std::size_t index)
{
  return const_cast<uint8_t &>(
    static_cast<const RegisterFile &>(*this)[index]
  );
}

}   // namesapce Chip8
