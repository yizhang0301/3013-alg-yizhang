#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


const int maxsize = 31;
int limit;
class UnionFind{
    vector<int>parent;
public:
        vector<bool>root;


    int Union(int a,int b);
    void initial()
    {
       root.resize(maxsize);
       parent.resize(maxsize);
       for(int k=1;k<=maxsize-1;k++)
       {
           parent[k]=1;
           root[k]= true;
       }
    }
    int findroot(int k);
};
int UnionFind::findroot(int k)
{
     int r = k;
    while(!root[r]){
        r = parent[r]; // search for the root
    }
    int pe;
    int e = k;
    while(e != r){
        pe = parent[e];
        parent[e] = r;
        e = pe;
    }
    return r;
}
int UnionFind::Union(int r1,int r2)
{
       if(parent[r1] < parent[r2])
        {
        parent[r2] += parent[r1];
        parent[r1] = r2;
        root[r1] = false;
        return r2;
        }
        else
        {
        parent[r1] += parent[r2];
        parent[r2] = r1;
        root[r2] = false;
        return r1;
        }
}
class graph
{
private:
    int count;
    UnionFind uf;
public:
    void initial();
    void solve();
    void output();
};
void graph::initial()
{
    count =  0;
    uf.initial();
}
void graph::solve()
{
    char ch[3];
    gets(ch);
    limit = ch[0]-'A'+1;
    while(gets(ch))
    {
        if(!ch[0])
            break;
        int temp1 = ch[0]-'A'+1;
        int temp2 = ch[1]-'A'+1;
        int ra = uf.findroot(temp1);
        int rb = uf.findroot(temp2);
        if(ra!=rb)
            uf.Union(ra,rb);
    }
}
void graph::output()
{
    for(int i=1;i<=limit;i++)
        if(uf.root[i])
        count++;
    printf("%d\n",count);


}
int main()
{
    int cas;
    graph gh;


    scanf("%d",&cas);
    getchar();
    getchar();
    while(cas--)
    {
        gh.initial();
        gh.solve();
        gh.output();
        if(cas)
            printf("\n");
    }


    return 0;
}
