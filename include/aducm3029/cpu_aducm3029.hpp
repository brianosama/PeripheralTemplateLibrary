#include <cortex-m/cpu_cortexm.hpp>
#include "includes_aducm3029.hpp"

namespace PTL {

class ADUCM3029 {};

template <>
class CPU<ADUCM3029> : public CPU<CortexMCPU>
{

public:
	static void init(int flags)
    {
		
    }
};

typedef CPU<ADUCM3029> cpu;

}