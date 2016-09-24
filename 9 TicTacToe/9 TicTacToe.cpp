// 9 TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

char box[10] = {'0','1','2','3','4','5','6','7','8','9'};
void DrawBoard();
int CheckWin();
signed long fnRetNum(std::string strPrompt);

void DrawBoard(){

	//this draws the board using the descriptions in the array box
	std::cout << "\n \tTicTacToe\n";
	std::cout << "Player 1 (X) vs. Player 2 (O)\n";

	std::cout << "   |   |   \n";
	std::cout << " " << box[1] << " | " << box[2] << " | " << box[3] << " \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << " " << box[4] << " | " << box[5] << " | " << box[6] << " \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << " " << box[7] << " | " << box[8] << " | " << box[9] << " \n";
	std::cout << "   |   |   \n";
}
int CheckWin() {
	//check for 3 of the same characters in a row
	if (box[1] == box[2] && box[2] == box[3]) {
		return 1;
	}
	else if (box[1] == box[5] && box[5] == box[9]) {
		return 1;
	}
	else if (box[1] == box[4] && box[4] == box[7]) {
		return 1;
	}
	else if (box[2] == box[5] && box[5] == box[8]) {
		return 1;
	}
	else if (box[3] == box[6] && box[6] == box[9]) {
		return 1;
	}
	else if (box[3] == box[5] && box[5] == box[7]) {
		return 1;
	}
	else if (box[4] == box[5] && box[5] == box[6]) {
		return 1;
	}
	else if (box[7] == box[8] && box[8] == box[9]) {
		return 1;
	}
	if (box[1] != '1' && box[2] != '2' && box[3] != '3' &&
		box[4] != '4' && box[5] != '5' && box[6] != '6' &&
		box[7] != '7' && box[8] != '8' && box[9] != '9') {
		return 2;
	}
	else return -1;
}
signed long fnRetNum(std::string strPrompt) {

	signed long result = 0;

	while (true) {

		std::string strinput = "";
		//use getline to avoid errors with inputs
		std::cout << strPrompt;
		std::getline(std::cin, strinput);

		// this line defines a stringstream called 'mystream' and gives it the value of strinput
		std::stringstream myStream(strinput);
		//this line looks for result (i.e. a signed long) and stores it. If it can't, it returns false
		if (myStream >> result) {
			break;
		}
		std::cout << "That's not a number. Please enter a number.\n";
	}
	return result;
}


int main()
{

	int PlayAgain=1;

	do {
		int player = 2; int choice;
		int iFor=1;
		box[1] = '1'; box[2] = '2'; box[3] = '3';
		box[4] = '4'; box[5] = '5'; box[6] = '6';
		box[7] = '7'; box[8] = '8'; box[9] = '9';


			do {
				DrawBoard();

					//swap players
					if (player == 1) {
						player = 2;
					}
					else {
						player = 1;
					}

					std::string strPlayerPrompt = std::string("Player ") + std::to_string(player) + std::string(", choose a square: ");

					//get input from player and check the square hasn't already been taken
					do {
						choice = fnRetNum(strPlayerPrompt);
						// check that the square hasn't already been taken
						if (box[choice] != 'X' && box[choice] != 'O') {
							break;
						}
						std::cout << "You must pick a square that hasn't already been chosen.";
					} while (box[choice] != 'X' && box[choice] != 'O');

					// input choice
					if (player == 1) {
						box[choice] = 'X';
					}
					else {
						box[choice] = 'O';
					}

			} while (CheckWin() != 1 && CheckWin() != 2);

			if (CheckWin() == 2) {
				std::cout << "The game is a draw.";
			}
			else {
				std::cout << "\n\nPlayer " << player << " wins!\n";
			}
			DrawBoard();

			std::string strinput;
			do {
				//use getline to avoid errors with inputs
				std::cout << "Play again?\n";
				std::getline(std::cin, strinput);
				if (strinput != "Yes" && strinput != "No" && strinput != "Y" && strinput != "N") {
					std::cout << "Please choose 'Yes' or 'No'.\n";
				}
			} while (strinput != "Yes" && strinput != "No" && strinput != "Y" && strinput != "N");

	} while (PlayAgain != 1);

	return 0;
}

