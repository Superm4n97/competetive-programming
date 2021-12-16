#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

ll n,A[15];

ll fnc(vector<ll> v)
{
      ll cnt = 0;
      for (int i=0 ; i<n ; i++){
            if (v[i]>0)cnt++;
      }
      if (cnt<=1)return 0;

      ll mx = 0;

      vector<ll> v_new = v;
      for (int i=0 ; i<n ; i++){
            if (v[i] != 0){
                  ll L = -1 , R = n;
                  v_new[i] = 0;
                  for (int j = i+1 ; j<n; j++){
                        if (v[j]>0){
                              R = j;
                              break;
                        }
                  }
                  for (int j = i-1 ; j>=0 ; j--){
                        if (v[j]>0){
                              L = j;
                              break;
                        }
                  }
                  if (L == -1){
                        mx = max(mx,A[R]+fnc(v_new));
                  }
                  else if (R==n)mx = max(mx,A[L]+fnc(v_new));
                  else mx = max(mx,A[L]*A[R] + fnc(v_new));

                  v_new[i] = v[i];
            }
      }
      return mx;
}

int main()
{
      while(scanf("%lld",&n)!=EOF){
      vector<ll> v;
      for (int i=0 ; i<n ; i++){
            scl(A[i]);
            v.push_back(A[i]);
      }

      cout << fnc(v) << endl;
      }

      return 0;
}
