#include <iostream>
#include "FPSCalculator.h"

namespace engine {

FPSCalculator::FPSCalculator () 
:	fps			(0),
	fpsCounter	(0),
	elapsedTime	(0)
{}

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