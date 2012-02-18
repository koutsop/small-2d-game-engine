#ifndef FPS_CALCULATOR_H
#define FPS_CALCULATOR_H


#include "Clock.h"

namespace engine {

class FPSCalculator {
public:
	static void FPS (void);

private:
	static unsigned int	fps;
	static timestamp_t	msec;
};

}	//namespace engine

#endif //FPS_CALCULATOR_H