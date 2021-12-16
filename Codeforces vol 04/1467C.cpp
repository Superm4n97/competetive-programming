#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 300005

using namespace std;

ll n,m,o , mx1 , mx2 , mx3 , A[maxn] , sum1 =0 , sum2 = 0,sum3 = 0 , B[maxn] , C[maxn] , ans = 0;

void fn(ll a , ll id)
{
      if (id==1){
            if (a>mx2 || a>mx3)ans+=a;
            else ans-=a;
      }
      else if (id==2){
            if (a>mx1 || a>mx3)ans+=a;
            else ans-=a;
      }
      else {
            if (a>mx2 || a>mx1)ans+=a;
            else ans-=a;
      }
}

int main()
{
      ll tc=1;
      //scl(tc);

      while(tc--){
            scl(n),scl(m),scl(o);

            for (int i=1 ; i<=n ; i++){
                  scl(A[i]);
                  sum1+=A[i];
                  if (i==1)mx1 = A[1];
                  else mx1 = min(A[i],mx1);
            }
            for (int i=1 ; i<=m ; i++){
                  scl(B[i]);
                  sum2+=B[i];
                  if (i==1)mx2 = B[1];
                  else mx2 = min(B[i],mx2);
            }
            for (int i=1 ; i<=o ; i++){
                  scl(C[i]);
                  sum3+=C[i];
                  if (i==1)mx3 = C[1];
                  else mx3 = min(C[i],mx3);
            }

            ll total = sum1+sum2+sum3;
            ans = 0;

            ans = max(ans,total-sum1*2);
            ans = max(ans,total-sum2*2);
            ans = max(ans,total-sum3*2);

            ans = max(ans,total-2*mx1-2*mx2);
            ans = max(ans,total-2*mx3-2*mx2);
            ans = max(ans,total-2*mx1-2*mx3);

            printf("%I64d\n",ans);
      }

      return 0;
}
