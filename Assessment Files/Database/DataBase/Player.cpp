#include "pch.h"
#include "Player.h"
#include <cstring>
#include <iostream>
#include <string>

void Player::setName(const char* newName)
{
	strncpy_s(playerName, newName, 30);
}

void Player::setScore(int tempScore)
{
	playerScore = tempScore;
}

int Player::getNameLength()
{
	int nameLength = 0;

	for (int i = 0; i < 30; i++)
	{
		if (playerName[i] == '\0')
		{
			return nameLength;
		}
		nameLength++;
	}

	return 0;
}
