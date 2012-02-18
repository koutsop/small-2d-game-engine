#ifndef CLOCK_H
#define CLOCK_H

namespace engine {
	
	
typedef unsigned long	timestamp_t;

class Clock {
public:
	static void			SetGameTime (void);
	static timestamp_t	GetGameTime (void);
	static timestamp_t	GetSystemTime (void);
	static timestamp_t	DiffTime (timestamp_t time2, timestamp_t time1);
	static timestamp_t	DiffTimeInSec (timestamp_t time2, timestamp_t time1);

private:
	static timestamp_t	gameTime;
};



}

#endif	//CLOCK_H