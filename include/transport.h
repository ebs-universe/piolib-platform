
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
 * @file platform/transport.h
 * @brief Definitions for EBS transports
 * 
 */


#ifndef PLATFORM_TRANSPORT_H
#define PLATFORM_TRANSPORT_H

#include <stdint.h>

typedef struct PLUGGABLE_TRANSPORT_t
{
    void (*const init) (uint8_t);
    uint8_t (*const unhandled_rxb) (uint8_t); 
    uint8_t (*const read) (uint8_t, uint8_t *, uint8_t); 
    uint8_t (*const reqlock) (uint8_t, uint8_t, uint8_t); 
    uint8_t (*const rellock) (uint8_t, uint8_t); 
    uint8_t (*const write) (uint8_t, uint8_t *, uint8_t, uint8_t); 
    void (*const flush) (uint8_t);
}pluggable_transport_t;

#endif
