#include <assert.h>

#include "StateHolder.h"

namespace engine {

StateHolder::States		StateHolder::states;		//user difine state
StateHolder::GameState	StateHolder::gameState = StateNONE;

//---------------------------------------------------

void StateHolder::Run (void)
	{ gameState = StateRUNNING; }

//---------------------------------------------------

bool StateHolder::IsRunning (void)
	{ return gameState == StateRUNNING; }

//---------------------------------------------------

void StateHolder::Pause (void) 
	{ gameState = StatePAUSED; }

//---------------------------------------------------

bool StateHolder::IsPaused (void)
	{ return gameState == StatePAUSED; }

//---------------------------------------------------

void StateHolder::Finish (void)
	{ gameState = StateFINISHED; }

//---------------------------------------------------

bool StateHolder::IsFinished (void)
	{ return gameState == StateFINISHED; }

//---------------------------------------------------

void StateHolder::RegisterState (const std::string & stateId) 
	{ states[stateId] = false; }

//---------------------------------------------------

bool StateHolder::IsStateExists (const std::string & stateId) 
	{ return states.find(stateId) != states.end(); }

//---------------------------------------------------

bool StateHolder::IsInState (const std::string & stateId) {
	assert(IsStateExists(stateId));
	return states[stateId];
}

//---------------------------------------------------

void StateHolder::ActivateState (const std::string & stateId) {
	assert(IsStateExists(stateId));
	states[stateId] = true;
}

//---------------------------------------------------

void StateHolder::InactivateState (const std::string & stateId) {
	assert(IsStateExists(stateId));
	states[stateId] = false;	
}

}	//namespace engine