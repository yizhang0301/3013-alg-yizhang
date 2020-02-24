#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Node
 *
 * Description:take string to list
 * Public Methods:string:definition,word
 *				Node*next
 * Usage:Node:Temp
 *
 */
struct Node
{
	string definition;			
	string word;				
	Node* next;					
};

/**
 * List
 * Description:Link list
 *
 */
class wordList
{
private:
	Node* Head;					
	Node* End;					
	int length;					
	int wordfound;				
	string listwords[10];
public:


	wordList()
	{
		Head = nullptr;
		End = nullptr;
		length = 0;
		wordfound = 0;

	}

	/**
	 * Public : insert(string W, string D)
	 *
	 * Description:get a new node
	 * Params:string a b
	 */
	void insert(string a, string b)
	{
		Node* temp = new Node;
		temp->word = a;
		temp->definition = b;
		temp->next = nullptr;
		if (Head == nullptr)
		{
			Head = temp;
			length++;
		}
		else if (Head->next == nullptr)
		{
			End = temp;
			Head->next = End;
			length++;
		}
		else
		{
			End->next = temp;
			End = temp;
			length++;
		}
		temp = nullptr;
	}

	/**
	 * Public: search(string input)
	 *
	 * Description:looking and string list
	 * Params:string input		
	 */
	void search(string input)
	{
		int timeSeen = 0;
		Node* temp = new Node;
		temp = Head;
		int i = 0;
		while (temp != nullptr)
		{
			string check = temp->word;

			size_t found = check.find(input);

			if (found != string::npos)
			{
				if (i < 10)
				{
					listwords[i] = temp->word;
					i++;
				}
				timeSeen++;
			}

			temp = temp->next;
		}
		wordfound = timeSeen;
		temp = nullptr;
	}

	/**
	 * Public : printlistwords()
	 *
	 * Description:print 10 words
	 */
	void printlistwords()
	{
		bool printed = false;
		for (int i = 0; i < 10; i++)
		{
			
				printed = true;
				cout << listwords[i] << " -> ";
		}
		cout << endl;

	}
	int Found()
	{
		return wordfound;
	}


};
