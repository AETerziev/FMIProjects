#include "stdafx.h"
#include "NewLines.h"



NewLines::NewLines()
{
}
void NewLines::newLinesCRFL(string newLine)
{
	std::string::size_type temp = 0;
	while ((temp = newLine.find("\n", temp)) != std::string::npos)
	{
		newLine.replace(temp, 1, "\r\n");
		newLineFix = newLine;
	}
	newLineFix = newLine;
}

void NewLines::newLinesLF(string newLine)
{
	std::string::size_type temp = 0;
	while ((temp = newLine.find("\r\n", temp)) != std::string::npos)
	{
		newLine.replace(temp, 2, "\n");
		newLineFix = newLine;
	}
	newLineFix = newLine;
}
NewLines::~NewLines()
{
}
