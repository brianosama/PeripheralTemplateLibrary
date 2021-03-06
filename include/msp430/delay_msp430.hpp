#include <stdint.h>

namespace PTL {

class Delay
{
public:
    typedef uint32_t width;

    static void delay(width cycles)
    {
        // call to here: 5 cycles
        // - 4 below because we do post-check, so with 0 we do 1 iteration
        cycles -= 5 + 3 + 5 + 3 - 4; // 3 clocks
        cycles >>= 2; // 5 instructions, 5 cycles
        asm(
            "mov    %A0, r14 \n"
            "mov    %B0, r15 \n"
            "1: \n"
            "sub    #1, r14 \n" // 1 cycle
            "subc   #0, r15 \n" // 1 cycle
            "jc    1b \n" // 2 cycles, msp430 has weird C flag value for subtracts
            : : "ir" (cycles) : "r14", "r15"
        );
        // ret: 3 cycles
    }
};

} // namespace
