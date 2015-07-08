#include "stdafx.h"
#include "Identation.h"


Identation::Identation()
{
}
void Identation::identationTabs(string newLine)
{
	std::string::size_type temp = 0;
	while ((temp = newLine.find("\t", temp)) != std::string::npos)
	{
		newLine.replace(temp, 1,"    ");
		newLineFix = newLine;
	}
	newLineFix = newLine;
}
void Identation::identationSpaces(string newLine)
{
	std::string::size_type temp = 0;
	while ((temp = newLine.find("    ", temp)) != std::string::npos)
	{
		newLine.replace(temp, 4, "\t");
		newLineFix = newLine;
	}
	newLineFix = newLine;
}

Identation::~Identation()
{
}
