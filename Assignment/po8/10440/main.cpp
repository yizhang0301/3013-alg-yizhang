///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           YI ZHANG
// Email:            zy19950301@126.com
// Label:            10440
// Title:            Ferry Loading
// Course:           3013-alg
// Semester:         Spring 2020
//
// Description:   A greedy approach to ferryiing cars across a river.
//
//       
//
// Files:  main.cpp          
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int Max(int a,int b){
    if (a>b)
        return a;
    else
        return b;
}
 
class Ferry{
    private:
        int n;
        int m;
        int t;
        int cars[MAXN];
    public:
        void process();
};
 
void Ferry::process(){
    int cases;
    int ansTime,ansNum;
 
 
    cin >>cases;
    while(cases--){
        ansTime = 0;
        ansNum = 0;
        cin>>n>>t>>m;
        for(int i = 0;i < m;i++){
            cin>>cars[i];
        }
        
        if(n > m){
            ansTime = cars[m-1] + t;
            ansNum = 1;
        }
        else if(m % n == 0){
            for(int i = n - 1;i < m;i += n){
                ansTime = Max(ansTime,cars[i]);
                ansTime += 2 * t;
            }
            ansTime = ansTime - t;
            ansNum = m/n;
        }
        else{
            int remainder;
            remainder = m%n;
            ansTime = cars[remainder - 1]+2*t;
            for(int i = remainder + n - 1;i < m;i = i + n){
                ansTime = Max(ansTime ,cars[i] );
                ansTime += 2 * t;
            }
            ansTime -=  t;
            ansNum = m/n + 1;
        }
 
        cout<<ansTime<<" "<<ansNum<<endl;
    }

int main()
{
    Ferry ferry;
    ferry.process();
    return 0;

}
