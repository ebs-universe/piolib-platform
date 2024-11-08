

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


void die(void) {
    global_interrupt_disable();
    #ifdef __arm__
    CFSR_t cfsr = (CFSR_t)(*((HAL_SFR_t *)0xE000ED28));
    (void) cfsr;
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
