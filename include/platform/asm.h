/* 
   Copyright (c)
     (c) 2018 Chintalagiri Shashank, Quazar Technologies Pvt. Ltd.
   
   This file is part of
   Embedded bootstraps : platform library
   
   This library is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/

/**
 * @file platform/asm.h
 * @brief Helper Definitions for ASM files
 * 
 * Base assembly files on :
 * 
 * MSP430 : 
 * msp430-elf-gcc -S [source[.c -fverbose-asm -fdata-sections -ffunction-sections
 *
 */

#ifndef PLATFORM_ASM_H
#define PLATFORM_ASM_H

#ifdef __MSP430__

#define PC  r0   
#define SP  r1
#define SR  r2

#endif
#endif
