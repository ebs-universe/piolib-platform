
#ifndef PLATFORM_CONSTANTS_H
#define PLATFORM_CONSTANTS_H

#include <stdbool.h>

// For legacy support before the inclusion of stdbool.h
#define EBS_FALSE  false
#define EBS_TRUE   true

typedef bool EBS_BOOL_t;

// M_PI does not always seem to be defined? 
#ifndef M_PI
    #define M_PI 3.141592653589793238462643383279502984
#endif
#ifndef M_PI_L
    #define M_PI_L 3.141592653589793238462643383279502984L
#endif

#endif
