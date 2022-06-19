#pragma once
#include <string>
#include <vector>
#include "FileHandler.h"

class WordData : public FileHandler
{
public:

	std::vector<std::string>wordsList;
	void FileOperation();
};