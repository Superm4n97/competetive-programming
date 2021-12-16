#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005

using namespace std;

ll n,k;
vector < string > vs[maxn] , v;
int  vis[1000];

int main()
{
      cin >> n >> k;

      for (int t = 0 ; t<n ; t++){
            ll a;
            cin >> a;

            for (int i=0 ; i<k ; i++){
                  string s;
                  cin >> s;

                  vs[a].push_back(s);
            }
      }

      for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<k ; j++)v.push_back(vs[i][j]);
      }

      bool sol = true;

      for (int i=1 ; i<v.size() ; i++){
            if (v[i]<v[i-1]){
                  sol = false;
            }
      }

      if (!sol)cout << "IMPOSSIBLE" << endl;
      else {
            cout << v[0][0];
            for (int i=1 ; i<v.size() ; i++){
                  if (v[i][0]!=v[i-1][0])cout << v[i][0];
            }
            cout << endl;
      }
}
/**
2 2
1
aa
p
0
a
a
**/
