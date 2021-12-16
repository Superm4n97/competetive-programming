#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100006

using namespace std;

string s,t;
int Z[3][maxn];

void Z_function(string text, int id)
{
      int L = 0 , R = 0 , N = text.size();
      Z[id][0] = 0;

      for (int i=1 ; i<N ; i++){
            if (i>R){
                  L = R = i;
                  while(R<N && text[R]==text[R-L])R++;
                  Z[id][i] = R-L;
                  R--;
            }
            else {
                  if (i+Z[id][i-L]-1<R)Z[id][i] = Z[id][i-L];
                  else {
                        L = i;
                        while(R<N && text[R]==text[R-L])R++;
                        Z[id][i] = R-L;
                        R--;
                  }
            }
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            cin >> s >> t;
            ll n = s.size()+t.size() , pat = t.size();

            string st = t+s;
            st[pat-1] = '$';
            Z_function(st,0);

            string st2 = s+t;
            reverse(st2.begin(),st2.end());
            st2[pat-1] = '$';
            Z_function(st2,1);

            ll cnt[2][n+5];
            memset(cnt,0,sizeof cnt);

            for (int i=0; i<n ; i++){
                  cnt[0][i] += 1;
                  cnt[1][i] += 1;

                  cnt[0][i+Z[0][i]] += -1;
                  cnt[1][i+Z[1][i]] += -1;
            }
            for (int i=1 ; i<n ; i++){
                  cnt[0][i]+=cnt[0][i-1];
                  cnt[1][i]+=cnt[1][i-1];
            }

            ll ans = 0;
            for (int i=t.size(),j=n-2 ; i<n-1 ; i++,j--){
                  ans+=(cnt[0][i]*cnt[1][j]);
            }
            printf("Case %d: %lld\n",_t,ans);

      }

      return 0;
}
