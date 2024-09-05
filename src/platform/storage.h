
/* 
   Copyright (c)
     (c) 2024 Chintalagiri Shashank, Quazar Technologies Pvt. Ltd.
   
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
 * @file platform/nvstorage.h
 * @brief Definitions for EBS storage interfaces
 * 
 */


#ifndef PLATFORM_STORAGE_H
#define PLATFORM_STORAGE_H

#include <stdint.h>
#include "types.h"

typedef struct PLUGGABLE_STORAGE_t
{
    HAL_BASE_t volume;
    HAL_BASE_t size; 
    void (*const init) (HAL_BASE_t);
    HAL_BASE_t (*const ready) (HAL_BASE_t);
    HAL_BASE_t (*const write_byte) (HAL_BASE_t, uint16_t, uint8_t); 
    uint8_t (*const read_byte) (HAL_BASE_t, uint16_t); 
    HAL_BASE_t (*const write) (HAL_BASE_t, uint16_t, const void *, HAL_BASE_t);
    HAL_BASE_t (*const read) (HAL_BASE_t, uint16_t, void *, HAL_BASE_t);
    HAL_BASE_t (*const format) (HAL_BASE_t);
}pluggable_storage_t;

#endif
