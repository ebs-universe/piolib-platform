
#include<stdint.h>

#ifdef GCC_MSP430

typedef uint8_t HAL_BASE_t;
typedef uint16_t HAL_INT_t;
typedef volatile uint16_t HAL_SFR_t;
typedef uint16_t HAL_ADDRESS_t;
typedef uint8_t PORTSELECTOR_t;
typedef uint16_t PINSELECTOR_t;

#endif
