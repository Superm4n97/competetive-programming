#include<bits/stdc++.h>
#define ll long long int
#define maxn 500005
#define inf 100000000000014
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[maxn] , fix[maxn] , nxt[maxn];

int LongestNonDecreasingSequecne_NlogN(vector <ll> org)
{
      if (org.empty())return 0;

      vector <ll> len;
      len.push_back(0);
      len.push_back(org[0]);

      for (int i=1 ; i<org.size() ; i++){

            ll sz_len = len.size();
            if (len[1]>org[i])len[1] = org[i];
            else if (len[sz_len-1] <= org[i])len.push_back(org[i]);
            else {

                  ll b = 1 , e = sz_len-1 , res = -1;
                  while(b<=e){

                        ll mid = (b+e)/2;
                        if (len[mid] <= org[i]){

                              res = max(res,mid);
                              b = mid+1;
                        }
                        else e = mid-1;
                  }
                  len[res+1] = org[i];
            }
      }

      return len.size()-1;
}

int main()
{
      ll n,k;
      cin >> n >> k;


      for (int i=1 ;i<=n; i++){
            cin >> A[i];
            A[i]-=i;
      }
      for (int i=1 ; i<=k ; i++){

            ll a;
            cin >> a;
            fix[a] = 1;
      }

      ll pre = -inf;
      bool solution = true;

      for (int i=1 ; i<=n ; i++){
            if (fix[i]==1){
                  if (A[i]<pre)solution = false;
                  else pre = A[i];
            }
            if (A[i]<pre)A[i] = inf;
      }

      if (!solution){
            cout << -1 << endl;
            return 0;
      }

      pre = inf;
      for (int i=n ; i>=1 ; i--){

            if (A[i]==inf)continue;

            if (fix[i]==1){
                  //nxt[i] = pre;
                  pre = A[i];
            }
            else if (A[i]>pre)A[i] = inf;
      }

//      for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
//      cout << endl;

      vector <ll> v;
      ll ans = 0;
      for (int i=1 ; i<=n ; i++){
            if (A[i]==inf)continue;

            v.push_back(A[i]);
      }

//      show(ans);
//                        for (int j = 0 ; j<v.size() ; j++)cout << v[j] << " ";
//                        cout << endl;
      if (!v.empty())ans += LongestNonDecreasingSequecne_NlogN(v);
//      show(ans);

      cout << n - (ans) << endl;

      return 0;
}
