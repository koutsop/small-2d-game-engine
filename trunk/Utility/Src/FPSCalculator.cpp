#include <iostream>
#include "FPSCalculator.h"

namespace engine {

short			FPSCalculator::fps			= 0;
short			FPSCalculator::fpsCounter	= 0;
timestamp_t		FPSCalculator::elapsedTime	= 0;

//-----------------------------------------------------------------------

void FPSCalculator::CalcFPS (void) {
	++fpsCounter;
	elapsedTime += Clock::GetSystemTime() - Clock::GetGameTime();	

	if (elapsedTime >= 1000) {//upologizoume an perase ena sec
		fps			= fpsCounter;
		elapsedTime	= fpsCounter = 0;
	}
}

//-----------------------------------------------------------------------

short FPSCalculator::GetFPS (void)
	{ return fps; }


}