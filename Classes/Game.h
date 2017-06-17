#ifndef __GAME_H__
#define __GAME_H__

typedef enum {
	GAMEMODE_NONE = -1,
	GAMEMODE_PLAY = 0,
	GAMEMODE_RESULT
}GAMEMODE;


typedef enum {
	FIELD3X3 = 0
}GAMEPLAYMODE;

const int GAMESQUAREFIELDSIZE[] = {
	3
};

struct GAMESAVE {
	int header;
	int timeUsage;
	int footer;
};

#define SAVEFILE_HEADER 12345
#define FIRST_TOUCH_TIMEFRAME -1
#define SAVEFILE_FOOTER 54321

#define GAMESAVE_NAME "gmesav.bin"
#define GAMEFONT_PATH "fonts/Marker Felt.ttf"
	
#endif
