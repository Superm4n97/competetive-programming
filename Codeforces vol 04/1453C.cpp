#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll L[15][5] , R[15][5] , U[15][5] , D[15][5] , n ,ans[15];

void Initialize(ll num, ll x, ll y)
{
      if (x<U[num][0])U[num][0] = x , U[num][1] = y;
      if (x>D[num][0])D[num][0] = x , D[num][1] = y;
      if (y<L[num][1])L[num][0] = x , L[num][1] = y;
      if (y>R[num][1])R[num][0] = x , R[num][1] = y;
      return;
}

ll calX(ll num, ll x, ll y)
{
      return max(y-1,n-y)*max(x-U[num][0],D[num][0]-x);
}

ll calY(ll num, ll x, ll y)
{
      return max(x-1,n-x)*max(y-L[num][1],R[num][1]-y);
}

void mem()
{
      memset(L,-1,sizeof L);
      memset(R,-1,sizeof R);
      memset(U,-1,sizeof U);
      memset(D,-1,sizeof D);
      memset(ans,0,sizeof ans);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%I64d",&n);
            mem();
            string s[n+2];
            for (int i=0 ; i<n ; i++){
                  cin >> s[i];
                  for (int j=0 ; j<n ; j++){
                        ll num = s[i][j]-'0';
                        if (L[num][0]==-1){
                              L[num][0] = R[num][0] = U[num][0] = D[num][0] = i+1;
                              L[num][1] = R[num][1] = U[num][1] = D[num][1] = j+1;
                        }
                        else {
                              Initialize(num,i+1,j+1);
                        }
                  }
            }

            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<n ; j++){
                        ll num = s[i][j]-'0';
                        ans[num] = max(ans[num] , max(calX(num,i+1,j+1),calY(num,i+1,j+1)));
                  }
            }
            for (int i=0 ; i<10 ; i++)cout << ans[i] << " ";
            cout << "\n";
      }

      return 0;
}
