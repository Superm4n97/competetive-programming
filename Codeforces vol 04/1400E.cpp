#include<bits/stdc++.h>
#define ll long long int
#define show(x)         cout << #x << " : " << x << endl
#define maxn 5005
#define inf 1000000000012

using namespace std;


ll rec(vector < ll > v)
{
      if(v.size()==1)return 1;

      ll n = v.size() , mn = inf , ret = 0;
      vector < ll > v_new;

      for (int i = 0; i<n ; i++)mn = min(mn,v[i]);
      for (int i = 0; i<n ; i++)v[i]-=mn;

      for (int i = 0; i<n ; i++){
            if (v[i])v_new.push_back(v[i]);

            if(v[i]==0 && !v_new.empty()){
                  ret+=rec(v_new);
                  v_new.clear();
            }

            if (i==n-1 && !v_new.empty())ret+=rec(v_new);
      }

      return min(ret+mn,n);
}

int main()
{
      ll A[maxn] , n;
      cin >> n;

      for (int i = 0; i<n ; i++){
            cin >> A[i];
      }

      vector < ll > v;

      ll ans = 0;

      for (int i=0; i<n; i++){

            if(A[i])v.push_back(A[i]);

            if (A[i]==0 && !v.empty()){
                  ans+=rec(v);
                  v.clear();
            }

            if (i==n-1 && !v.empty()){
                  ans+=rec(v);
            }
      }

      cout << min(ans,n) << endl;



      return 0;
}
