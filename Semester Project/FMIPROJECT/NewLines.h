#pragma once
#include <string>
using namespace std;
class NewLines
{
public:
	string newLineFix;
	void newLinesCRFL(string newLine);
	void newLinesLF(string newLine);
	NewLines();
	~NewLines();
};

