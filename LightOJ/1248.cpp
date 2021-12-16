#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll N;

double rec(ll paisi)
{
      if(paisi==N)return (double)0;
      double n = N, rc = rec(paisi+1)+1 , ps = (double)paisi;

      return ((n-ps)*rc+paisi)/(n-ps);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int i=1 ; i<=tc ; i++){
            scanf("%lld",&N);

            printf("Case %d: %.9lf\n",i,rec(0));
      }
}
