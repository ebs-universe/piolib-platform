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

#include <stdint.h>

#ifdef __AVR__
    #include <avr/pgmspace.h>
    #define ROMEM                   PROGMEM
    #define ROMEM_TABLE_P(_t)       _t
    #define ROMEM_READ_WORD(addr)   pgm_read_word(addr)
    #define ROMEM_READ_DWORD(addr)  pgm_read_dword(addr)
    #define ROMEM_READ_BYTE(addr)   pgm_read_byte(addr)
#elif defined __MSP430__
    #define ROMEM  
    #define ROMEM_TABLE_P(_t)       &(_t[0])
    #define ROMEM_READ_WORD(addr)   *(uint16_t *)(addr)
    #define ROMEM_READ_DWORD(addr)  *(uint32_t *)(addr)
    #define ROMEM_READ_BYTE(addr)   *(uint8_t  *)(addr)
#endif