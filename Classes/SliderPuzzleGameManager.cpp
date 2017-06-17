#include "SliderPuzzleGameManager.h"

#include <stdio.h>

GAMEMODE SliderPuzzleGameManager::m_gameMode = GAMEMODE_NONE;
char  SliderPuzzleGameManager::m_writeablePath[128] = {' '};
GAMESAVE SliderPuzzleGameManager::sramData = {-1, -1 , -1};

std::string SliderPuzzleGameManager::GetTimeUsageInMMSS(int timeFrameVal) {
	char buff[100];
	std::string result;
	int tempTime, min, sec;

	tempTime = timeFrameVal;
	min = tempTime / 3600;
	tempTime -= min*3600;
	sec = tempTime / 60;
	sprintf(buff, "%02d:%02d", min, sec);
	result = buff;
	return result;
}