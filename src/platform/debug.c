

#include "cpu.h"
#include "debug.h"

void die(void) {
    global_interrupt_disable();
    while(1);
}
