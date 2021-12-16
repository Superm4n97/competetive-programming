#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);
            vector<double> v;
            for (int i=0 ; i<n ; i++){
                  double d;
                  scanf("%lf",&d);
                  v.push_back(d);
            }

            double sum = 0;

            sort(v.rbegin(),v.rend());
            for (int i=1 ; i<n ; i++){
                  sum+=v[i];
            }
            sum = sum/(n-1);
            printf("%.10lf\n",v[0]+sum);
      }

      return 0;
}
