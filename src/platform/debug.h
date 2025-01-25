

#ifndef DEBUG_H
#define DEBUG_H

#include <application.h>
#include <stdarg.h>
#include "types.h"


void die(void);

#if APP_ENABLE_DEBUG

HAL_BASE_t _debug_putchar(char c);
HAL_BASE_t _debug_write(const void *buffer, HAL_BASE_t len);
HAL_BASE_t _debug_printf(const char *format, va_list args);
void _debug_flush(void);

static inline HAL_BASE_t debug_putchar(char c) {
    return _debug_putchar(c);
}

static inline HAL_BASE_t debug_write(const void *buffer, HAL_BASE_t len){
    return _debug_write(buffer, len);
}

static inline HAL_BASE_t debug_printf(const char *format, ...){
    uint8_t rval;
    va_list args;       
    va_start( args, format );
    rval = _debug_printf(format, args);
    va_end(args);
    return rval;
}

static inline void debug_flush(void){
    _debug_flush();
}

#else

static inline HAL_BASE_t debug_putchar(char c) {
    return 0;
}

static inline HAL_BASE_t debug_write(const void *buffer, HAL_BASE_t len){
    return 0;
}

static inline HAL_BASE_t debug_printf(const char *format, ...){
    return 0;
}

static inline void debug_flush(void){}

#endif 

#endif
