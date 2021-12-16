#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n;
ll X[maxn] , Y[maxn];

ll different(ll a, ll b , ll c)
{
      return a+b-c;
}

int main()
{
      cin>> n;

      for (int i=1 ; i<=n ; i++){
            cin >> X[i] >> Y[i];
      }

      vector < ll > ans;

      ans.push_back(1);

      if (X[X[1]] == Y[1] || Y[X[1]]==Y[1]){
            ans.push_back(X[1]);
            ans.push_back(Y[1]);
      }
      else {
            ans.push_back(Y[1]);
            ans.push_back(X[1]);
      }

      for (int i=1 ; i<n-1 ; i++){
            ll a = ans[i];
            ans.push_back(different(X[a],Y[a],ans[i+1]));
      }

      for (int i=0 ; i<n ; i++)cout << ans[i] << " ";
      cout << endl;


      return 0;
}
