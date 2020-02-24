
#include <fstream>
#include <iostream>
#include "JsonFacade.hpp"       
#include <time.h>
#include <chrono> 
#include "Timer.hpp"            
#include "List.h"
#include "mygetch.hpp"


using namespace std;

int main()
{
	Timer Load;                                 
	double TimeLoad;
	JsonFacade J("dict_w_defs.json");
	wordList L1;                      

	char Typed;
	string word = "";

	vector<string> keys = J.getKeys();           

	Load.Start();
	for (int i = 0; i < keys.size(); i++)
	{
		string DicWord = J.getKey(i);            
		string DicDef = J.getValue(DicWord);     
		L1.insert(DicWord, DicDef);           
	}

	Load.End();
	TimeLoad = Load.Seconds();                 

	cout << "Type  Z to quit." << endl;;

	while ((Typed = getch()) != 'Z')
	{
		Timer T;                                 
		T.Start();
		word += Typed;                            



		if ((int)Typed != 10)
		{                                         
			cout << word << endl;
		}
		L1.search(word);                       
		T.End();
		double s = T.Seconds();                   
		cout << L1.Found() << " words found in: " << s << "Seconds" <<endl;
		L1.printlistWords();   
		cout << endl;
	}

	return 0;
}
