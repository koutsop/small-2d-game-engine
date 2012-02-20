#ifndef FPS_CALCULATOR_H
#define FPS_CALCULATOR_H


#include "Clock.h"

namespace engine {

class FPSCalculator {
public:
	static void CalcFPS (void);
	static short GetFPS (void);

private:
	static short		fps;
	static short		fpsCounter;
	static timestamp_t	elapsedTime;
};

}	//namespace engine

#endif //FPS_CALCULATOR_H