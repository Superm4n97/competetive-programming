#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll phi[maxn], ans[maxn];

void EulerTotient()
{
      for (int i=1 ; i<maxn ; i++)phi[i] = i;

      for (int i=2 ; i<maxn ; i++){
            if (phi[i]==i){
                  for (int j = i ; j<maxn ; j+=i){
                        phi[j]/=i;
                        phi[j]*=(i-1);
                  }
            }
      }
      return;
}
void sumOfGCD()
{
      /// a number N has phi[N/d] number of such number which has gcd d with N
      for (ll i=2; i<maxn ; i++){
            ans[i]+=phi[i]; ///includes coprimes of i (gcd 1 with i)
            for (ll j = i+i ; j<maxn ; j+=i){
                  ans[j]+=(phi[j/i]*i);
            }
      }
      for (int i=1 ; i<maxn ; i++)ans[i]+=ans[i-1];///cumulative sum of answers
      return;
}

int main()
{
      EulerTotient();
      sumOfGCD();

      ll n;
      while(true){
            scanf("%lld",&n);
            if (n==0)break;
            printf("%lld\n",ans[n]);
      }

      return 0;
}
