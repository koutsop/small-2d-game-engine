#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <allegro5/allegro_audio.h>

namespace engine {

enum AudioPlayMode {
	PlayModeONCE	= ALLEGRO_PLAYMODE_ONCE,
	PlayModeLOOP	= ALLEGRO_PLAYMODE_LOOP,
	PlayModeBIDIR	= ALLEGRO_PLAYMODE_BIDIR
};

class Audio {
public:
	Audio (const std::string path);
	
	static void Initialise (void);
	static void CleanUp (void);
	static void StopAll (void);
	static void SetReserveNumber (int number);
	static int	GetReserveNumber (void);

	void		Play (AudioPlayMode mode);
	void		Stop (void);
private:
	static int			reserveNumber;
	ALLEGRO_SAMPLE_ID	id;
	ALLEGRO_SAMPLE *	data;
	
};

}	//engine


#endif	//AUDIO_H