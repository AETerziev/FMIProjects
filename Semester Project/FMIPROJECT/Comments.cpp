#include "stdafx.h"
#include "Comments.h"
#include <iostream>
using namespace std;


Comments::Comments()
{
}
void Comments::removeComments(string newLine)
{
	for (int i = 0; i < newLine.length(); i++)
	{
		if (newLine[i] == '/' && newLine[i + 1] == '/')
		{
			newLine.erase(i,newLine.length()-i);
		}
		if (newLine[i] == '/' && newLine[i + 1] == '*')
		{
			if (newLine.find("*/") != string::npos)
			{
				int tempIndex = i;
				while (newLine[i] != '*' && newLine[i + 1] != '/')
				{
					i++;
				}
				newLine.erase(0, i + 2);
			}
			else
			{
				newLine.erase(i, newLine.length() - i);
			}
		}
		if (newLine[i] == '*' && newLine[i + 1] == '/')
		{
			newLine.erase(0, i+2);
		}
		newLineFixed = newLine;
	}
}

Comments::~Comments()
{
}

