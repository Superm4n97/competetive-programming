#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector<ll> v;
ll n,m,x,y,sum = 0;

ll findPos(ll val)
{
      ll ret = n-1 , b = 0 , e = n-1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (v[mid]>=val){
                  ret = min(mid,ret);
                  e = mid-1;
            }
            else b = mid+1;
      }
      return ret;
}

ll findPos2(ll val)
{
      ll ret = 0 , b = 0 , e = n-1;
      while(b<=e){

      }
}

ll cal(ll p)
{
      return max(y-sum+v[p],0LL)+max(x-v[p],0LL);
}

int main()
{
      scanf("%lld",&n);
      for (int i=0 ; i<n ; i++){
            ll a;
            scanf("%lld",&a);
            v.push_back(a);
            sum+=a;
      }
      sort(v.begin(),v.end());

      scanf("%lld",&m);

      while(m--){
            scanf("%lld %lld",&x,&y);
            ll p = findPos(x);
            ll ans = cal(p);
            if (p>0)ans = min(ans,cal(p-1));
            printf("%lld\n",ans);
      }


      return 0;
}
