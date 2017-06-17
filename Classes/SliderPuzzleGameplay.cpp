#include "SliderPuzzleGameplay.h"
#include <cstdlib>

#define RANDOM_BACKWARD_STEP 200

SliderPuzzleGameplay::SliderPuzzleGameplay(GAMEPLAYMODE gameplayMode,
	float systemWidth, float systemHeight,
	float pieceWidth, float pieceHeight) {
	this->gameplayMode = gameplayMode;
	this->systemWidth = systemWidth;
	this->systemHeight = systemHeight;
	this->pieceWidth = pieceWidth;
	this->pieceHeight = pieceHeight;

	InitGameplayVariables();

	InitMaxSizeXY();
	InitPieceArrayValue();
}

SliderPuzzleGameplay::~SliderPuzzleGameplay() {
	delete[] pieceArray;
	delete[] currentPieceForm;
}

void SliderPuzzleGameplay::InitGameplayVariables() {
	MyColor4B temp1 = {0, 232, 216, 255};
	MyColor4B temp2 = {0, 0, 255, 255};
	backgroundColor = temp1;
	timeUsageColor = temp2;

	timeUsage = 0;
	stageNumber = 1;
	playerMode = SP_PLAYER_MODE_IDLE;
}

void SliderPuzzleGameplay::InitMaxSizeXY() {
	if (this->gameplayMode == FIELD3X3) {
		maxPieceSizeX = 3;
		maxPieceSizeY = 3;
	    blankIndexXAxis = 2;
	    blankIndexYAxis = 2;
		pieceArray = new MyVec2[9];

		currentPieceForm = new int[9];
		for(int i=0; i<9; i++)
			currentPieceForm[i] = i+1;
	}
}

void SliderPuzzleGameplay::InitPieceArrayValue() {
	MyVec2 temp;
	float attributeX = 0, attributeY = 0;
	for(int j=0; j<maxPieceSizeY; j++) {

		if (j==0)
			attributeY = pieceHeight;
		else if (j==1)
			attributeY = 0;
		else if (j==2)
			attributeY = -1*pieceHeight;

		for(int i=0; i<maxPieceSizeX; i++) {
			if (i==0)
				attributeX = -1*pieceWidth;
			else if (i==1)
				attributeX = 0;
			else if (i==2)
				attributeX = pieceWidth;

			int tempIndex = j*maxPieceSizeY+i;

			temp.x = systemWidth/2 + attributeX;
			temp.y = systemHeight/2 + attributeY;
			pieceArray[tempIndex].x = temp.x;
			pieceArray[tempIndex].y = temp.y;
		}
	}
}

void SliderPuzzleGameplay::DoShuffleBackwardStep() {
    int moveByXAxis[4], moveByYAxis[4];
	moveByXAxis[0] = 0;
	moveByXAxis[1] = 0;
	moveByXAxis[2] = 1;
	moveByXAxis[3] = -1;

	moveByYAxis[0] = 1;
	moveByYAxis[1] = -1;
	moveByYAxis[2] = 0;
	moveByYAxis[3] = 0;

    for(int i = 0; i<RANDOM_BACKWARD_STEP; i++) {
        int r = rand()%4;
        int newIndexXAxis = blankIndexXAxis + moveByXAxis[r];
        int newIndexYAxis = blankIndexYAxis + moveByYAxis[r];

        if ((newIndexXAxis >= 0) && (newIndexYAxis >= 0)
        	&& (newIndexXAxis < maxPieceSizeX) && (newIndexYAxis < maxPieceSizeY)) {
            int blankIndex = blankIndexYAxis * maxPieceSizeX + blankIndexXAxis;
            int newIndex = newIndexYAxis * maxPieceSizeX + newIndexXAxis;
            int temp = currentPieceForm[blankIndex];
            currentPieceForm[blankIndex] = currentPieceForm[newIndex];
            currentPieceForm[newIndex]= temp;

            blankIndexXAxis = newIndexXAxis;
            blankIndexYAxis = newIndexYAxis;
        } else {
           i--; // couldn't move, so retry
        }
    }
}

MyVec2 SliderPuzzleGameplay::GetPiecePosInGridForm(int index) {
	return pieceArray[index];
}

int SliderPuzzleGameplay::MovePieceAtIndex(int index) {
	int destinationIndex;
	if (gameplayMode == FIELD3X3)
		destinationIndex = GameMode3x3MoveTo(index);
		
	if (destinationIndex != SP_MOVETO_NONE) {
		int temp = currentPieceForm[index];
		currentPieceForm[index] = currentPieceForm[destinationIndex];
		currentPieceForm[destinationIndex] = temp;
	}
	return destinationIndex;	
}

int SliderPuzzleGameplay::GameMode3x3MoveTo(int sourceIndex) {
	int result = SP_MOVETO_NONE;
	std::vector<int> possibleValues = std::vector<int>();
	switch(sourceIndex) {
		case SP_MOVETO_ONE: {
            possibleValues.push_back(SP_MOVETO_TWO);
			possibleValues.push_back(SP_MOVETO_FOUR);
			break;
		}
		case SP_MOVETO_TWO: {
			possibleValues.push_back(SP_MOVETO_ONE);
			possibleValues.push_back(SP_MOVETO_FIVE);
			possibleValues.push_back(SP_MOVETO_THREE);
			break;
		}
		case SP_MOVETO_THREE: {
			possibleValues.push_back(SP_MOVETO_TWO);
			possibleValues.push_back(SP_MOVETO_SIX);
			break;
		}
		case SP_MOVETO_FOUR: {
			possibleValues.push_back(SP_MOVETO_ONE);
			possibleValues.push_back(SP_MOVETO_FIVE);
			possibleValues.push_back(SP_MOVETO_SEVEN);
			break;
		}
		case SP_MOVETO_FIVE: {
			possibleValues.push_back(SP_MOVETO_TWO);
			possibleValues.push_back(SP_MOVETO_FOUR);
			possibleValues.push_back(SP_MOVETO_SIX);
			possibleValues.push_back(SP_MOVETO_EIGHT);
			break;
		}
		case SP_MOVETO_SIX: {
			possibleValues.push_back(SP_MOVETO_THREE);
			possibleValues.push_back(SP_MOVETO_FIVE);
			possibleValues.push_back(SP_MOVETO_NINE);
			break;
		}
		case SP_MOVETO_SEVEN: {
			possibleValues.push_back(SP_MOVETO_FOUR);
			possibleValues.push_back(SP_MOVETO_EIGHT);
			break;
		}
		case SP_MOVETO_EIGHT: {
			possibleValues.push_back(SP_MOVETO_SEVEN);
			possibleValues.push_back(SP_MOVETO_FIVE);
			possibleValues.push_back(SP_MOVETO_NINE);
			break;
		}
		case SP_MOVETO_NINE: {
			possibleValues.push_back(SP_MOVETO_SIX);
			possibleValues.push_back(SP_MOVETO_EIGHT);
			break;
		}
		default:
		break;
	}
	
	for(unsigned int i=0; i<possibleValues.size(); i++)
		if (currentPieceForm[possibleValues.at(i)] == 9) {
			result = possibleValues.at(i);
			break;			
		}
	return result;
}

bool SliderPuzzleGameplay::isBeatRecord(int recordedTimeUsage) {
	if (recordedTimeUsage == FIRST_TOUCH_TIMEFRAME) {
		return true;
	} else if (recordedTimeUsage > timeUsage) {
		return true;
	} else {
		return false;
	}
}
