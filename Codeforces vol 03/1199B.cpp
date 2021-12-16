#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      double H,L;
      cin >> H >> L;

      double ans = L*L - H*H;
      ans/=(2*H);

      printf("%.13f\n",ans);


      return 0;
}
