#pragma once

/**
 * @file Multimedia_config.hpp
 *
 * @brief
 */

#include <cstdint>


namespace Multimedia
{

// Video

constexpr uint32_t NUM_KEYS = (1 << 8);

// TODO: Change to enum
// TODO: Typedef key type
constexpr uint8_t KEY_ESCAPE = 0x1B;
constexpr uint8_t KEY_1 = '1';
constexpr uint8_t KEY_2 = '2';
constexpr uint8_t KEY_3 = '3';
constexpr uint8_t KEY_4 = '4';
constexpr uint8_t KEY_Q = 'Q';
constexpr uint8_t KEY_W = 'W';
constexpr uint8_t KEY_E = 'E';
constexpr uint8_t KEY_R = 'R';
constexpr uint8_t KEY_A = 'A';
constexpr uint8_t KEY_S = 'S';
constexpr uint8_t KEY_D = 'D';
constexpr uint8_t KEY_F = 'F';
constexpr uint8_t KEY_Z = 'Z';
constexpr uint8_t KEY_X = 'X';
constexpr uint8_t KEY_C = 'C';
constexpr uint8_t KEY_V = 'V';

// Input

// R, G, B, A
constexpr uint32_t NUM_COLOUR_CHANNELS = 4;
constexpr uint32_t COLOUR_R = 0;
constexpr uint32_t COLOUR_G = 1;
constexpr uint32_t COLOUR_B = 2;
constexpr uint32_t COLOUR_A = 3;

}   // namespace Multimedia

