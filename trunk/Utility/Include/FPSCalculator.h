#ifndef FPS_CALCULATOR_H
#define FPS_CALCULATOR_H


#include "Clock.h"

namespace engine {

class FPSCalculator {
public:
	FPSCalculator ();

	void		CalcFPS (void);
	short		GetFPS (void);

private:
	short		fps;
	short		fpsCounter;
	timestamp_t	elapsedTime;
};

}	//namespace engine

#endif //FPS_CALCULATOR_H