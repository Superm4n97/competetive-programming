#include<bits/stdc++.h>
#define ll long long int
#define maxn 400005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll S[4*maxn] , A[maxn] , n , k;
vector < ll > v;

void build(ll node, ll b, ll e)
{
      if (b==e){
            {/**Initial Value assign**/
                  S[node] = A[b];
            }
            return;
      }

      ll mid = (b+e)/2;
      build(node*2 , b, mid);
      build(node*2+1 , mid+1, e);

      { /**Merging two childes**/
            S[node] = max(S[node*2],S[node*2+1]);
      }

      return;
}


ll query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x){
            /**Base Value of extra segments**/
            return 0;
      }

      if(b>=x && e<=y){
            return S[node];
      }

      ll mid = (b+e)/2;
      ll t1 = query(node*2,b,mid ,x,y);
      ll t2 = query(node*2+1,mid+1,e,x,y);

      {/**main calculation**/

            return max(t1,t2);
      }
}

ll bound(ll x)
{
      ll b = 0 , e = n-1 , ret = n+4;

      while(b<=e){
            ll mid = (b+e)/2;
            if (v[mid]>=x){
                  ret = min(ret,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }

      return ret+1;
}

void solve()
{
      build(1,1,n);

      ll ans = 0;


      if (n==1){
            cout << 1 << endl;
            return;
      }

      for (int i=1 ; i<=n ; i++){

            ll t1 = query(1,1,n,1,i) , t2 = 0;

            ll tut = bound(v[i-1]+1+k);
            if (tut<=n)
            t2 = query(1,1,n,tut,n);

            ans = max(ans,t1+t2);
      }

      cout << ans << endl;

      return;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            cin >> n >> k;
            v.clear();

            for (int i=0 ; i<n; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }
            for (int i=0 ; i<n; i++){
                  ll a;
                  cin >> a;
            }


            sort(v.begin() , v.end());

            ll l = 0 , r = 0;
            while(r<n){

                  while(v[r] - v[l] > k)l++;
                  A[r+1] = r-l+1;

                  r++;
            }

//            for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
//            cout << endl;


            solve();
      }

      return 0;
}
