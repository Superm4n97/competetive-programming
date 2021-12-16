#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000007

using namespace std;
            ll ans[maxn] , cnt[maxn];
void mem(ll m){
            for (int i=0 ; i<m+5 ; i++)ans[i] = cnt[i]= 0;
}

int main()
{
      ll tc;
      scanf("%lld",&tc);

      for(ll _t =1 ; _t<=tc ; _t++){
            ll n,m;
            scanf("%lld %lld",&n,&m);

            mem(m);

            ll A[n+5];

            for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);
            A[0] = 0;
            A[n+1] = m;

            sort(A,A+(n+1));

            for (int i=1 ; i<=n+1 ; i++){

                  ll a = A[i]-A[i-1];
                  if (a<=1)continue;
                  ll temp[a+5] ,pre = a+3;
                  for (int i=0 ; i<a+4 ; i++)temp[i] = 0;

                  for (int j = 0 ; j<a ; j++){
                        ///5   6 7 8 9   10
                        ll jump = (a+j)/(j+1);
                        if (jump!=pre){
                              temp[jump] += j;
                              pre = jump;
                        }
                  }
                  for (int i=1 ; i<a ; i++){
                        if (temp[i]==0)temp[i] = temp[i-1];
                        ans[i]+=temp[i];
                  }
            }

            for (int i=m ; i>=1 ; i--){
                  cnt[ans[i]] = i;
            }
            if (cnt[0]==0)cnt[0] = 1;
            for (int i=1 ; i<=m ; i++){
                  if (cnt[i]==0)cnt[i] = cnt[i-1];
            }

            ll q;
            scanf("%lld",&q);
            printf("Case %lld:\n",_t);
            while(q--){
                  ll id;
                  scanf("%lld",&id);
                  printf("%lld\n",cnt[id]);
            }
      }

      return 0;
}
