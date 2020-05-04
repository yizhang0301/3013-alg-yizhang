/////////////////////////////////////////////////////////////////////////////////
// Author:           yi zhang
// Email:            zy19950301
// Label:            uVA 11597
// Title:            subtree
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 		subtree
//      
// Files:            
//		main.cpp
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main() {
	int numV; 
  int sum; 
  int subtree;
  int value;
	int numC = 1;								
	cin >> numV;							

	while (numVerts != 0) {
		value = numV - 1;				
		sum = (numV * value) / 2;	
		subtree = sum / value;		
		cout << "Case " << numC << ": " << subtree << endl; 
    numC++;								
		cin >> numV;					
	}
	return 0;
}
