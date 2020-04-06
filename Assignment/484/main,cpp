///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           YI ZHANG
// Email:            zy19950301@126.com
// Label:            484
// Title:            The Department of Redundancy Department
// Course:           3013-alg
// Semester:         Spring 2020
//
// Description: Write a program that will remove all duplicates from a sequence of integers and print the list of unique
//integers occuring in the input sequence, along with the number of occurences of each.
//
//       
//
// Files:  main.cpp          
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
int main()
{
    map<int, int> m;
    vector<int> v;
    int a;
 
    while(cin >> a) {
        if(m.find(a) == m.end()) {
            m.insert(make_pair(a, 1));
            v.push_back(a);
        } else
            m[a]++;
    }
 
    for(int i=0; i<(int)v.size(); i++)
        cout << v[i] << " " << m[v[i]] << endl;
 
    return 0;
}
