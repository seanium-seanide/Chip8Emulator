#pragma once

/**
 * @file Chip8_MemoryRegion.hpp
 *
 * @brief
 */


#include <cstdint>


namespace Chip8
{

class MemoryRegion
{
public:

  MemoryRegion(std::size_t minIndex, std::size_t maxIndex);
  ~MemoryRegion();


  /**
   * @brief
   */
  std::size_t getMinIndex();

  /**
   * @brief
   */
  std::size_t getMaxIndex();


  /**
   * @brief
   */
  void storeBlock(std::size_t regionStart, uint8_t *blockStart, std::size_t blockSize);

private:

  // TODO: Friend function for Chip8::Memory to pass pointer to base address

  std::size_t m_minIndex;
  std::size_t m_maxIndex;

};  // class MemoryRegion

}   // namespace Chip8
