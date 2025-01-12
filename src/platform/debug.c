

#include "cpu.h"
#include "debug.h"
#include "types.h"
#include <application.h>

#if APP_ENABLE_OUTPUT_ERROR
#include <hal/uc/gpio.h>
#endif

#ifdef __arm__

typedef union {
    struct {
        uint8_t MMFSR;
        uint8_t BFSR;
        uint16_t UFSR;
    };
    uint32_t CFSR;
} CFSR_t;

#endif

#pragma GCC push_options 
#pragma GCC optimize("O0")


void die(void) {
    global_interrupt_disable();
    #ifdef __arm__
    CFSR_t cfsr = (CFSR_t)(*((HAL_SFR_t *)0xE000ED28));
    (void) cfsr;
    uint32_t bfar = *((HAL_SFR_t *)0xE000ED38);
    (void) bfar;
    #endif
    #if APP_ENABLE_OUTPUT_ERROR
        #if ERROR_POLARITY
        gpio_set_output_high(ERROR_GPIO);
    #else           
        gpio_set_output_low(ERROR_GPIO);
        #endif
    #endif
    while(1);
}

#pragma GCC pop_options 

#if DEBUG_TRANSPORT_TYPE == EBS_INTF_UART
#include <hal/uc/uart.h>

#define LOCKTOKEN   0x00

HAL_BASE_t _debug_putchar(char c){
    if (uart_reqlock(DEBUG_TRANSPORT_INTFNUM, 1, LOCKTOKEN)){
        return uart_putc(DEBUG_TRANSPORT_INTFNUM, c, LOCKTOKEN, 0x00);
    }
    uart_send_trigger(DEBUG_TRANSPORT_INTFNUM);
    return 0;
}

HAL_BASE_t _debug_write(const void *buffer, HAL_BASE_t len){
    if (uart_reqlock(DEBUG_TRANSPORT_INTFNUM, len, LOCKTOKEN)){
        return uart_write(DEBUG_TRANSPORT_INTFNUM, (uint8_t *)buffer, len, LOCKTOKEN);
    }
    uart_send_trigger(DEBUG_TRANSPORT_INTFNUM);
    return 0;
}

HAL_BASE_t _debug_printf(const char *format, va_list args){
    return uart_vprintf(DEBUG_TRANSPORT_INTFNUM, format, args);
}

void _debug_flush(void){
    uart_send_flush(DEBUG_TRANSPORT_INTFNUM);
}

#elif DEBUG_TRANSPORT_TYPE == EBS_INTF_USBCDC
#include <hal/uc/usbcdc.h>

HAL_BASE_t _debug_putchar(char c){

}

HAL_BASE_t _debug_write(const void *buffer, HAL_BASE_t len){

}

HAL_BASE_t _debug_printf(const char *format, ...){

}

void _debug_flush(void){

}

#endif
