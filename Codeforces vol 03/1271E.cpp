#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << endl

using namespace std;

ll n,k;

ll cnt(ll x , ll type)
{
      ll temp = x , ret = 0 , off = 1;

      if (type==2)off = 2;

      while(true){

            ll l = temp , r = temp+off-1;

            if (l>n)return ret;

            if (r<=n)ret+=off;
            else {
                  r = n;
                  ret+=(r-l+1);
                  return ret;
            }

            temp*=2;
            off*=2;
      }
}

int main()
{
      cin >> n >> k ;
      if (k==n){
            cout << 1 << endl;
            return 0;
      }
      if (k==n-1){
            cout << 2 << endl;
            return 0;
      }

      ll b = 3 , e = n , ans = 2;
      if (n%2==0)e--;


      while(b<=e){
            ll mid = (b+e)/2;

            if (mid%2==0)mid--;

            ll x = cnt(mid,1);

            if (x>=k){
                  ans = max(ans,mid);
                  b = mid+2;
            }
            else e = mid-2;
      }

      b = 4 , e = n;
      if (e%2)e--;


      while(b<=e){

            ll mid = (b+e)/2;

            if (mid%2)mid--;

            ll x = cnt(mid,2);

            if (x>=k){
                  ans = max(ans,mid);
                  b = mid+2;
            }
            else e = mid-2;
      }

      cout << ans << endl;

      return 0;
}
