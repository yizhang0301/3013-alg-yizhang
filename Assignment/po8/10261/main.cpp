#include<iostream>
#include<string>
#include<string.h>
#include<set>

bool memorry[MAXN][MAXL];
int nCars[MAXN];
int choice[MAXN][MAXL];
int sumLength[MAXN];
using namespace std;
int main(){
    int Cases;
    int boatLength;
    int carLength;
    bool isfirstcase = true;
    cin>>Cases;
    while(Cases--){
        if(isfirstcase)
            isfirstcase = false;
        else
            cout<<endl;
        cin>>boatLength;
        boatLength*=100;
        int cars = 1;
        sumLength[0] = 0;
        nCars[0] = 0;
        while(cin>>carLength && carLength != 0){
            if(cars < MAXN){
                nCars[cars] = carLength;
                sumLength[cars] = sumLength[cars-1]+carLength;
                cars++;
            }
        }
        cars--;
        memset(choice,-1,sizeof(choice));
        memset(memorry,false,sizeof(memorry));
        memorry[0][0] = true;
        pair<int,int> longest;
        for(int i = 0;i < cars;i++)
            for(int j = 0;j <= boatLength;j++)
                if(memorry[i][j]){
                    if(j+nCars[i+1] <= boatLength){
                        memorry[i+1][j+nCars[i+1]] = true;
                        choice[i+1][j+nCars[i+1]] = 1;
                        longest = make_pair(i+1,j+nCars[i+1]);
                    }
                    if(sumLength[i]+nCars[i+1]-j <= boatLength){
                        memorry[i+1][j] = true;
                        choice[i+1][j] = 0;
                        longest = make_pair(i+1,j);
                    }
                }
 
        cout<<longest.first<<endl;
        string solution;
        for(int i = longest.first,j = longest.second;i > 0&&choice[i][j] != -1 ;i--){
            solution = (choice[i][j]? "port\n":"starboard\n") + solution ;
            if(choice[i][j])
                j -= nCars[i];
        }
            cout<<solution;
    }
    return 0;
}
