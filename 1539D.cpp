#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,b,e,ans,sum;
vector<pair<ll,ll> > vp;

bool fn(ll pre)
{
      ll need = sum-pre;
      for (int i=0 ; i<n ; i++){
            if (pre>=vp[i].first){
                  pre+=vp[i].second;
                  need-=vp[i].second;
            }
            else break;
      }
      if (need>0)return false;
      return true;
}

int main()
{
      cin >> n;
      b = 0 , e = 0;
      for (int i=0 ; i<n ; i++){
            ll a,b;
            cin >> a >> b;
            vp.push_back({b,a});
            e+=a;
      }
      sort(vp.begin(),vp.end());

      ans = e*2+5,sum = e;

//      show(sum);

      while(b<=e){
            ll mid = (b+e)/2;
            if (fn(mid)){
//                  show(mid);
                  ans = min(ans,mid*2+(sum-mid));
                  e = mid-1;
            }
            else b = mid+1;
      }
      cout << ans << endl;

      return 0;
}
