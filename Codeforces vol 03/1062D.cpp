#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006
#define scl(x) scanf("%I64d",&x)

using namespace std;

ll n, d[maxn] , sum[maxn];

int main()
{
      scl(n);
      memset(d,-1,sizeof d);
      d[0] = d[1] = 1;

      for (ll i=2 ; i<=n ; i++){

            if (d[i]==-1){
                  d[i]=i;
                  ll temp = i*i;
                  while(temp<=n){
                        if (d[temp]==-1)d[temp] = i;
                        temp+=i;
                  }
            }
      }

      for (int i=4 ; i<=n ; i++){
            if(d[i]==i)continue;

            vector < ll > v;
            ll temp = i;

            while(temp>1){
                  v.push_back(d[temp]);
                  temp/=d[temp];
            }

            ll cnt = 1 , ans = 1 , last = v.size()-1;

            for (int j = 1 ; j<v.size() ; j++){

                  if (v[j]==v[j-1])cnt++;
                  else {
                        ll p = v[j-1] , a = cnt;

                        ll pal = 1;

                        for (int k = 0 ; k<=cnt ; k++)pal*=p;
                        pal = pal-1;
                        pal/=(p-1);

                        ans*=pal;

                        cnt = 1;
                  }
            }

            ll p = v[last] , a = cnt;
            ll pal = 1;

            for (int k = 0 ; k<=cnt ; k++)pal*=p;
            pal = pal-1;
            pal/=(p-1);
            ans*=pal;

            sum[i] = (ans-1-i)*4;
      }

      for (int i=4 ; i<=n ; i++)sum[i]+=sum[i-1];

      cout << sum[n] << endl;


      return 0;
}
