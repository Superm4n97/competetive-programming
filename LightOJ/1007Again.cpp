#include<bits/stdc++.h>
#define ll unsigned long long
#define maxn 5000006
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll phi[maxn];

void eulerTotient()
{
      for (int i=1 ; i<maxn ; i++)phi[i] = i;

      for (int i=2 ; i<maxn ; i++){
            if (phi[i]==i){
                  for (int j=i ; j<maxn ; j+=i){
                        phi[j]/=i;
                        phi[j]*=(i-1);
                  }
            }
      }

      for (int i=1 ; i<maxn ; i++)phi[i] =phi[i-1] + phi[i]*phi[i];
}

int main()
{
      eulerTotient();
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            int a, b;
            scanf("%d %d",&a,&b);
            printf("Case %d: %llu\n",_t,phi[b]-phi[a-1]);
      }

      return 0;
}
