#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n;
string G[60];

bool valid(ll i, ll j)
{
      if (i>=0 && i<n && j>=0 && j<n && G[i][j]=='.')return true;
      return false;
}

bool check(ll i, ll j)
{
      if (valid(i,j) && valid(i+1,j) && valid(i+1,j-1) && valid(i+1,j+1) && valid(i+2,j))return true;
      return false;
}

void f(ll i,ll j)
{
      G[i][j] = G[i+1][j-1] = G[i+1][j] = G[i+1][j+1] = G[i+2][j] = '#';
}

int main()
{
      cin >> n;

      for (int i=0 ; i<n ; i++)cin >> G[i];

      bool ans = true;

      for (int i=0 ; i<n ; i++){
            for (int j = 0 ; j<n ; j++){
                  if (G[i][j]=='.'){
                        if (check(i,j)){
                              f(i,j);
                        }
                        else ans = false;
                  }
            }
      }

      cout << (ans?"YES":"NO") << endl;


      return 0;
}
