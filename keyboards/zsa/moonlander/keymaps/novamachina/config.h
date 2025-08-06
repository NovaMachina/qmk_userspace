/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define myLayout(\
    kL0A, kL0B, kL0C, kL0D, kL0E, kL0F, kL0G, \
    kL1A, kL1B, kL1C, kL1D, kL1E, kL1F, kL1G, \
    kL2A, kL2B, kL2C, kL2D, kL2E, kL2F, kL2G, \
    kL3A, kL3B, kL3C, kL3D, kL3E, kL3F, \
    kL4A, kL4B, kL4C, kL4D, kL4E, \
    kLR, \
    kLTT, KLMT, KLBT, \
    kR0A, kR0B, kR0C, kR0D, kR0E, kR0F, kR0G, \
    kR1A, kR1B, kR1C, kR1D, kR1E, kR1F, kR1G, \
    kR2A, kR2B, kR2C, kR2D, kR2E, kR2F, kR2G, \
    kR3A, kR3B, kR3C, kR3D, kR3E, kR3F, \
    kR4A, kR4B, kR4C, kR4D, kR4E, \
    kRR, \
    kRTT, KRMT, KRBT) { \
    /*left*/\
    {kL0A, kL0B, kL0C, kL0D, kL0E, kL0F, kL0G}, \
    {kL1A, kL1B, kL1C, kL1D, kL1E, kL1F, kL1G}, \
    {kL2A, kL2B, kL2C, kL2D, kL2E, kL2F, kL2G}, \
    {kL3A, kL3B, kL3C, kL3D, kL3E, kL3F, KC_NO}, \
    {kL4A, kL4B, kL4C, kL4D, kL4E, KC_NO, KC_NO}, \
    {kLTT, KLMT, KLBT, kLR, KC_NO, KC_NO, KC_NO}, /*top thumb, middle thumb, bottom thumb, red key*/ \
    /*right*/\
    {kR0A, kR0B, kR0C, kR0D, kR0E, kR0F, kR0G}, \
    {kR1A, kR1B, kR1C, kR1D, kR1E, kR1F, kR1G}, \
    {kR2A, kR2B, kR2C, kR2D, kR2E, kR2F, kR2G}, \
    {KC_NO, kR3A, kR3B, kR3C, kR3D, kR3E, kR3F}, \
    {KC_NO, KC_NO, kR4A, kR4B, kR4C, kR4D, kR4E}, \
    {KC_NO, KC_NO, KC_NO, kRR, KRBT, KRMT, kRTT} /*red key, top thumb, middle thumb, bottom thumb*/ \
}

#define RGB(r,g,b) {r,g,b}

#define myLayout_led(\
    kL0A, kL0B, kL0C, kL0D, kL0E, kL0F, kL0G, \
    kL1A, kL1B, kL1C, kL1D, kL1E, kL1F, kL1G, \
    kL2A, kL2B, kL2C, kL2D, kL2E, kL2F, kL2G, \
    kL3A, kL3B, kL3C, kL3D, kL3E, kL3F, \
    kL4A, kL4B, kL4C, kL4D, kL4E, \
    kLR, \
    kLTT, kLMT, kLBT, \
    kR0A, kR0B, kR0C, kR0D, kR0E, kR0F, kR0G, \
    kR1A, kR1B, kR1C, kR1D, kR1E, kR1F, kR1G, \
    kR2A, kR2B, kR2C, kR2D, kR2E, kR2F, kR2G, \
    kR3A, kR3B, kR3C, kR3D, kR3E, kR3F, \
    kR4A, kR4B, kR4C, kR4D, kR4E, \
    kRR, \
    kRTT, kRMT, kRBT) { \
    /*left*/\
    kL0A, kL1A, kL2A, kL3A, kL4A, \
    kL0B, kL1B, kL2B, kL3B, kL4B, \
    kL0C, kL1C, kL2C, kL3C, kL4C, \
    kL0D, kL1D, kL2D, kL3D, kL4D, \
    kL0E, kL1E, kL2E, kL3E, kL4E, \
    kL0F, kL1F, kL2F, kL3F, \
    kL0G, kL1G, kL2G, \
    kLTT, kLMT, kLBT,kLR, \
    /*right*/\
    kR0A, kR1A, kR2A, kR3A, kR4A, \
    kR0B, kR1B, kR2B, kR3B, kR4B, \
    kR0C, kR1C, kR2C, kR3C, kR4C, \
    kR0D, kR1D, kR2D, kR3D, kR4D, \
    kR0E, kR1E, kR2E, kR3E, kR4E, \
    kR0F, kR1F, kR2F, kR3F, \
    kR0G, kR1G, kR2G, \
    kRTT, kRMT, kRBT, kRR, \
}
