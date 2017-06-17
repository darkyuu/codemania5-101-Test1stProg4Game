#ifndef __SLIDERPUZZLEGAMEPLAY_H__
#define __SLIDERPUZZLEGAMEPLAY_H__

#include <stdio.h>
#include <string>
#include <vector>

#include "Game.h"
#include "MyColor4B.h"
#include "MyVec2.h"

using namespace std;

enum {
	SP_PLAYER_MODE_IDLE = 0,
	SP_PLAYER_MODE_MOVE,
	SP_PLAYER_MODE_END
};

enum {
	SP_MOVETO_NONE = -1,
	SP_MOVETO_ONE = 0,
	SP_MOVETO_TWO, 
	SP_MOVETO_THREE, 
	SP_MOVETO_FOUR,
	SP_MOVETO_FIVE,
	SP_MOVETO_SIX,
	SP_MOVETO_SEVEN,
	SP_MOVETO_EIGHT,
	SP_MOVETO_NINE
};

class SliderPuzzleGameplay {
public:
	SliderPuzzleGameplay(GAMEPLAYMODE gameplayMode,
		float systemWidth, float systemHeight,
		float pieceWidth, float pieceHeight);
	~SliderPuzzleGameplay();
	
	MyColor4B backgroundColor;
	
	MyColor4B timeUsageColor;
	int timeUsage;

	int stageNumber;

	int* currentPieceForm;
	int playerMode;
	
	MyVec2 GetPiecePosInGridForm(int index);

	void DoShuffleBackwardStep();
	int MovePieceAtIndex(int index);
	
	bool isBeatRecord(int recordedTimeUsage);
	
private:
	GAMEPLAYMODE gameplayMode;
	float systemWidth;
	float systemHeight;
	float pieceWidth;
	float pieceHeight;
	int maxPieceSizeX;
	int maxPieceSizeY;
    int blankIndexXAxis;
    int blankIndexYAxis;

	MyVec2* pieceArray;
	void InitGameplayVariables();
	void InitMaxSizeXY();
	void InitPieceArrayValue();
	int GameMode3x3MoveTo(int sourceIndex);
};

#endif
