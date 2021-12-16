#include<bits/stdc++.h>

using namespace std;

/*
n m
1 2
1 3
2 4
3 4
3 5
4 5
*/


vector < int > G[10];

int main()
{
      int a,b;
      cin >> a >> b;

      G[a].push_back(b);
      G[b].push_back(a);


      return 0;
}

