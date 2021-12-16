#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,ans;

ll cal(ll r)
{
      return (r*(r+1))/2;
}

ll secondHalf()
{
      ll total = cal(k-1);
      ll b = 0 , e = k-1 , ret = 0;

      while(b<=e){
            ll mid = (b+e)/2;
            ll taken = total - cal(mid);

            if (taken>=n){
                  ret = max(ret,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return k-1-ret;
}

ll firstHalf()
{
      ll ret = k , b = 0 , e = k;
      while(b<=e){
            ll mid = (b+e)/2;
            if (cal(mid)>=n){
                  ret = min(ret,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      n-=cal(ret);
      return ret+secondHalf();
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            cin >> k >> n;
            cout << firstHalf() << endl;
      }

      return 0;
}
