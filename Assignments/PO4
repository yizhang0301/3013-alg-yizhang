///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           YI ZHANG
// Email:            zy19950301@126.com
// Label:            PO4
// Title:            Processing in Trie Tree Time
// Course:           3013-alg
// Semester:         Spring 2021
//
// Description:  use trie to search dic.txt
//       
//
// Files:  main.cpp          
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "termcolor.hpp"
#include "Timer.hpp"
#include "mygetch.hpp"
#include <time.h>
using namespace std;
#define CHAR_SIZE 26
 /**
  *
  * Function Name: checktop ()
  * Description:check letter
  * Parameters:char
  * Returns:bool
  *
  */
bool checktop(char letter)
{
	int l = letter;
	return (l >= 65 && l <= 90);
}
/**
 *
 * Function Name: checkdown ()
 * Description:check low
 * Parameters:char
 * Returns: bool
 *
 */
bool checkdown(char letter)
{
	int l = letter;
	return (l >= 97 && l <= 122);
}
/**
 *
 * Function Name: checkletter ()
 * Description:check letter
 * Parameters:char
 * Returns: bool
 *
 */
bool checkletter(char letter)
{
	int l = letter;
	return checktop(l) || checkdown(l);
}
/**
 *
 * Function Name: isAlphaOnly ()
 * Description:
 * Parameters: string
 * Returns:bool
 *
 */
bool isAlphaOnly(string word)
{

	for (int i = 0; i < word.length(); i++)
	{
		if (!checkletter(word[i]))
		{
			return false;
		}
	}
	return true;
}
/**
 *
 * Function Name: Mtop ()
 * Description:makeword out
 */
void Mtop(string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (checkdown(word[i]))
		{
			word[i] -= 32;
		}
	}
}
/*
 *   Struct:TrieNode
 *   Description:node about character
 *   Public Methods:TrieNode()
 */
struct TrieNode
{
	bool Leaf;
	TrieNode* character[CHAR_SIZE];
	string word;

	TrieNode()
	{
		this->Leaf = false;

		for (int i = 0; i < CHAR_SIZE; i++)
		{
			this->character[i] = nullptr;
		}
	}
};
/**
 *
 *  Function Name: cletter
 *  Description:count letter
 *  Returns: vector<char>
 *
 */
vector<char> cletter(string filename)
{
	ifstream fin;
	vector<char> alph;

	fin.open(filename);

	string word;
	while (!fin.eof())
	{
		fin >> word;
		for (int j = 0; j < word.size(); j++)
		{
			if (std::find(alph.begin(), alph.end(), word[j]) == alph.end())
			{
				alph.push_back(word[j]);
			}
		}
	}
	return alph;
}
/*
 *    Class Name: Trie
 *    Description:class about tire node
 *    private Methods:
 *       bool deletion(TrieNode *&, string);
 *       void findn(TrieNode *&, string);
 *       vector<string> results;
 *   public Methods:
 *      Trie()                        
 *      void insert(string);
 *      bool deletion(string);
 *      bool search(string);
 *      bool Children(TrieNode const *);Children
 *      vector<string> findn(string);
 */
class Trie
{
	TrieNode* root;
	bool deletion(TrieNode*&, string);
	void findn(TrieNode*&, string);
	vector<string> results;

public:
	Trie()                                  
	{
		root = new TrieNode;
	}
	void insert(string);
	bool deletion(string);
	bool search(string);
	bool Children(TrieNode const*);
	vector<string> findn(string);
};
/**
 *   Private : findn
 *  Description:find all letter
 *  Returns: void
 */
void Trie::findn(TrieNode*& currect, string key)
{
	if (currect->Leaf)
	{
		results.push_back(key);
	}

	for (int i = 0; i < 26; i++)
	{
		if (currect->character[i])
		{
			findn(currect->character[i], key + char(i + 65));
		}
	}
}
vector<string> Trie::findn(string key)
{
	TrieNode* currect = root;
	results.clear();
	for (int i = 0; i < key.length(); i++)
	{                                       
		currect = currect->character[key[i] - 65];
	}
	findn(currect, key);
	return results;
}
/**
 *  Public : insert()
 *  Description:get key
 *  Params: string key
 *  Returns:void
 */
void Trie::insert(string key)
{
	Mtop(key);                         

	TrieNode* currect = root;                  
	for (int i = 0; i < key.length(); i++)
	{                                       
		if (currect->character[key[i] - 65] == nullptr)
		{
			currect->character[key[i] - 65] = new TrieNode();
		}

		currect = currect->character[key[i] - 65]; 
	}

	currect->Leaf = true;                   
}
/**
 *  Public : search()
 *  Description:search letter
 *  Params:string key
 *  Returns:bool
 */
bool Trie::search(string key)
{
	Mtop(key);
	TrieNode* currect = root;

	if (currect == nullptr)                   
	{
		return false;
	}

	for (int i = 0; i < key.length(); i++)
	{
		currect = currect->character[key[i] - 65];  

		if (currect == nullptr)
		{                                   
			return false;
		}
	}                                       
	return currect->Leaf;                    
}
/**
 *  Public : Children()
 *  Description: Returns true if a given node has any children
 *  Params:TrieNode const *currect
 *  Returns: bool
 */
bool Trie::Children(TrieNode const* currect)
{
	for (int i = 0; i < CHAR_SIZE; i++)
	{
		if (currect->character[i])
		{
			return true;                    // child found
		}
	}

	return false;
}
/**
 *   Public : deletion()
 *   Description:delete key.
 *   Params:string key
 *   Returns:bool
 */
bool Trie::deletion(string key)
{
	Mtop(key);
	return deletion(root, key);
}
/**
 *   Public : deletion()
 *   Description:delete a key in the Trie.
 *   Params:TrieNode *&currect, string key
 *   Returns:bool
 */
bool Trie::deletion(TrieNode*& currect, string key)
{                                          
	if (currect == nullptr)
	{
		return false;
	}
	if (key.length())                       
	{                                       
		if (currect != nullptr &&
			currect->character[key[0] - 65] != nullptr &&
			deletion(currect->character[key[0] - 65], key.substr(1)) &&
			currect->Leaf == false)         

		{
			if (!Children(currect))
			{
				delete currect;
				currect = nullptr;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	if (key.length() == 0 && currect->Leaf) 
	{                                       
		if (!Children(currect))
		{                                   
			delete currect;
			currect = nullptr;
			return true;                    
		}
		else                                
		{                                  
			currect->Leaf = false;
			return false;                  
		}
	}
	return false;
}
/**
 *
 * Function Name: loadDictionary ()
 * Description:read file and time
 * Parameters:Trie *&T, string filename
 * Returns:bool
 *
 */
void loadDictionary(Trie*& T, string filename = "")
{
	string word;
	size_t found;
	ifstream fin;

	if (filename == "")
		fin.open("dictionary.txt");
	else
		fin.open(filename);

	Timer time;                             
	time.Start();                          

	while (!fin.eof())                      
	{
		fin >> word;
		if (isAlphaOnly(word))              
		{
			T->insert(word);                
		}
	}
	time.End();
	cout << termcolor::green << time.Seconds()<< termcolor::reset<< " seconds to read in the data." << endl;
}

/**
 *
 * Function Name: Search ()
 * Description:Receive a word and compare it to our linkedlist.
 * Parameters:Trie *T, string word
 * Returns:bool
 */
void Search(Trie* T, string word)
{
	cout << word;                           
	if (T->search(word))                    
	{
		cout << " found." << endl;
	}
	else
	{
		cout << " not found." << endl;      
	}
}
int main()
{
	Trie* T = new Trie();
	loadDictionary(T, "dic.txt");
	char k;                                 
	string word = "";                       
	vector<string> Matches;                 
	string Top_Results[10];                
	int SearchResults;                      

	cout << "Type keys and watch what happens. Type capital"
		<< termcolor::red << " Z to quit."
		<< termcolor::reset << endl;

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
				cout << "please enter letter.\n";
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
		Matches = T->findn(word);
		Auto_Suggestion.End();

		SearchResults = Matches.size();

		if ((int)k != 32)                   // When the key pressed is not "Space bar".
		{
			cout << "Keypressed: " << termcolor::red << k << " = "
				<< termcolor::green << (int)k << termcolor::reset << endl;
			cout << "Current Substr: " << termcolor::red << word
				<< termcolor::reset << endl;
			cout << termcolor::red << SearchResults << termcolor::reset
				<< " words found in " << termcolor::green
				<< Auto_Suggestion.Seconds() << termcolor::reset << " Seconds"
				<< termcolor::reset << endl;

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

			cout << termcolor::reset << endl
				<< endl;
		}
	}

	return 0;
}
