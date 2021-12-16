#include<bits/stdc++.h>
#define ll long long int
#define maxn 2000006
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll pf[maxn];

void initialize()
{
      memset(pf,-1,sizeof pf);
      pf[1] = 1;

      for (int i=2 ; i<maxn ; i++){
            if (pf[i]==-1){
                  for (int j = i ; j<maxn ; j+=i){
                        if (pf[j]==-1)pf[j] = i;
                  }
            }
      }
      return;
}

int main()
{
      initialize();

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){

            ll n , k;
            scanf("%lld %lld",&n,&k);

            ll A[n+5] , ans[n+5];
            unordered_map<ll,ll> curr,pre;

            ans[0] = 0;

            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);

                  ans[i] = ans[i-1]+1;

                  while(A[i]>1){
                        ll temp = pf[A[i]];
                        while(A[i]%temp==0)A[i]/=temp;

                        if (curr[temp]==0 || curr[temp]+k<i){
                              curr[temp] = i;
                              pre[temp] = 0;
                        }
                        else{
                              if (pre[temp]==0){
                                    if (ans[i])
                                    ans[i] = min(ans[i],ans[curr[temp]]+1);
                                    pre[temp] = curr[temp];
                                    curr[temp] = i;
                              }
                              else {
                                    if (pre[temp]+k>=i && ans[pre[temp]]<ans[curr[temp]]){
                                          ans[i] = min(ans[i],ans[pre[temp]]+1);
                                          curr[temp] = i;
                                    }
                                    else {
                                          ans[i] = min(ans[i],ans[curr[temp]]+1);
                                          pre[temp] = curr[temp];
                                          curr[temp] = i;
                                    }
                              }
                        }
                  }
            }
//            for (int i=1;i<=n ; i++)cout << ans[i]-1 << " ";
//            cout << endl;
            printf("Case %d: %lld\n",_t,ans[n]-1);
      }

      return 0;
}
