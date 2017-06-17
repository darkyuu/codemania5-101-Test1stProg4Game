#ifndef __SLIDERPUZZLEGAMEMANAGER_H__
#define __SLIDERPUZZLEGAMEMANAGER_H__

#include <iostream>

#include "Game.h"

class SliderPuzzleGameManager {
public:
	static GAMEMODE m_gameMode;
	static char m_writeablePath[128];
	static GAMESAVE sramData;
	
	static std::string GetTimeUsageInMMSS(int timeFrameVal);
};


#endif // __SLIDERPUZZLEGAMEMANAGER_H__