#include <cstdio>
#include <ctime>
#include "Clock.h"


namespace engine {

timestamp_t Clock::gameTime;

//-----------------------------------------------------------------------

void Clock::SetGameTime(void) 
	{ gameTime = std::clock(); }

//-----------------------------------------------------------------------

timestamp_t Clock::GetGameTime(void)
	{  return gameTime; }

//-----------------------------------------------------------------------

timestamp_t Clock::GetSystemTime(void)
	{ return std::clock(); }

//-----------------------------------------------------------------------

timestamp_t Clock::DiffTime(timestamp_t time2, timestamp_t time1)
	{ return (time2 - time1); }

//-----------------------------------------------------------------------

timestamp_t Clock::DiffTimeInSec(timestamp_t time2, timestamp_t time1)
	{ return (time2 - time1) / CLOCKS_PER_SEC; }
}