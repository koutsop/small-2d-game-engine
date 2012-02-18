#include <iostream>
#include "FPSCalculator.h"

namespace engine {

unsigned int	FPSCalculator::fps	= 0;
timestamp_t		FPSCalculator::msec = 0;

void FPSCalculator::FPS (void) {
	timestamp_t currTime = Clock::GetSystemTime();
	
	if (!msec)  
		msec = currTime;
	else
	if (Clock::DiffTimeInSec(currTime, msec) >= 1) {//upologizoume an perase ena sec
		std::cout << "fps: " << fps << std::endl;
		fps		= 0;
		msec	= 0;
	}
	++fps;
}


}