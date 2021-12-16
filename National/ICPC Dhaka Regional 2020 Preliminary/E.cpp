#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n , cnt = 1 , sum = 0, fst = -1;
            scanf("%lld",&n);

            ll A[n+5] , neg = -1000000000012;

            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  if (A[i]<=0)neg = max(neg,A[i]);
            }

            vector<ll> v;
            for (int i=1 ; i<=n ; i++){
                  if (A[i] != 0)v.push_back(A[i]);
            }

            printf("Case %d: ",_t);

            if (v.empty()){
                  printf("0 0\n");
                  continue;
            }

            if (v[0]>0){
                  sum+=v[0];
                  fst = 1;
            }

            for (int i=1 ; i<v.size() ; i++){
                  if ((v[i-1]<0 && v[i]>0) || (v[i-1]>0 && v[i]<0)){
                        cnt++;
                  }
                  if (v[i]>0)sum+=v[i];
            }

            if (sum==0){
                  sum = neg;
            }

            if (cnt<=2){
                  printf("%lld 0\n",sum);
            }
            else {
                  ll mv = 0;
                  if (fst==1){
                        if (cnt%2==1)mv = cnt/2;
                        else mv = (cnt-1)/2;
                  }
                  else {
                        mv = (cnt-2)/2;
                  }

                  printf("%lld %lld\n",sum,mv);
            }
      }


      return 0;
}
