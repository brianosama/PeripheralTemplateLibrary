
#ifndef _GPIO_ADUCM3029_HPP
#define _GPIO_ADUCM3029_HPP

#include <gpio_base.hpp>
#include <bits.hpp>
#include <aducm3029/includes_aducm3029.hpp>

namespace PTL {
	
template <int base_, typename width_>
class Port : public IPort<width_>
{
	
public:
	typedef width_ width;
	static const int base = base_;
	static ADI_GPIO_TypeDef *ptr() { return (ADI_GPIO_TypeDef *) base; }
	
	static void enable() { }	
	
	static width value() {
		return ptr()->IN;
	}
	
    static void set(width val){
		ptr()->OUT = val;
	}
};

typedef Port<ADI_GPIO0_BASE, uint16_t> GPIO0;
typedef Port<ADI_GPIO1_BASE, uint16_t> GPIO1;
typedef Port<ADI_GPIO2_BASE, uint16_t> GPIO2;
	
template <class port, class bit>
class Pin : public PortPin< Pin<port, bit>, port, bit >
{	
public:

	static void input() {
		port::ptr()->IEN |= bit::value;
	}
	
	static void output() {
		port::ptr()->OEN |= bit::value;
	}
	
    static void high() {
		port::ptr()->SET |= bit::value;
	}
	
    static void low()  {
		port::ptr()->CLR |= bit::value;
	}
	
    static void toggle() {
		port::ptr()->TGL |= bit::value;
	}
	
    static void disable()
    {
		port::ptr()->IEN &= ~bit::value;
        port::ptr()->OEN &= ~bit::value;
    }
};	
	
}

#endif