#pragma once

/**
 * @file Chip8_RegisterFile.hpp
 *
 * @brief
 */


#include <array>
#include <cstdint>


constexpr std::size_t NUM_GENERAL_PURPOSE_REGISTERS = 16;


namespace Chip8
{

class RegisterFile
{
public:

  RegisterFile();
  ~RegisterFile();

  /**
   * @brief Retrieve the value of a general purpose register by index.
   *
   * @param index Index of a general purpose register in the range 0x00 - 0x0F
   *
   * @return a const reference to the desired register.
   */
   const uint8_t &operator[](std::size_t index) const;

  /**
   * @brief Retrieve a general purpose register by index.
   *
   * @param index Index of a general purpose register in the range 0x00 - 0x0F
   *
   * @return a reference to the desired register.
   */
   uint8_t &operator[](std::size_t index);

private:

   std::array<uint8_t, NUM_GENERAL_PURPOSE_REGISTERS> m_generalPurposeRegisters;
   uint16_t m_delayTimer;
   uint16_t m_soundTimer;
   uint16_t m_programCounter;
   uint8_t m_stackPointer;

};  // class RegisterFile

}   // namesapce Chip8
