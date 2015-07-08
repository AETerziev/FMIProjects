#pragma once
#include <string>
using namespace std;
class Identation
{
public:
	string newLineFix;
	void identationTabs(string newLine);
	void identationSpaces(string NewLine);
	Identation();
	~Identation();
};

