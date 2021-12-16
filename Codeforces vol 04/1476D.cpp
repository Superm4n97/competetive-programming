#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 300005

using namespace std;

ll n,dpL[maxn][3],dpR[maxn][3];
string s;

void clean()
{
      for (int i=0 ; i<n+5 ; i++){
            dpL[i][0] = dpL[i][1] = dpL[i][2] = dpR[i][0] = dpR[i][1]=dpR[i][2] = -1;
      }
}

ll recR(ll pos, ll state)
{
      if (dpR[pos][state] != -1)return dpR[pos][state];
      if (pos==n) return dpR[pos][state] = 1;

      if (state==0 && s[pos]=='R') return dpR[pos][state] = recR(pos+1,1-state)+1;
      if (state==1 && s[pos]=='L') return dpR[pos][state] = recR(pos+1,1-state)+1;
      return dpR[pos][state] = 1;
}

ll recL(ll pos, ll state)
{
//      show("L");
//      show(pos);
      if (dpL[pos][state] != -1)return dpL[pos][state];
      if (pos==0)return dpL[pos][state] = 1;


      if ((state==0 && s[pos-1]=='L') || (state==1 && s[pos-1]=='R'))
            return dpL[pos][state] = recL(pos-1,1-state)+1;
      return dpL[pos][state] = 1;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n);
            cin >> s;
            clean();
            for (int i=0 ; i<=n ; i++){
//                  show(recL(i,0));
//                  show(recR(i,0));
                  printf("%I64d ",recL(i,0)+recR(i,0)-1);
            }
            printf("\n");
      }


      return 0;
}

