#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n,k;
            scanf("%lld %lld",&n,&k);

            vector<ll> vs,vus;
            map<ll,ll> mp;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  vus.push_back(a);
            }

            vs = vus;
            sort(vs.begin(),vs.end());
            vus.push_back(1000000000013);

            for (int i=0 ; i<n ; i++){
                  if (i==n-1)mp[vs[i]] = 1000000000012;
                  else mp[vs[i]] = vs[i+1];
            }

            ll pointer = n-1,cnt = 0;

            for (int i=0 ; i<n ; i++){
                  if (mp[vus[i]]!=vus[i+1])cnt++;
            }

//            show(cnt);

            if(cnt<=k)printf("Yes\n");
            else printf("No\n");
      }

      return 0;
}
/*
5 3
6 3 4 1 2
1 2 3 4 6

6  4 3  2 1

1 -4 0 -2
1 0 -2 -4
*/
