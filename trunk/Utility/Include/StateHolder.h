#ifndef STATE_HOLDER_H
#define STATE_HOLDER_H

#include <map>
#include <string>

namespace engine {

class StateHolder {
public:
	static void Run (void);
	static bool IsRunning (void);

	static void Pause (void);
	static bool IsPaused (void);

	static void Finish (void);
	static bool IsFinished (void);

	static void RegisterState (const std::string & stateId);
	static bool	IsStateExists (const std::string & stateId);
	static bool	IsInState (const std::string & stateId);
	static void	ActivateState (const std::string & stateId);
	static void InactivateState (const std::string & stateId);

private:
	typedef std::map<std::string, bool> States;
	enum GameState {
		StateRUNNING	= 0,
		StatePAUSED		= 1,
		StateFINISHED	= 2,
		StateNONE	
	};

	static States		states;		//user difine state
	static GameState	gameState;

};

}	//namespace engine


#endif	//STATE_HOLDER_H