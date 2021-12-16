#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000021
#define base 137
#define maxn 1200005

using namespace std;

char s[maxn], pat[maxn];
ll P[maxn], stringHash[maxn] , patternHash[maxn] , k, sizeS, sizePat;

ll amodb(ll a)
{
      return a - a/mod*mod;
}

ll findHashString(ll x, ll y)
{
      if (x==0)return stringHash[y];
      return amodb(stringHash[y] - amodb(stringHash[x-1]*P[y-x+1]) + mod);
}

ll findHashPattern(ll x, ll y)
{
      if (x==0)return patternHash[y];
      return amodb(patternHash[y] - amodb(patternHash[x-1]*P[y-x+1]) + mod);
}

ll solve(ll x, ll y)
{
      ll id = 0 ,cnt = 0;

      while(id<sizePat){
            if (s[x+id] != pat[id]){
                  id++;
                  cnt++;
                  if (cnt>k)return 0;
            }
            else {
                  ll b = id , e =  sizePat-1 , res = id;
                  while(b<=e){
                        ll mid = (b+e)/2;
                        if (findHashPattern(id,mid)==findHashString(x+id,x+mid)){
                              res = max(res,mid);
                              b = mid+1;
                        }
                        else e = mid-1;
                  }
                  id = res+1;
            }
      }
      return 1;
}

int main()
{
      P[0] = 1;
      for (ll i=1 ; i<maxn ; i++)P[i] = amodb(P[i-1]*base);
      ll tc;
      scanf("%lld",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%s",s);
            scanf("%s",pat);
            scanf("%lld",&k);

            sizeS = strlen(s);
            sizePat = strlen(pat);

            ll ans = 0;

            stringHash[0] = s[0];
            for (int i=1 ; i<sizeS ; i++)stringHash[i] = amodb((stringHash[i-1]*base+s[i]));

            patternHash[0] = pat[0];
            for (int i=1; i<sizePat ; i++)patternHash[i] = amodb(patternHash[i-1]*base+pat[i]);

            for (int i=0,j = sizePat-1 ; j<sizeS ; i++,j++){
                  ans+=solve(i,j);
            }
            printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}

