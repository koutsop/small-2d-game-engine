#include "Audio.h"
#include "Arcanoid.h"
#include "Graphics.h"
#include "KeyboardInput.h"

int main(int argc, char **argv) {
	engine::InitialiseGraphics();
	engine::Font::Initialise();
	engine::Audio::Initialise();
	engine::KeyboardInput::Initialise();

	Arcanoid * game = new Arcanoid();
	game->Start(".\\..\\configsFiles\\game.cfg");
	delete game;

	engine::Font::CleanUp();
	engine::Audio::CleanUp();
	engine::KeyboardInput::CleanUp();
	engine::CleanUpGraphics();
}

