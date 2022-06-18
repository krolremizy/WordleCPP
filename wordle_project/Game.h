#pragma once
#include <regex>
#include "WordData.h"

class Game
{
public:
	const std::string green =	"\x1b[42m";
	const std::string yellow =	"\x1b[43m";
	const std::string reset =	"\x1b[0m";
	std::string result = "";


	bool InputVerification(std::string input, WordData& wd_obj);
	bool InputWins(const std::string& input, const std::string& winning_word);
	void CompareWords(const std::string& input, const std::string& winning_word);
};