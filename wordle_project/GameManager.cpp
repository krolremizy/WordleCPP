#include <iostream>
#include <regex>
#include <windows.h>
#include <algorithm>
#include "GameManager.h"
#include "MenuLoop.h"
#include "PostGameLoop.h"

import Module;

void GameManager::Menu()
{
	std::string menu_input;
	std::string option1_str;
	menu_loop = true;

	system("cls");
	std::cout << "WORDLE \nby Rafal Kciuk\n\n";
	std::cout << "=INFORMATION=" << std::endl;
	std::cout << "1. To show instructions, type '1'. \n2. To start the game, type '2'." << std::endl;
	std::cout << "3. To quit the game, type '3'." << std::endl;
	std::cout << "Typing anything else won't take you anywhere" << std::endl << std::endl;
	std::cout << "Decision: ";
	std::cin >> menu_input;

	if (menu_input == "1")
	{
		system("cls");
		std::cout << "=INSTRUCTIONS=" << std::endl;
		std::cout << "Wordle is a web-based game created by Josh Wardle." << std::endl;
		std::cout << "It's rules are simple. You have to guess what a 5-letter word is." << std::endl;
		std::cout << "You will have 6 chances to guess the word. " << std::endl;
		std::cout << "If a character from your word is correct and on the exactly same position, it will turn green." << std::endl;
		std::cout << "If a character from your word is correct, but on a wrong position, it will turn yellow." << std::endl;
		std::cout << "If a character from your word doesn't appear in the programme's word, it will stay white." << std::endl;
		std::cout << "To come back to menu, type anything" << std::endl;
		std::cin >> option1_str;
	}
	if (menu_input == "2")
	{
		system("cls");
		std::cout << "Game is now running";
		Sleep(1500);
		menu_loop = false;
		MainGame();
	}
	if (menu_input == "3")
	{
		menu_loop = false;
	}
}
void GameManager::MainGame()
{
	system("cls");
	PostGameLoop pgl_object;
	Random random_object;
	std::string input;

	wd_object.FileOperation();

	std::string word_to_guess = wd_object.wordsList[random_object.RandomWordGenerator(wd_object.wordsList.size())];
	//std::cout << word_to_guess << std::endl << std::endl;

	std::cout << "Word has been generated!";
	std::cout << std::endl << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << "Your word: ";
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (game_object.InputVerification(input, wd_object))
		{
			if (game_object.InputWins(input, word_to_guess))
			{
				std::string victory;
				victory += game_object.green + input;
				std::cout << victory << game_object.reset << std::endl << std::endl;
				std::cout << "Congratulations! You guessed correctly in " << i+1 << " attempts!" << std::endl;
				Sleep(3000);
				pgl_object.Loop();
				return;
			}
			game_object.CompareWords(input, word_to_guess);
		}
		else
		{
			i--;
		}
	}
	std::cout << "Unfortunately, you didn't guess the word." << std::endl;
	std::cout << "The correct word was '" << word_to_guess << "'." << std::endl << std::endl;
	Sleep(3000);
	pgl_object.Loop();
	return;
}

void GameManager::PostGame()
{
	MenuLoop ml_object;
	std::string postgame_input;
	game_loop = true;
	system("cls");
	std::cout << "What would you like to do now?" << std::endl;
	std::cout << "1. To come back to main menu, type '1'." << std::endl;
	std::cout << "2. To start another game, type '2'." << std::endl;
	std::cout << "3. To quit the game, type '3'." << std::endl;
	std::cout <<"Typing anything else won't take you anywhere" << std::endl << std::endl;
	std::cout << "Decision: ";
	std::cin >> postgame_input;
	if (postgame_input == "1")
	{
		game_loop = false;	
		ml_object.Loop();
	}
	if (postgame_input == "2")
	{
		game_loop = false;
		MainGame();
	}
	if (postgame_input == "3")
	{
		game_loop = false;
		return;
	}
}