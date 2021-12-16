#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll C[205][205];

ll fn(ll n, ll r)
{
      if(n<r)return 0;
      if (C[n][r]!=-1)return C[n][r];

      if (n==r)return C[n][r] = 1;
      if (r==1)return C[n][r] = n;

      return C[n][r] = fn(n-1,r)+fn(n-1,r-1);
}

int main()
{
      memset(C,-1,sizeof C);
      ll n;
      cin >> n;
      cout << fn(n-1,11) << endl;

      return 0;
}
