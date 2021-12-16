#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000000000012

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll A[n+5] , ans[n+5];
      vector < ll > v;

      for (int i=0 ; i<=n ; i++)ans[i] = inf;

      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a;

            v.push_back(a);
      }

      sort(v.rbegin() , v.rend());

      ll x = 0 , cnt = 0;

      for (int i=0 ; i<n ; i+=2){
            ans[i] = v[x];
            x++;
      }

      queue < ll > q;

      for (int i=1 ; i<n ; i+=2){

            if (i<n-1 && v[x]<ans[i+1] && v[x]<ans[i-1]){
                  ans[i] = v[x];
                  cnt++;
            }
            else {
                  q.push(v[x]);
                  i-=2;
            }
            x++;

            if (x==v.size())break;
      }

      for (int i=0 ; i<n ; i++){
            if (ans[i]==inf){
                  ans[i] = q.front();
                  q.pop();
            }
      }

      cout << cnt << endl;
      for (int i=0 ; i<n ; i++)cout << ans[i] << " ";
      cout << endl;


      return 0;
}

