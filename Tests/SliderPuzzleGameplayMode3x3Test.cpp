#include "gmock/gmock.h"

#include "../Classes/MyColor4B.h"
#include "../Classes/MyVec2.h"
#include "../Classes/Game.h"
#include "../Classes/SliderPuzzleGameplay.h"

using namespace std;

class SliderPuzzleGameplayMode3x3Test : public testing::Test {

protected:
	int sysWidth;
	int sysHeight;

	int pieceWidth;
 	int pieceHeight;

	SliderPuzzleGameplay* gamePlayer;

    SliderPuzzleGameplayMode3x3Test() {
    }

    virtual ~SliderPuzzleGameplayMode3x3Test() {
    }

	virtual void SetUp() {
		sysWidth = 640;
		sysHeight = 480;

		pieceWidth = 64;
	 	pieceHeight = 64;

		gamePlayer = new SliderPuzzleGameplay(FIELD3X3, sysWidth, sysHeight, pieceWidth, pieceHeight);
    }

    virtual void TearDown() {
		delete gamePlayer;
    }
};

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece1AtLeftTopCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2-pieceWidth, sysHeight/2+pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(0);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece2AtTopOfCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2, sysHeight/2+pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(1);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece3AtRightTopCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2+pieceWidth, sysHeight/2+pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(2);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece4AtLeftOfCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2-pieceWidth, sysHeight/2};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(3);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece5AtCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2, sysHeight/2};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(4);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece6AtRightCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2+pieceWidth, sysHeight/2};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(5);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece7AtLeftButtomCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2-pieceWidth, sysHeight/2-pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(6);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece8AtBottomOfCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2, sysHeight/2-pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(7);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestPiece9AtRightBottomOfCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2+pieceWidth, sysHeight/2-pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(8);

	EXPECT_EQ(expect.x, actual.x);
	EXPECT_EQ(expect.y, actual.y);
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexOneToIndexTwo)
{
	int expect[9] = {	9, 3, 8,
						1, 6, 2,
						5, 4, 7	};

	gamePlayer->currentPieceForm[0] = 3; gamePlayer->currentPieceForm[1] = 9; gamePlayer->currentPieceForm[2] = 8;
	gamePlayer->currentPieceForm[3] = 1; gamePlayer->currentPieceForm[4] = 6; gamePlayer->currentPieceForm[5] = 2;
	gamePlayer->currentPieceForm[6] = 5; gamePlayer->currentPieceForm[7] = 4; gamePlayer->currentPieceForm[8] = 7;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_ONE);

	for(int i=0; i<9; i++)
	{
		EXPECT_EQ(expect[i], gamePlayer->currentPieceForm[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestTouchIndexSevenButNotChange)
{
	int expect[9] = {	9, 3, 8,
						1, 6, 2,
						5, 4, 7	};

	gamePlayer->currentPieceForm[0] = 9; gamePlayer->currentPieceForm[1] = 3; gamePlayer->currentPieceForm[2] = 8;
	gamePlayer->currentPieceForm[3] = 1; gamePlayer->currentPieceForm[4] = 6; gamePlayer->currentPieceForm[5] = 2;
	gamePlayer->currentPieceForm[6] = 5; gamePlayer->currentPieceForm[7] = 4; gamePlayer->currentPieceForm[8] = 7;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_SEVEN);

	for(int i=0; i<9; i++)
	{
		EXPECT_EQ(expect[i], gamePlayer->currentPieceForm[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexOneToIndexFour)
{
	int expect[9];
	int actual[9];
	expect[0] = 9;
	expect[1] = 2;
	expect[2] = 3;
	expect[3] = 1;
	expect[4] = 5;
	expect[5] = 6;
	expect[6] = 4;
	expect[7] = 7;
	expect[8] = 8;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 2;
	gamePlayer->currentPieceForm[2] = 3;
	gamePlayer->currentPieceForm[3] = 9;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 6;
	gamePlayer->currentPieceForm[6] = 4;
	gamePlayer->currentPieceForm[7] = 7;
	gamePlayer->currentPieceForm[8] = 8;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_ONE);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexTwoToIndexOne)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 9;
	expect[2] = 2;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 9;
	gamePlayer->currentPieceForm[1] = 1;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 3;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_TWO);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexTwoToIndexFive)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 9;
	expect[2] = 3;
	expect[3] = 4;
	expect[4] = 2;
	expect[5] = 5;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 3;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 2;
	gamePlayer->currentPieceForm[2] = 3;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 9;
	gamePlayer->currentPieceForm[5] = 5;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 3;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_TWO);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexTwoToIndexThree)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 9;
	expect[2] = 2;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 2;
	gamePlayer->currentPieceForm[2] = 9;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 3;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_TWO);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexThreeToIndexTwo)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 2;
	expect[2] = 9;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 9;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 3;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_THREE);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexThreeToIndexSix)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 2;
	expect[2] = 9;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 2;
	gamePlayer->currentPieceForm[2] = 3;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 9;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_THREE);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexFourToIndexOne)
{
	int expect[9];
	int actual[9];
	expect[0] = 3;
	expect[1] = 1;
	expect[2] = 2;
	expect[3] = 9;
	expect[4] = 4;
	expect[5] = 5;
	expect[6] = 6;
	expect[7] = 7;
	expect[8] = 8;

	gamePlayer->currentPieceForm[0] = 9;
	gamePlayer->currentPieceForm[1] = 1;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 3;
	gamePlayer->currentPieceForm[4] = 4;
	gamePlayer->currentPieceForm[5] = 5;
	gamePlayer->currentPieceForm[6] = 6;
	gamePlayer->currentPieceForm[7] = 7;
	gamePlayer->currentPieceForm[8] = 8;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_FOUR);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexFourToIndexFive)
{
	int expect[9];
	int actual[9];
	expect[0] = 4;
	expect[1] = 1;
	expect[2] = 2;
	expect[3] = 9;
	expect[4] = 3;
	expect[5] = 5;
	expect[6] = 6;
	expect[7] = 7;
	expect[8] = 8;

	gamePlayer->currentPieceForm[0] = 4;
	gamePlayer->currentPieceForm[1] = 1;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 3;
	gamePlayer->currentPieceForm[4] = 9;
	gamePlayer->currentPieceForm[5] = 5;
	gamePlayer->currentPieceForm[6] = 6;
	gamePlayer->currentPieceForm[7] = 7;
	gamePlayer->currentPieceForm[8] = 8;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_FOUR);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

TEST_F(SliderPuzzleGameplayMode3x3Test, TestMoveFromIndexFourToIndexSeven)
{
	int expect[9];
	int actual[9];
	expect[0] = 4;
	expect[1] = 1;
	expect[2] = 2;
	expect[3] = 9;
	expect[4] = 6;
	expect[5] = 5;
	expect[6] = 3;
	expect[7] = 7;
	expect[8] = 8;

	gamePlayer->currentPieceForm[0] = 4;
	gamePlayer->currentPieceForm[1] = 1;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 3;
	gamePlayer->currentPieceForm[4] = 6;
	gamePlayer->currentPieceForm[5] = 5;
	gamePlayer->currentPieceForm[6] = 9;
	gamePlayer->currentPieceForm[7] = 7;
	gamePlayer->currentPieceForm[8] = 8;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_FOUR);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		EXPECT_EQ(expect[i], actual[i]);
	}
}

/*
TEST_GROUP(SliderPuzzleGameplayMode3x3)
{
	int sysWidth;
	int sysHeight;

	int pieceWidth;
 	int pieceHeight;

	SliderPuzzleGameplay* gamePlayer;

	void setup()
	{
		sysWidth = 480;
		sysHeight = 320;

		pieceWidth = 64;
	 	pieceHeight = 64;

		gamePlayer = new SliderPuzzleGameplay(FIELD3X3, sysWidth, sysHeight, pieceWidth, pieceHeight);
	}

	void teardown()
	{
		delete gamePlayer;
	}
};

TEST(SliderPuzzleGameplayMode3x3, TestPiece1AtLeftTopCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2-pieceWidth, sysHeight/2+pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(0);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestPiece2AtTopOfCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2, sysHeight/2+pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(1);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestPiece3AtRightTopCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2+pieceWidth, sysHeight/2+pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(2);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestPiece4AtLeftOfCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2-pieceWidth, sysHeight/2};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(3);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestPiece5AtCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2, sysHeight/2};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(4);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestPiece6AtRightCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2+pieceWidth, sysHeight/2};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(5);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestPiece7AtLeftButtomCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2-pieceWidth, sysHeight/2-pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(6);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestPiece8AtBottomOfCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2, sysHeight/2-pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(7);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestPiece9AtRightBottomOfCenterOfScreen)
{
	MyVec2 expect = {sysWidth/2+pieceWidth, sysHeight/2-pieceHeight};
	MyVec2 actual = gamePlayer->GetPiecePosInGridForm(8);

	CHECK_EQUAL(expect.x, actual.x);
	CHECK_EQUAL(expect.y, actual.y);
}

TEST(SliderPuzzleGameplayMode3x3, TestIsCorrectForm)
{
	int expect[9];
	int actual[9];

	//for(int i=0; i<9; i++)
	//{
	//	expect[i] = i+1;
	//	actual[i] = gamePlayer->currentPieceForm[i];
	//	CHECK_EQUAL(expect[i], actual[i]);
	//}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexOneToIndexTwo)
{
	int expect[9];
	int actual[9];
	expect[0] = 9;
	expect[1] = 1;
	expect[2] = 2;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 9;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 3;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_ONE);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexOneToIndexFour)
{
	int expect[9];
	int actual[9];
	expect[0] = 9;
	expect[1] = 2;
	expect[2] = 3;
	expect[3] = 1;
	expect[4] = 5;
	expect[5] = 6;
	expect[6] = 4;
	expect[7] = 7;
	expect[8] = 8;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 2;
	gamePlayer->currentPieceForm[2] = 3;
	gamePlayer->currentPieceForm[3] = 9;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 6;
	gamePlayer->currentPieceForm[6] = 4;
	gamePlayer->currentPieceForm[7] = 7;
	gamePlayer->currentPieceForm[8] = 8;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_ONE);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexTwoToIndexOne)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 9;
	expect[2] = 2;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 9;
	gamePlayer->currentPieceForm[1] = 1;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 3;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_TWO);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexTwoToIndexFive)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 9;
	expect[2] = 3;
	expect[3] = 4;
	expect[4] = 2;
	expect[5] = 5;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 3;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 2;
	gamePlayer->currentPieceForm[2] = 3;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 9;
	gamePlayer->currentPieceForm[5] = 5;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 3;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_TWO);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexTwoToIndexThree)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 9;
	expect[2] = 2;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 2;
	gamePlayer->currentPieceForm[2] = 9;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 3;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_TWO);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexThreeToIndexTwo)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 2;
	expect[2] = 9;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 9;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 3;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_THREE);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexThreeToIndexSix)
{
	int expect[9];
	int actual[9];
	expect[0] = 1;
	expect[1] = 2;
	expect[2] = 9;
	expect[3] = 4;
	expect[4] = 5;
	expect[5] = 3;
	expect[6] = 7;
	expect[7] = 8;
	expect[8] = 6;

	gamePlayer->currentPieceForm[0] = 1;
	gamePlayer->currentPieceForm[1] = 2;
	gamePlayer->currentPieceForm[2] = 3;
	gamePlayer->currentPieceForm[3] = 4;
	gamePlayer->currentPieceForm[4] = 5;
	gamePlayer->currentPieceForm[5] = 9;
	gamePlayer->currentPieceForm[6] = 7;
	gamePlayer->currentPieceForm[7] = 8;
	gamePlayer->currentPieceForm[8] = 6;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_THREE);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexFourToIndexOne)
{
	int expect[9];
	int actual[9];
	expect[0] = 3;
	expect[1] = 1;
	expect[2] = 2;
	expect[3] = 9;
	expect[4] = 4;
	expect[5] = 5;
	expect[6] = 6;
	expect[7] = 7;
	expect[8] = 8;

	gamePlayer->currentPieceForm[0] = 9;
	gamePlayer->currentPieceForm[1] = 1;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 3;
	gamePlayer->currentPieceForm[4] = 4;
	gamePlayer->currentPieceForm[5] = 5;
	gamePlayer->currentPieceForm[6] = 6;
	gamePlayer->currentPieceForm[7] = 7;
	gamePlayer->currentPieceForm[8] = 8;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_FOUR);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexFourToIndexFive)
{
	int expect[9];
	int actual[9];
	expect[0] = 4;
	expect[1] = 1;
	expect[2] = 2;
	expect[3] = 9;
	expect[4] = 3;
	expect[5] = 5;
	expect[6] = 6;
	expect[7] = 7;
	expect[8] = 8;

	gamePlayer->currentPieceForm[0] = 4;
	gamePlayer->currentPieceForm[1] = 1;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 3;
	gamePlayer->currentPieceForm[4] = 9;
	gamePlayer->currentPieceForm[5] = 5;
	gamePlayer->currentPieceForm[6] = 6;
	gamePlayer->currentPieceForm[7] = 7;
	gamePlayer->currentPieceForm[8] = 8;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_FOUR);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}

TEST(SliderPuzzleGameplayMode3x3, TestMoveFromIndexFourToIndexSeven)
{
	int expect[9];
	int actual[9];
	expect[0] = 4;
	expect[1] = 1;
	expect[2] = 2;
	expect[3] = 9;
	expect[4] = 6;
	expect[5] = 5;
	expect[6] = 3;
	expect[7] = 7;
	expect[8] = 8;

	gamePlayer->currentPieceForm[0] = 4;
	gamePlayer->currentPieceForm[1] = 1;
	gamePlayer->currentPieceForm[2] = 2;
	gamePlayer->currentPieceForm[3] = 3;
	gamePlayer->currentPieceForm[4] = 6;
	gamePlayer->currentPieceForm[5] = 5;
	gamePlayer->currentPieceForm[6] = 9;
	gamePlayer->currentPieceForm[7] = 7;
	gamePlayer->currentPieceForm[8] = 8;

	gamePlayer->playerMode = SP_PLAYER_MODE_MOVE;
	int destinationIndex = gamePlayer->MovePieceAtIndex(SP_MOVETO_FOUR);

	for(int i=0; i<9; i++)
	{
		actual[i] = gamePlayer->currentPieceForm[i];
		CHECK_EQUAL(expect[i], actual[i]);
	}
}
*/
