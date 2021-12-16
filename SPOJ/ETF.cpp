#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll phi[maxn];

void EularTotient()
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

int main()
{
      EularTotient();

      ll tc;
      cin >> tc;

      while(tc--){
            ll a;
            cin >> a;

            cout << phi[a] << "\n";
      }

      return 0;
}
