

#include <stdint.h>

#ifdef GCC_AVR
    #include <avr/pgmspace.h>
    #define ROMEM                   PROGMEM
    #define ROMEM_TABLE_P(_t)       _t
    #define ROMEM_READ_WORD(addr)   pgm_read_word(addr)
    #define ROMEM_READ_DWORD(addr)  pgm_read_dword(addr)
    #define ROMEM_READ_BYTE(addr)   pgm_read_byte(addr)
#else
    #define ROMEM  
    #define ROMEM_TABLE_P(_t)       &(_t[0])
    #define ROMEM_READ_WORD(addr)   *(uint16_t *)(addr)
    #define ROMEM_READ_DWORD(addr)  *(uint32_t *)(addr)
    #define ROMEM_READ_BYTE(addr)   *(uint8_t  *)(addr)
#endif