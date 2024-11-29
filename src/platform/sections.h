/*
 * section   | speed  | execute | shared | cached | buffered | DMA | ISR 
 * ----------|--------|---------|--------|--------|----------|-----|----
 * FASTDATA  | Fast   | No      | No     | No     | No       | No  | Yes
 * FASTEXEC  | Fast   | Yes     | No     | No     | No       | No  | Yes
 * SHAREDATA | Normal | No      | Yes    | No     | No       | Yes | Yes
 * <default> | Normal | Yes     | Yes    | Likely | Likely   | No  | No
 * 
 * Memory sections should be created based on each sections capabilities, 
 * specifically, with attention to: 
 *   - DMA R/W safety without any special cache coherence effort
 *   - ISR R/W safety without any special cache coherence effort
 * 
 * If the platform needs no special considerations for any of these, 
 * the names should still be defined but the content can be blank.
 * 
 * Applications and libraries should prepend these to appropriate 
 * definitions when the following conditions are met, for each 
 * individual variable / function : 
 * 
 *   - Variable R/W in ISR context + DMA context : SHARED
 *   - Variable R/W in DMA context only : SHARED
 *   - Variable R/W in ISR context only : DTCM
 *   - Variable R/W in regular context only, high frequency : DTCM
 *   - Variable R/W in regular context only, low frequency  : <default>
 * 
 *   - Function executes in ISR context : ITCM
 *   - Function executes in regular context only, high frequency : ITCM
 *   - Function executes in regular context only, low frequency : <default>
 * 
 * Note: The stack and heap presently exist in DTCM on the stm32 h7rsxx 
 * linker file, so we might not be able to DMA to/from malloc defined 
 * variables. Consider reconfiguring malloc to use SHARED or another 
 * DMA-accessible region if possible, ideally optionally.
 *
 * TODO: 
 * 
 * HPDMA in CM7 might be able to write to DTCM. If that is the case 
 * for the platform, then it may be ok to put SHARED memory into DTCM 
 * as well, as long as we can ensure HPDMA-only usage. We presently 
 * don't try to do this, and it's unclear what other constraints exist.
 */

#include <iomap.h>

#if MEMMAP_ENABLE_FASTDATA
    #define FASTDATA    __attribute__((section(".dtcm")))
#else 
    #define FASTDATA
#endif

#if MEMMAP_ENABLE_FASTEXEC 
    #define FASTEXEC    __attribute__((section(".itcm")))
#else 
    #define FASTEXEC
#endif

#if MEMMAP_ENABLE_SHAREDATA
    #define SHAREDATA  
#else
    #define SHAREDATA  
#endif
