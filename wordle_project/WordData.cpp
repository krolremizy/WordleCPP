#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include "WordData.h"

void WordData::FileOperation()
{
	std::string word;
	std::filesystem::path currentPath = std::filesystem::current_path().append("Resources/words.txt");
	std::ifstream file(currentPath);

	if (file.is_open())
	{
		while (std::getline(file, word))
		{
			wordsList.emplace_back(word);
		}
	}
	file.close();

	if (wordsList.empty())
	{
		std::cerr << "Word list loaded empty!" << std::endl;
		return;
	}
	std::ranges::transform(wordsList.begin(), wordsList.end(), wordsList.begin(), [](std::string s)
		{
			for (int i = 0; i < s.length(); i++)
				s[i] = std::toupper(s[i]);

			return s;
		});
	std::ranges::sort(wordsList);
}