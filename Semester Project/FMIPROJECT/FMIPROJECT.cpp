#include "stdafx.h"
#include <regex>
#include <string>
#include <iostream>
#include <cstring>
#include "Comments.h"
#include <list>
#include <vector>
#include <fstream>
#include "NewLines.h"
#include "Identation.h"
using namespace std;
int main()
{
	list<string> commands;
	list<string> files;
	string tempString;
	string input;
	//Algorithm to split the input and put files in list "files" and comamnds in list "commands"
	getline(cin, input);
	for (int i = 0; i < input.length(); i++)
	{
		do
		{
			tempString.append(1, input[i]);
			i++;

		} while (input[i] != ' ' && i < input.length());
		if (tempString[0] == '-')
		{
			commands.push_back(tempString);
		}
		else
		{
			files.push_back(tempString);
		}
		tempString.clear();

	}
	//Foreaching each file with each command all in the requested sequence. Creating object of each class for the needed 
	// operation and using their properties and methods. On each itteration the input file is copied to the OLD file
	// and the input file is being modified depending on the requested command.
	for each (string file in files)
	{
		int counter = 0;
		for each (string command in commands)
		{
				counter++;
				string newLine;
				ifstream inputFileRead(file);
				string newFile;
				newFile.append(file);
				newFile.append(".old");
				ofstream outputFileRead(newFile);
				while (getline(inputFileRead, newLine))
				{
					outputFileRead << newLine << endl;
				}
				inputFileRead.close();
				outputFileRead.close();
				newLine.clear();
			
			if (command == "--comments")
			{
				Comments comment;
				ifstream outputFileWrite(newFile);
				ofstream inputFileWrite(file);

				while (getline(outputFileWrite, newLine))
				{
					comment.removeComments(newLine);
					if (comment.newLineFixed.empty())
					{
						continue;
					}
					else
						inputFileWrite << comment.newLineFixed << endl;
				}
				outputFileWrite.close();
				inputFileWrite.close();
			}
			else if (command == "--newlines=CRLF")
			{
				ifstream outputFileWrite(newFile);
				ofstream inputFileWrite(file);
				NewLines newlines;
				while (getline(outputFileWrite, newLine))
				{
					newlines.newLinesCRFL(newLine);
					inputFileWrite << newlines.newLineFix << endl;
				}
			}
			else if (command == "--newlines=LF")
			{
				ifstream outputFileWrite(newFile);
				ofstream inputFileWrite(file);
				NewLines newlines;
				while (getline(outputFileWrite, newLine))
				{
					newlines.newLinesCRFL(newLine);
					inputFileWrite << newlines.newLineFix << endl;
				}
			}
			else if (command == "--identation=spaces")
			{
				ifstream outputFileWrite(newFile);
				ofstream inputFileWrite(file);
				Identation identation;
				while (getline(outputFileWrite, newLine))
				{
					identation.identationSpaces(newLine);
					inputFileWrite << identation.newLineFix << endl;
				}
			}
			else if (command == "--identation=tabs")
			{
				ifstream outputFileWrite(newFile);
				ofstream inputFileWrite(file);
				Identation identation;
				while (getline(outputFileWrite, newLine))
				{
					identation.identationTabs(newLine);
					inputFileWrite << identation.newLineFix << endl;
				}
			}

		}


	}

	return 0;
}

