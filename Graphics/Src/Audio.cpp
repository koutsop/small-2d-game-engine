#include <assert.h>
#include <allegro5/allegro_acodec.h>
#include "Audio.h"
#include "GraphicsCommon.h"

namespace engine {

int	Audio::reserveNumber = 10;

//---------------------------------------------------

Audio::Audio (const std::string path) 
:	id(),
	data((ALLEGRO_SAMPLE *)0) {
	data = al_load_sample (path.c_str());
}

//---------------------------------------------------

void Audio::Initialise (void) {
	if (!al_is_audio_installed()) {
		reserveNumber = 10;
		CHECK_ALLEGRO_COMPONENT(al_install_audio());
		CHECK_ALLEGRO_COMPONENT(al_init_acodec_addon());
		CHECK_ALLEGRO_COMPONENT(al_reserve_samples(reserveNumber));
	}
}

//---------------------------------------------------

void Audio::CleanUp (void) {
	if (al_is_audio_installed())
		al_uninstall_audio();
}

//---------------------------------------------------

void Audio::StopAll (void) 
	{ al_stop_samples(); }

//---------------------------------------------------

void Audio::SetReserveNumber (int number) 
	{  CHECK_ALLEGRO_COMPONENT(al_reserve_samples(reserveNumber = number)); }

//---------------------------------------------------

int	Audio::GetReserveNumber (void) 
	{ return reserveNumber; }

//---------------------------------------------------

void Audio::Play (AudioPlayMode mode) { 
	assert(al_is_audio_installed());
	al_play_sample(data, 1.0, 0.0, 1.0, (ALLEGRO_PLAYMODE)mode, &id);	
}

//---------------------------------------------------

void Audio::Stop (void) 
	{ al_stop_sample(&id); }


}