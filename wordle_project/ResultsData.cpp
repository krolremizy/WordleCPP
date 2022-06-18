#include <fstream>
#include <filesystem>
#include "ResultsData.h"

void ResultsData::FileOperation(const std::string& guess, int tries)
{
	std::filesystem::path currentPath = std::filesystem::current_path().append("Resources/results.txt");
	std::ofstream file(currentPath);

	if (file.is_open())
	{
		file << guess << " - " << tries << std::endl;

	}
	file.close();
}