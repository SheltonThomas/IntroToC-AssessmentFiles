#pragma once

class Player
{
public:
	char* getName() { return playerName; };
	void setName(const char* newName);
	int getNameLength();

	int getScore() { return playerScore; };
	void setScore(int tempScore);

private:
	char playerName[30];
	int playerScore;
};
