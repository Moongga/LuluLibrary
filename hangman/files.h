#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

string GetWord() {
	const int countLines = 52;
	const std::string fileName = "English-words.txt";
	std::ifstream inFile(fileName);

	if (!inFile.is_open()) {

		std::cerr << "Can't open the file " << fileName << '\n';
	}

	srand(time(0));
	int counter = -1;
	std::size_t neededLine = rand() % countLines + 1;
	std::string currentLine;

	while (std::getline(inFile, currentLine) && ++counter != neededLine);

	if (counter < neededLine) {
		std::cout << "There is no line with number " << neededLine << '\n';
		std::cout << "The max line number is " << counter << '\n';
	}
	else
		inFile.close();
		return currentLine;
}