#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 2000006

using namespace std;

int cnt[maxn];
vector<int> prime;

void fn()
{
      memset(cnt,0,sizeof cnt);

      for (int i=2 ; i<maxn ; i++){
            if (cnt[i]==0){
                  prime.push_back(i);
                  for (int j=i ; j<maxn ; j+=i)cnt[j] = 1;
            }
      }
}

ll bs(ll val)
{
      ll b = 0 , e = prime.size()-1;
      ll  ret = e;
      while(b<=e){
            ll mid = (b+e)/2;
            if (prime[mid]>=val){
                  ret = min(ret , mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      return prime[ret];
}

int main()
{
      fn();

      ll tc;
      scl(tc);

      while(tc--){
            ll d;
            scl(d);

            ll x1 = bs(1+d);
            ll x2 = bs(x1+d);
//            ll x3 = bs(d+x2+1);
//            show(x3);
            printf("%I64d \n",x1*x2);

      }


}
