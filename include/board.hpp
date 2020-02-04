/*
 * This file is part of the Peripheral Template Library project.
 *
 * Copyright (c) 2012 Paul Sokolovsky <pfalcon@users.sourceforge.net>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
// TODO: Selecting board based on CPU is very rough
#if defined(__MSP430__)
#include <board_launchpad_msp430.hpp>
#elif defined(__AVR__)
#include <board_arduino.hpp>
#elif defined(__STM32__)
#include <board_stm32vldiscovery.hpp>
#elif defined(__EFM32__)
#include <board_efm32gg_stk3700.hpp>
#elif defined(__LM4__)
#include <board_launchpad_stellaris.hpp>
#elif defined(__ADICUP3029__)
#include <board_adicup3029.hpp>
#else
#error Unknown platform in board.hpp
#endif
