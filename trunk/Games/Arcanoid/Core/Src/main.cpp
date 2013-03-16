#include "Audio.h"
#include "Arcanoid.h"
#include "Graphics.h"
#include "KeyboardInput.h"

int main(int argc, char **argv) {
	engine::InitialiseGraphics();
	engine::Font::Initialise();
	engine::Audio::Initialise();
	engine::KeyboardInput::Initialise();

	//The bitmaps should be destroyed beffore the CleanUpGraphics
	//If we use a stack object the we will have a crash
	Arcanoid * game = new Arcanoid();
	game->Start("./../../Resources/configFiles/game.cfg");
	delete game;

	engine::Font::CleanUp();
	engine::Audio::CleanUp();
	engine::KeyboardInput::CleanUp();
	engine::CleanUpGraphics();
}

