/*
 * section   | speed  | execute | shared | cached | buffered | DMA | ISR 
 * ----------|--------|---------|--------|--------|----------|-----|----
 * FASTDATA  | Fast   | No      | No     | No     | No       | Yes | Yes
 * FASTEXEC  | Fast   | Yes     | No     | No     | No       | No  | Yes
 * SHAREDATA | Normal | No      | Yes    | No     | No       | Yes | Yes
 * ROMEM     | Normal | No      | Yes    | Likely | Likely   | Yes | Yes
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
 * Applications and libraries should prepend these for each individual 
 * variable / function : 
 * 
 *   - Variable R/W in ISR + DMA + Cortex contexts : SHAREDATA
 *   - Variable R/W in DMA + Cortex contexts only : FASTDATA / SHAREDATA
 *   - Variable R/W in ISR + Cortex contexts only : FASTDATA / SHAREDATA
 *   - Variable R/W in Cortex context only, high frequency : FASTDATA
 *   - Variable R/W in Cortex context only, low frequency  : <default>
 * 
 *   - Function executes in ISR context : FASTEXEC
 *   - Function executes in Cortex context only, high frequency : FASTEXEC
 *   - Function executes in Cortex context only, low frequency : <default>
 * 
 *   - Constant data stored in flash : ROMEM (to migrate from romem.h)
 * 
 * These are tentative definitions which might need additional review. The 
 * following open questions must be addressed: 
 * 
 *   - It is unclear whether DMA can always access FASTDATA
 *   - It is unclear whether FASTDATA is ok for data accessed in DMA 
 *     and ISR contexts
 * 
 * The implementation of this is as follows: 
 * 
 * STM32H7RS
 * ---------
 *   - FASTDATA is DTCM. This is non-cached, non-shared core coupled memory.
 *     It can be accessed from an interrupt context and probably can be 
 *     accessed from a DMA context, though there seem to be conflicting 
 *     information about this. Variables should be treated as volatile
 *     when being accessed from the Cortex, if the DMA / Interrupt are 
 *     expected to write to them. (.dtcm)
 *
 *   - FASTEXEC is ITCM. This non-cached, non-shared core coupled memory. It
 *     can be used in an interrupt context. (.itcm)
 * 
 *   - SHAREDATA is non-cached, shared regular RAM in a separate section. 
 *     The linker file should put this in a memory region where prefetch 
 *     and caching are disbaled in the MPU. It can perhaps also be placed 
 *     into the 16kb SRAM1/2 if it needs to be on AHB instead of AXI. This 
 *     could perhaps be used to store data which is handled by the DMA and 
 *     within interrupt contexts, when the data is large but slow enough 
 *     or where DTCM might hit other constraints. (.shared)
 * 
 *   - Default is cacheable RAM and FLASH. ICACHE and DCACHE are presently 
 *     not enabled, however, expect this to be enabled at some point.
 * 
 *   - ROMEM not implemented.
 * 
 *   - It seems HPDMA is suited to DTCM and the large SRAM1/2/3/4 on AXI, 
 *     while GPDMA is suited to the 16kb SRAM1/2 and AHB peripherals. 
 *     Details to be worked out. It may be necessary to add an additional
 *     section to be able to use this. For the moment, plan  is to use the 
 *     16kb SRAM1/2 for GPDMA use with SHAREDATA, while HPDMA can be used 
 *     with FASTDATA in DTCM.
 * 
 */

#ifndef PLATFORM_SECTIONS_H
#define PLATFORM_SECTIONS_H

#include <iomap.h>
#include "types.h"

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
    #define SHAREDATA  __attribute__((section(".shared")))
#else
    #define SHAREDATA  
#endif

bool memmap_check_fastmem(HAL_ADDRESS_t ptr);

#endif