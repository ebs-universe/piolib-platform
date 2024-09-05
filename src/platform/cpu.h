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
 * @file platform/cpu.h
 * @brief Definitions for EBS CPU controls
 * 
 */


#ifndef PLATFORM_CPU_H
#define PLATFORM_CPU_H


#if defined __AVR__
    #include <avr/interrupt.h>
    static inline void global_interrupt_enable(void){
        sei();
    }
    
    static inline void global_interrupt_disable(void){
        cli();
    }
#elif defined __MSP430__
    #include <msp430.h>
    static inline void global_interrupt_enable(void){
        __eint();
    }
    
    static inline void global_interrupt_disable(void){
        __dint();
    }
#elif defined __arm__
    #include "stm32f4xx.h"
    static inline void global_interrupt_enable(void){
        __enable_irq();
    }
    
    static inline void global_interrupt_disable(void){
        __disable_irq();
    }
#endif

static inline void critical_enter(void){
    global_interrupt_disable();
}

static inline void critical_exit(void){
    global_interrupt_enable();
}

#endif


