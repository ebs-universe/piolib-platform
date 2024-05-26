
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

#include<stdint.h>

#ifdef GCC_MSP430

typedef uint8_t HAL_BASE_t;
typedef uint16_t HAL_INT_t;
typedef volatile uint16_t HAL_SFR_t;
typedef uint16_t HAL_ADDRESS_t;
typedef uint8_t PORTSELECTOR_t;
typedef uint16_t PINSELECTOR_t;

#endif
