

#include "sections.h"

bool memmap_check_fastmem(HAL_ADDRESS_t ptr){
    #if MEMMAP_ENABLE_FASTDATA
        if (ptr >= MEMMAP_FASTDATA_START && ptr <= MEMMAP_FASTDATA_END){
            return true;
        }
    #endif
    #if MEMMAP_ENABLE_FASTEXEC
        if (ptr >= MEMMAP_FASTEXEC_START && ptr <= MEMMAP_FASTEXEC_END){
            return true;
        }
    #endif
    return false;
}
