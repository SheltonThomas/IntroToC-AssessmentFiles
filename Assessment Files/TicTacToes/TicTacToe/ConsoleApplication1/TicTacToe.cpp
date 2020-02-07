// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <locale>

using namespace std;

int main()
{
	char TTTBoard[3][3];
	int playerTurn = 1;
	bool gameOver = false;
	bool failedMove;
	bool fullBoard = false;
	bool ticTacToe = false;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			TTTBoard[x][y] = ' ';
		}
	}

	cout << " 7 | 8 | 9" << endl;
	cout << "---+---+---" << endl;
	cout << " 4 | 5 | 6" << endl;
	cout << "---+---+---" << endl;
	cout << " 1 | 2 | 3" << endl << endl;

	cout << "Use the numpad to say were you want your mark to be on the board." << endl;
	cout << "Player one will be x and player 2 will be o." << endl;

	system("pause");
	system("cls");

	while (!gameOver)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		failedMove = false;
		system("cls");

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				cout << " " << TTTBoard[x][y] << " ";
				if (y != 2)
				{
					cout << "|";
				}
			}
			cout << endl;
			if (x != 2)
			{
				cout << "---+---+---" << endl;
			}
		}

		cout << "It is currently player " << playerTurn << "'s turn." << endl;
		cout << "Where would you like to put your mark?" << endl;

		int boardPlacement;
		cin >> boardPlacement;

		if (cin.fail())
		{
			cout << "You inputted a wrong key. Try again." << endl;
			failedMove = true;

			cin.clear(); 
			cin.ignore(cin.rdbuf()->in_avail());
		}

		switch (boardPlacement)
		{
		case 1:
			if (TTTBoard[2][0] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[2][0] = 'x';
			else TTTBoard[2][0] = 'o';
			break;

		case 2:
			if (TTTBoard[2][1] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[2][1] = 'x';
			else TTTBoard[2][1] = 'o';
			break;

		case 3:
			if (TTTBoard[2][2] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[2][2] = 'x';
			else TTTBoard[2][2] = 'o';
			break;

		case 4:
			if (TTTBoard[1][0] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[1][0] = 'x';
			else TTTBoard[1][0] = 'o';
			break;

		case 5:
			if (TTTBoard[1][1] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[1][1] = 'x';
			else TTTBoard[1][1] = 'o';
			break;

		case 6:
			if (TTTBoard[1][2] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[1][2] = 'x';
			else TTTBoard[1][2] = 'o';
			break;

		case 7:
			if (TTTBoard[0][0] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[0][0] = 'x';
			else TTTBoard[0][0] = 'o';
			break;

		case 8:
			if (TTTBoard[0][1] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[0][1] = 'x';
			else TTTBoard[0][1] = 'o';
			break;

		case 9:
			if (TTTBoard[0][2] != ' ')
			{
				cout << "There is already a mark in this spot." << endl;
				system("pause");
				failedMove = true;
				break;
			}

			if (playerTurn == 1) TTTBoard[0][2] = 'x';
			else TTTBoard[0][2] = 'o';
			break;

		default:
			if (failedMove)
			{
				break;
			}
			cout << "You can't put a mark there.";
			failedMove = true;
			break;
		}

		gameOver = true;
		fullBoard = true;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (TTTBoard[x][y] == ' ')
				{
					gameOver = false;
					fullBoard = false;
				}
			}
		}

		if ((TTTBoard[0][0] != ' ' && TTTBoard[0][0] == TTTBoard[0][1] && TTTBoard[0][1] == TTTBoard[0][2]) ||
			(TTTBoard[1][0] != ' ' && TTTBoard[1][0] == TTTBoard[1][1] && TTTBoard[1][1] == TTTBoard[1][2]) ||
			(TTTBoard[2][0] != ' ' && TTTBoard[2][0] == TTTBoard[2][1] && TTTBoard[2][1] == TTTBoard[2][2]) ||

			(TTTBoard[0][0] != ' ' && TTTBoard[0][0] == TTTBoard[1][0] && TTTBoard[1][0] == TTTBoard[2][0]) ||
			(TTTBoard[0][1] != ' ' && TTTBoard[0][1] == TTTBoard[1][1] && TTTBoard[1][1] == TTTBoard[2][1]) ||
			(TTTBoard[0][2] != ' ' && TTTBoard[0][2] == TTTBoard[1][2] && TTTBoard[1][2] == TTTBoard[2][2]) ||
			
			(TTTBoard[0][0] != ' ' && TTTBoard[0][0] == TTTBoard[1][1] && TTTBoard[1][1] == TTTBoard[2][2]) ||
			(TTTBoard[0][2] != ' ' && TTTBoard[0][2] == TTTBoard[1][1] && TTTBoard[1][1] == TTTBoard[2][0]))
		{
			ticTacToe = true;
			gameOver = true;
		}

		if (!failedMove && !fullBoard && !ticTacToe)
		{
			if (playerTurn == 1)	playerTurn = 2;
			else playerTurn = 1;
		}
	}
	
	system("cls");

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << " " << TTTBoard[x][y] << " ";
			if (y != 2)
			{
				cout << "|";
			}
		}
		cout << endl;
		if (x != 2)
		{
			cout << "--- --- ---" << endl;
		}
	}

	if (ticTacToe)
	{
		cout << "Player " << playerTurn << " won the game." << endl;
	}

	else if (fullBoard)
	{
		cout << endl << "Your game ended in a draw." << endl;
	}

	system("pause");
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
