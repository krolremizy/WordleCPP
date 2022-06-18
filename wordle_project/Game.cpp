#include <iostream>
#include "Game.h"

bool Game::InputVerification(const std::string input, WordData& wd_obj)
{
	std::regex my_regex("[a-zA-Z]{5}");

	if (!std::regex_match(input, my_regex))
	{
		std::cout << "You have to use 5 characters, remember you can only use letters" << std::endl << std::endl;
		return false;
	}

	for (int i = 0; i < wd_obj.wordsList.size(); i++)
	{
		if (input == wd_obj.wordsList[i])
		{
			std::cout << "Input correct!" << std::endl;
			return true;
		}
	}
	std::cout << "Wrong input, it's not a valid word" << std::endl << std::endl;
	return false;
}

bool Game::InputWins(const std::string& input, const std::string& winning_word)
{
	return (input == winning_word);
}

void Game::CompareWords(const std::string& input, const std::string& winning_word)
{
	std::string guess_word;
	for (int i = 0; i < input.size(); i++)
	{
		bool is_in_word = false;

		if (input[i] == winning_word[i])
		{
			result += green + input[i] + reset;
		}
		else
		{
			for (int j = 0; j < winning_word.size(); j++)
			{
				if (input[i] == winning_word[j])
				{
					is_in_word = true;
				}
			}
			if (is_in_word)
			{
				result += yellow + input[i] + reset;
			}
			else
			{
				result += input[i];
			}
		}
	}
	std::cout << result;
	result = "";
	std::cout << std::endl << std::endl;
}