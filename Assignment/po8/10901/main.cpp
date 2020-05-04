 ///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           YI ZHANG
// Email:            zy19950301@126.com
// Label:            10901
// Title:            Ferry Loading
// Course:           3013-alg
// Semester:         Spring 2020
//
// Description:  A queue based approach to solving this problem.
//
//       
//
// Files:  main.cpp          
/////////////////////////////////////////////////////////////////////////////////
#include <climits>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
int event[MAXM];
bool side[MAXM];
int times[MAXM];
 
int main() {
	int c, n, t, m;
	cin >> c;
	while(c--) {
		cin >> n >> t >> m;
		for(int i = 0; i < m; i++) {
			string si;
			cin >> event[i] >> si;
			side[i] = si == "left";
		}
		queue<int> left, right, inBoat;
		bool inLeft = true;
		int arrivalTime = INT_MAX;
		int currEv = 0;
 
		while(currEv < m || arrivalTime != INT_MAX) {
			if(currEv != m && event[currEv] <= arrivalTime) {
				(side[currEv] ? left : right).push(currEv);
				if(arrivalTime == INT_MAX) arrivalTime = event[currEv];
				currEv++;
			} else {
				while(!inBoat.empty()) {
					times[inBoat.front()] = arrivalTime;
					inBoat.pop();
				}
				if(left.empty() && right.empty()) {
					arrivalTime = INT_MAX;					
				} else {
					queue<int>& curr = inLeft ? left : right;
					while(!curr.empty() && (int) inBoat.size() < n) {
						inBoat.push(curr.front());
						curr.pop();
					}
					arrivalTime = arrivalTime + t;
					inLeft = !inLeft;
				}
			}
		}
		for(int i = 0; i < m; i++) cout << times[i] << endl;
		if(c) cout << endl;
	}
	return 0;
