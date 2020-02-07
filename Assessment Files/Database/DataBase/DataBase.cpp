// DataBase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;

//The only 2 functions that worked properly, copy and pasted the code from my broken
//functions to the main body and they worked, so code is messy. C++ is best.
//This looks so scuffed
void sort(Player* playerList, int amountOfPlayers); //Used to sort the playerList based on the names

void save(Player* playerList, int amountOfPlayer); //Saves everything about the players to a file

int main()
{
	//ned chiptar igtteen for dis(binery)
	char choices;
	int amountOfPlayers = 0;
	Player* playerList = new Player[amountOfPlayers];
	bool usingDatabase = true;

	while (usingDatabase)
	{
		ifstream in("DataBase.dat", ifstream::in | ifstream::binary);

		in.read((char*)&amountOfPlayers, sizeof(int));

		playerList = new Player[amountOfPlayers];

		for (int i = 0; i < amountOfPlayers; i++)
		{
			char tempPlayerName[30];
			in.read(tempPlayerName, 30);
			int tempPlayerScore;
			in.read((char*)&tempPlayerScore, sizeof(int));

			playerList[i].setName(tempPlayerName);
			playerList[i].setScore(tempPlayerScore);
		}

		in.close();
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		system("cls");

		cout << "Player Database Options:" << endl;
		cout << "-------------------------------" << endl;
		cout << "1)View players in database" << endl;
		cout << "2)Search for a player" << endl;
		cout << "3)Add player to database" << endl;
		cout << "4)Remove player from database" << endl;
		cout << "5)Modify a player's information" << endl;
		cout << "6)Quit" << endl;

		cout << "Your choice: ";
		cin >> choices;

		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		system("cls");

		switch (choices)
		{
		case '1':

			if (amountOfPlayers == 0)
			{
				cout << "No players in the database." << endl;

				system("pause");
				break;
			}

			cout << "Player Name:" << setw(19) << "Player Score:" << endl;
			cout << "-------------------------------" << endl;
			for (int i = 0; i < amountOfPlayers; i++)
			{
				cout << playerList[i].getName();
				for (int j = 0; j < (30 - playerList[i].getNameLength() + 1); j++)
				{
					cout << ".";
				}
				cout<< playerList[i].getScore() << endl;
			}

			system("pause");

			break;

		case '2':
		{
			if (amountOfPlayers == 0) break;
			char nameToLookFor[30];
			cout << "What is the name of the player you are looking for? ";
			cin >> nameToLookFor;

			int index;
			int leftPoint = 0;
			int rightPoint = amountOfPlayers;
			bool isPlayerFound = false;

			while (leftPoint <= rightPoint)
			{
				index = ((leftPoint + rightPoint) / 2);

				char currentName[30];

				if (strcmp(playerList[index].getName(), nameToLookFor) == 0)
				{
					isPlayerFound = true;
					break;
				}

				if (strcmp(playerList[index].getName(), nameToLookFor) < 0)
				{
					leftPoint = index + 1;
				}

				if (strcmp(playerList[index].getName(), nameToLookFor) > 0)
				{
					rightPoint = index - 1;
				}
			}

			if (!isPlayerFound)
			{
				cout << "Player not found." << endl;
			}
			else
			{
				cout << "Player's Name: " << playerList[index].getName() << endl;
				cout << "Player's Score:" << playerList[index].getScore() << endl;
			}

			system("pause");

			break;
		}

		case '3':
		{
			bool validInput = false;
			char tempPlayerName[30];
			int tempPlayerScore;
			cout << "Adding a player to the database: " << endl;
			cout << "-------------------------------" << endl;
			cout << "What is the player's name? ";
			cin >> tempPlayerName;

			while (!validInput)
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				validInput = true;
				cout << "What is the player's score? ";
				cin >> tempPlayerScore;

				if (cin.fail())
				{
					cout << "Invalid Input" << endl << endl;;
					validInput = false;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
				}
			}



			Player* tempPlayerList = new Player[amountOfPlayers + 1];
			for (int i = 0; i < amountOfPlayers; i++)
			{
				tempPlayerList[i] = playerList[i];
			}

			tempPlayerList[amountOfPlayers].setName(tempPlayerName);
			tempPlayerList[amountOfPlayers].setScore(tempPlayerScore);
			amountOfPlayers++;

			playerList = new Player[amountOfPlayers];

			for (int i = 0; i < amountOfPlayers; i++)
			{
				playerList[i] = tempPlayerList[i];
			}

			delete[] tempPlayerList;

			sort(playerList, amountOfPlayers);

			break;
		}

		case '4':
		{
			if (amountOfPlayers == 0) break;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			Player* tempPlayerList = new Player[amountOfPlayers - 1];
			char nameToLookFor[30];
			int newPosition = 0;

			cout << "What is the name of the player that you want to remove? ";
			cin >> nameToLookFor;

			int index;
			int leftPoint = 0;
			int rightPoint = amountOfPlayers;
			bool isPlayerFound = false;

			while (leftPoint <= rightPoint)
			{
				index = ((leftPoint + rightPoint) / 2);

				char currentName[30];

				if (strcmp(playerList[index].getName(), nameToLookFor) == 0)
				{
					isPlayerFound = true;
					break;
				}

				if (strcmp(playerList[index].getName(), nameToLookFor) < 0)
				{
					leftPoint = index + 1;
				}

				if (strcmp(playerList[index].getName(), nameToLookFor) > 0)
				{
					rightPoint = index - 1;
				}
			}

			if (!isPlayerFound)
			{
				cout << "Player not found.";
			}
			else
			{
				for (int i = 0; i < amountOfPlayers; i++)
				{
					if (i != index)
					{
						tempPlayerList[newPosition].setName(playerList[i].getName());
						tempPlayerList[newPosition].setScore(playerList[i].getScore());
						newPosition++;
					}
				}
				amountOfPlayers--;

				playerList = new Player[amountOfPlayers];

				for (int i = 0; i < amountOfPlayers; i++)
				{
					playerList[i].setName(tempPlayerList[i].getName());
					playerList[i].setScore(tempPlayerList[i].getScore());
				}

				cout << "Player, " << playerList[index].getName() << ", has been removed from the data base." << endl;
				system("pause");
			}

			break;
		}

		case '5':
		{
			char nameToLookFor[30];
			if (amountOfPlayers == 0) break;

			cout << "What is the name of the player that you want to modify? ";
			cin >> nameToLookFor;

			int index;
			int leftPoint = 0;
			int rightPoint = amountOfPlayers;
			bool isPlayerFound = false;

			while (leftPoint <= rightPoint)
			{
				index = ((leftPoint + rightPoint) / 2);

				char currentName[30];

				if (strcmp(playerList[index].getName(), nameToLookFor) == 0)
				{
					isPlayerFound = true;
					break;
				}

				if (strcmp(playerList[index].getName(), nameToLookFor) < 0)
				{
					leftPoint = index + 1;
				}

				if (strcmp(playerList[index].getName(), nameToLookFor) > 0)
				{
					rightPoint = index - 1;
				}
			}
			if (!isPlayerFound)
			{
				cout << "Player not found.";
			}
			else
			{
				char choice;
				cout << "What would you like to change?" << endl;
				cout << "------------------------------" << endl;
				cout << "1)The player's name" << endl;
				cout << "2)The player's score" << endl;
				cout << "3)The player's name and score" << endl;

				cin >> choice;

				switch (choice)
				{
				case '1':
				{
					char tempPlayerName[30];

					cout << "What would you like to change the name to? ";
					cin >> tempPlayerName;

					playerList[index].setName(tempPlayerName);

					break;
				}

				case '2':
				{
					int tempPlayerScore;
					cout << "What would you like to change the score to? ";
					cin >> tempPlayerScore;

					playerList[index].setScore(tempPlayerScore);

					break;
				}

				case '3':
				{
					char tempPlayerName[30];

					cout << "What would you like to change the name to? ";
					cin >> tempPlayerName;

					playerList[index].setName(tempPlayerName);

					int tempPlayerScore;
					cout << "What would you like to change the score to? ";
					cin >> tempPlayerScore;

					playerList[index].setScore(tempPlayerScore);

					break;
				}
				}
			}

			break;
		}

		case '6':

			usingDatabase = false;

			break;

		default:
			cout << "Invalid input" << endl;
			break;
		}

		save(playerList, amountOfPlayers);
	}

	system("pause");
}

void sort(Player* playerList, int amountOfPlayers)
{
	int startNumber = 0;
	int loopAmount = amountOfPlayers - 1;
	bool sorting = true;

	while (sorting)
	{
		sorting = false;
		for (int i = startNumber; i < loopAmount; i++)
		{
			if (strcmp(playerList[i].getName(), playerList[i + 1].getName()) > 0)
			{
				Player tempPlayer;
				tempPlayer.setName(playerList[i].getName());
				tempPlayer.setScore(playerList[i].getScore());

				playerList[i].setName(playerList[i + 1].getName());
				playerList[i].setScore(playerList[i + 1].getScore());

				playerList[i + 1].setName(tempPlayer.getName());
				playerList[i + 1].setScore(tempPlayer.getScore());
				sorting = true;
			}
		}

		loopAmount--;

		for (int i = loopAmount; i > startNumber; i--)
		{
			if (strcmp(playerList[i].getName(), playerList[i - 1].getName()) < 0)
			{
				Player tempPlayer;
				tempPlayer.setName(playerList[i].getName());
				tempPlayer.setScore(playerList[i].getScore());

				playerList[i].setName(playerList[i - 1].getName());
				playerList[i].setScore(playerList[i - 1].getScore());

				playerList[i - 1].setName(tempPlayer.getName());
				playerList[i - 1].setScore(tempPlayer.getScore());
				sorting = true;
			}
		}
		startNumber++;
	}
}

void save(Player* playerList, int amountOfPlayers)
{
	ofstream out("DataBase.dat", ofstream::out | ofstream::trunc | ofstream::binary);

	out.write((char*)&amountOfPlayers, sizeof(int));

	for (int i = 0; i < amountOfPlayers; i++)
	{
		out.write(playerList[i].getName(), 30);
		int tempPlayerScore;
		tempPlayerScore = playerList[i].getScore();

		out.write((char*)&tempPlayerScore, sizeof(int));
	}
	out.close();

}


    //in.open("Yeet.dat", std::ifstream::out | std::ifstream::binary);
	//out.open("Yeet.dat", std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);




	//Add a number to the DataBase

	//int yeet = 555;
	//out.write((char*)&yeet, sizeof(int)); //must write out a pointer char



	//Read a number from a database

	//int yote;

	//in.read((char*)&yote, sizeof(int));

	//std::cout << yote;




	//Adding player to DataBase and reading from the database

	//char playername[30];
	//std::cin >> playername;

	//out.write(playername, 30);
	//out.close();
	//in.read(playername, 30);
	//std::cout << playername;

	//in.close();
	//out.close();

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
