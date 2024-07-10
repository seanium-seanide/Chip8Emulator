#pragma once

/**
 * @file Chip8_config.hpp
 *
 * @brief
 */

#include <string>
#include <map>

#include <cstdint>

#include "Multimedia_config.hpp"


namespace Chip8
{

// Framebuffer

const std::string WINDOW_TITLE = "Chip-8";

const uint32_t WINDOW_WIDTH = 64;
const uint32_t WINDOW_HEIGHT = 32;
const uint32_t WINDOW_PIXEL_SIZE = 10;

// Keypad

// TODO: Change to enum
// TODO: Typedef key type
constexpr uint8_t KEY_0 = 0x00;
constexpr uint8_t KEY_1 = 0x01;
constexpr uint8_t KEY_2 = 0x02;
constexpr uint8_t KEY_3 = 0x03;
constexpr uint8_t KEY_4 = 0x04;
constexpr uint8_t KEY_5 = 0x05;
constexpr uint8_t KEY_6 = 0x06;
constexpr uint8_t KEY_7 = 0x07;
constexpr uint8_t KEY_8 = 0x08;
constexpr uint8_t KEY_9 = 0x09;
constexpr uint8_t KEY_A = 0x0A;
constexpr uint8_t KEY_B = 0x0B;
constexpr uint8_t KEY_C = 0x0C;
constexpr uint8_t KEY_D = 0x0D;
constexpr uint8_t KEY_E = 0x0E;
constexpr uint8_t KEY_F = 0x0F;

const std::map<uint8_t, uint16_t> KEYMAP = {
  {KEY_1, Multimedia::KEY_1}, {KEY_2, Multimedia::KEY_2}, {KEY_3, Multimedia::KEY_3}, {KEY_C, Multimedia::KEY_4}
, {KEY_4, Multimedia::KEY_Q}, {KEY_5, Multimedia::KEY_W}, {KEY_6, Multimedia::KEY_E}, {KEY_D, Multimedia::KEY_R}
, {KEY_7, Multimedia::KEY_A}, {KEY_8, Multimedia::KEY_S}, {KEY_9, Multimedia::KEY_D}, {KEY_E, Multimedia::KEY_F}
, {KEY_A, Multimedia::KEY_Z}, {KEY_0, Multimedia::KEY_X}, {KEY_B, Multimedia::KEY_C}, {KEY_F, Multimedia::KEY_V}
};

// Memory

constexpr uint16_t MEMORY_SIZE = 4096;

// System reserved: characters


}   // namespace Chip8
