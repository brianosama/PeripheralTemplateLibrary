#ifndef _BOARD_ADICUP3029_HPP
#define _BOARD_ADICUP3029_HPP

#include <board_base.hpp>
#include <gpio.hpp>
#include <clock.hpp>

namespace PTL {

class ADICUP3029 {};

template <>
class Board<ADICUP3029>
{
public:
    // green led DS3
    typedef Pin<GPIO2, Bit0> LED;
    // blue led DS4
    typedef Pin<GPIO1, Bit15> LED2;
		
    static const long freq = 6.5 MHZ;
};

typedef Board<ADICUP3029> board;

}

#endif