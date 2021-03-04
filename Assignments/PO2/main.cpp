///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           YI ZHANG
// Email:            zy19950301@126.com
// Label:            PO2
// Title:            Resizing the Stack
// Course:           3013-alg
// Semester:         Spring 2021
//
// Description:   A linked list help to search animals name and show how many it has
//       
//
// Files:  main.cpp          
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <time.h>
#include <chrono>
#include "Timer.hpp"
#include "mygetch.hpp"
#include <string>
#include <vector>
#include <fstream>
#include "termcolor.hpp"

using namespace std;
/*
	Struct Name: words
	Description: A node have animals words point
	Public Methods:
		string word
		words* Next
	Private Methods:
 */
struct words
{
	words* Next;
	string word;
	words()
	{
		Next = NULL;
		word = "";
	}
};

/*
	Class Name: LinkedList
		Description:list the node
		Public Methods:
		LinkedList() 
		getnum()
		insert(words* num)
		vector<string> Find(string typed)
	Private Methods:
 */

class LinkedList
{
protected:
	words* Head;
	words* Tail;
	int Size;

public:
	LinkedList();
	int getnum();
	void insert(words* num);
	void Display();
	vector<string> Find(string typed);
};

/*
	Constructor : LinkedList
	Description:Initialize values.
 */
LinkedList::LinkedList()
{
	Head = NULL;
	Tail = NULL;
	Size = 0;
}

/*
	Public : getnum()
	Description: returen list size
 */
int LinkedList::getnum()
{
	return Size;
}

/*
   Public : insert
   Description:insert node
   Params: words* num
   Returns:
*/
void LinkedList::insert(words* num)
{
	if (!Head)
	{
		Head = Tail = num;
	}

	else
	{
		Tail->Next = num;
		Tail = num;
	}

	Size++;
}

/*
   Public : Print()
   Description:prints List.
*/
void LinkedList::Display()
{
	words* Current = Head;

	while (Current)                        
	{
		cout << Current->word;              
		cout << endl;
		cout << "->";
		Current = Current->Next;           
	}
	cout << "Done" << endl;
}

/*
	Public : Find
	Description:get from user and find the word
	Params: string typed
	Returns: Results
*/
vector<string> LinkedList::Find(string typed)
{

	vector<string> Results;

	words* Current = Head;

	while (Current)
	{
		string found = "";

		found = Current->word;              

		int len = typed.length();          

		if (found.substr(0, len) == typed)  
		{                                  
			Results.push_back(found);
		}

		Current = Current->Next;            
	}

	return Results;                       
}

int main()
{
	LinkedList L1;                         
	vector<string> animals_Data;            

	ifstream infile;
	infile.open("animal_names.txt");

	Timer time;                             
	time.Start();                           

	while (!infile.eof())                  
	{
		string Temp;

		infile >> Temp;

		animals_Data.push_back(Temp);
	}

	time.End();

	cout << termcolor::green << time.Seconds() << termcolor::reset
		<< " seconds to read in the data." << endl;

	Timer Load_Words;                       

	Load_Words.Start();

	for (int j = 0; j < animals_Data.size(); j++)
	{                                       
		words* Temp = new words;     
		string item = animals_Data[j];
		Temp->word = item;
		L1.insert(Temp);
	}
	Load_Words.End();

	cout << termcolor::green << Load_Words.Seconds() << termcolor::reset
		<< " seconds to read in the data." << termcolor::reset << endl;

	char k;                                
	string word = "";                       
	vector<string> Matches;                 
	string Top_Results[10];                 
	int SearchResults;                      

	cout << "Type keys and watch what happens. Type capital"<< termcolor::red << " Z to quit." << termcolor::reset << endl;
	while ((k = getch()) != 'Z')            
	{
		if ((int)k == 127)                 
		{
			if (word.size() > 0)
			{
				word = word.substr(0, word.size() - 1);
			}
		}

		else
		{
			if (!isalpha(k))               
			{
				cout << "plz type letter only!"<< endl;
				continue;
			}

			if ((int)k >= 97)              
			{
				k -= 32;                   
			}
		}
		word += k;                          

		Timer Auto_Suggestion;              
		Auto_Suggestion.Start();
		Matches = L1.Find(word);
		Auto_Suggestion.End();

		SearchResults = Matches.size();

		if ((int)k != 32)                   
		{
			cout << "Keypressed: " << termcolor::red << k << " = "
				<< termcolor::green << (int)k << termcolor::reset << endl;
			cout << "Current Substr: " << termcolor::red << word
				<< termcolor::reset << endl;
			cout << termcolor::red << SearchResults << termcolor::reset
				<< " words found in " << termcolor::green << Auto_Suggestion.Seconds()
				<< termcolor::reset << " seconds" << termcolor::reset << endl;

			if (Matches.size() >= 10)       
			{
				for (int i = 0; i < 10; i++)
				{
					Top_Results[i] = Matches[i];
					cout << Top_Results[i] << " ";
				}
			}
			else
			{
				for (int j = 0; j < Matches.size(); j++)
				{
					Top_Results[j] = Matches[j];
					cout << Top_Results[j] << " ";
				}
			}

			cout << termcolor::reset << endl << endl;
		}
	}
	return 0;
}
