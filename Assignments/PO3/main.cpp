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
		words* left
		words* right
	Private Methods:
 */
struct words
{
	words* left;
	words* right;
	string word;
	words()
	{
		left = right = NULL;
		word = "";
	}
};

/*
	Class Name: BST
		Description:list the node
		Public Methods:
		LinkedList() 
		getnum()
		insert(words* num)
		vector<string> Find(string typed)
	Private Methods:
 */

class BST
{
private:
	words* m_root;
	int m_size;
	void Print(words*);

	void Insert(words*& m_root, string w, string d)
	{
		bool didInsert = false;

		if (!m_root)
		{
			m_root = new words(w, d);
		}
		else
		{
			if (m_root->word[0] == w[0])
			{
				for (int i = 0; i < m_root->word.size(); i++)
				{
					if (m_root->word[i] > w[i])
					{
						Insert(m_root->left, w, d);
						didInsert = true;

					}
					else if (m_root->word[i] < w[i])
					{
						Insert(m_root->right, w, d);
						didInsert = true;
					}
				}
				if (!didInsert)
				{
					Insert(m_root->right, w, d);
				}

			}
			else if (m_root->word[0] > w[0])
			{
				Insert(m_root->left, w, d);
			}
			else
			{
				Insert(m_root->right, w, d);
			}
		}
	}
	int currentSize;
	int dict[];
	bool Find(words*, int);
	int Height(words*);
	int NumChildren(words*);
	BST()
	{
		currentSize = 10;
		dict = new words[currentSize];
		int ratio = 1;
	}
	/*
	Class Name: Growtree
		Description:grow bst
		Public Methods:
		Private Methods:
 */
	void GrowTree()
	{
		int growSize = currentSize * 2;
		words* B = new words[growSize];

		for (int i = 0; i < currentSize; i++)
		{
			B[i] = dict[i];
		}

		currentSize = growSize;
		delete[] dict;
		dict = B;
		delete[] B;
	}

public:
	BST()
	{
		m_size = 0;
		m_root = NULL;
	}

	/*WordTree(string *w, string *d)
	{
	}*/

	void Insert(string w, string d)
	{
		if (!m_root)
		{
			words* temp = new words(w, d);
			m_root = temp;
		}
		else
		{
			Insert(m_root, w, d);
		}
	}
	void Print();
	bool Find(int);
	void Delete();
	int Height();

	int main()
	{

		vector<string> animals_Data;
		char k;
		string word = "";
		vector<string> Matches;
		string Top_Results[10];
		LinkedList dict;
		int SearchResults;

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
			dict.insert(Temp);
		}
		Load_Words.End();

		cout << termcolor::green << Load_Words.Seconds() << termcolor::reset
			<< " seconds to read in the data." << termcolor::reset << endl;



		cout << "Type keys and watch what happens. Type capital" << termcolor::red << " Z to quit." << termcolor::reset << endl;
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
					cout << "plz type letter only!" << endl;
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
			Matches = dict.Find(word);
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
