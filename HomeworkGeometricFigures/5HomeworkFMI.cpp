#include "stdafx.h"
#include "Circle.h"
#include "Group.h"
#include "Rectangle.h"
#include"Triangle.h"
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <iostream>
#include <map>
using namespace std;
int main()
{
	list<vector<float>> holder;
	ifstream infile("C:\\Users\\nasich\\Desktop\\temp.txt");
	string line;
	string tempString = "";
	string figure = "";
	string::size_type floatHolder = 0;
	vector<float> vektor;
	float perimeter = 0;
	int vectorCounter = 0;
	int figureCounter = 0;
	map<string, vector<float>> figureHolder;
	map<string, vector<float>> groupHolder;
	int circleInt = stoi("circle");
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			getline(infile, line);
			for (int i = 0; i < line.length(); i++)
			{

				do
				{
					if (figureCounter == 0)
					{
						tempString.push_back(line[i]);
						i++;
					}
					/*else
					{
						tempString.push_back(line[i]);
						i++;
					}*/
				} while (line[i] != ' ' && i < line.length());
				if (figureCounter == 0)
				{
					figure.append(tempString);
				}
				/*switch (figure)
				{
					case ""
				}*/
				else
				{
					float variable = std::stof(tempString.substr(floatHolder));
					vektor.push_back(variable);
				}
				tempString.clear();
				figureCounter++;
			}
			figureHolder.insert(pair<string, vector<float>>(figure, vektor));
			figureCounter = 0;
			figure.clear();
			vektor.clear();
		}

	}

	infile.close();



	return 0;
}

