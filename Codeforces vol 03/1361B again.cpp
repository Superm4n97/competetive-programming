#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout<<#x<<" : " <<x<<endl
#define mod1 1000000007
#define mod2 1000000009
#define mod3 1000000021

using namespace std;

ll amodb(ll a, ll b)
{
      return a-a/b*b;
}

ll bigmod1(ll a, ll p)
{
      if (p==0)return 1LL;
      ll temp = bigmod1(a,p/2LL);
      temp = amodb(temp*temp,mod1);
      if (p&1LL)temp=amodb(temp*a,mod1);
      return temp;
}

ll bigmod2(ll a, ll p)
{
      if (p==0)return 1LL;
      ll temp = bigmod2(a,p/2LL);
      temp = amodb(temp*temp,mod2);
      if (p&1LL)temp=amodb(temp*a,mod2);
      return temp;
}

ll bigmod3(ll a, ll p)
{
      if (p==0)return 1LL;
      ll temp = bigmod3(a,p/2LL);
      temp = amodb(temp*temp,mod3);
      if (p&1LL)temp=amodb(temp*a,mod3);
      return temp;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n,p;
            vector<ll> v;
            scanf("%lld %lld",&n,&p);
            for (int i=0; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  v.push_back(a);
            }
            if (p==1){
                  if (n&1LL)printf("1\n");
                  else printf("0\n");
                  continue;
            }

            sort(v.rbegin(),v.rend());
            ll sum1 = 0 , sum2 = 0, sum3 = 0;

            for (int i=0; i<n; i++){
                  if (sum1==0 && sum2==0 && sum3==0){
                        sum1 = bigmod1(p,v[i]);
                        sum2 = bigmod2(p,v[i]);
                        sum3 = bigmod3(p,v[i]);
                  }
                  else {
                        sum1-=bigmod1(p,v[i]);
                        sum2-=bigmod2(p,v[i]);
                        sum3-=bigmod3(p,v[i]);
                        if (sum1<0LL)sum1+=mod1;
                        if (sum2<0LL)sum2+=mod2;
                        if (sum3<0LL)sum3+=mod3;
                  }
            }
            printf("%lld\n",sum1);
      }

      return 0;
}
