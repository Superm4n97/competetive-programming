#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007
#define maxn 1000006

using namespace std;

ll n,p,tc,fre[maxn],cnt[maxn];

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;
      ll temp = bigmod(a,p/2);
      temp = amod(temp*temp);
      if (p&1LL)temp = amod(temp*a);
      return temp;
}

int main()
{
      scanf("%lld",&tc);
      while(tc--){
            vector<ll>v,lst;

            scanf("%lld %lld",&n,&p);
            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  v.push_back(a);
                  cnt[a]++;
                  if (cnt[a]==1)lst.push_back(a);
            }

            if (p==1){
                  if (n&1LL)printf("1\n");
                  else printf("0\n");
                  continue;
            }

            sort(v.rbegin(),v.rend());
            ll sum = -1;

            for (int i=0 ; i<n ; i++){
                  if (sum==-1)sum = v[i];
                  else {
                        ll a = v[i];
                        fre[a]++;
                        while(fre[a]==p){
                              a++;
                              fre[a]++;
                              if (cnt[a]==0){
                                    cnt[a]++;
                                    lst.push_back(a);
                              }
                        }
                        if (a==sum){
                              sum = -1;
                              fre[a] = 0;
                        }
                  }
            }
            if (sum==-1){
                  printf("0\n");
                  continue;
            }
            ll ans = bigmod(p,sum);
/*
            for (int i=0 ; i<lst.size() ; i++){
                  ans -= fre[lst[i]]*bigmod(p,lst[i]);
                  fre[lst[i]] = cnt[lst[i]] = 0;
            }
*/

            printf("%lld\n",bigmod(p,sum));

      }

      return 0;
}
