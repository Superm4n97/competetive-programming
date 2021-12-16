#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define maxn 200005

using namespace std;

ll n,q;
ll csum[8][maxn];
string s;

void build(ll id, string sx)
{
      for (int i=0 ; i<n ; i++){
            if (s[i] != sx[i%3])csum[id][i+1] = 1;
      }
      for (int i=1 ; i<=n ; i++)csum[id][i] += csum[id][i-1];
}

ll quary(ll l, ll r)
{
      ll ret = n+100;
      for (int i=0 ; i<6 ; i++){
            ret = min(ret,csum[i][r]-csum[i][l-1]);
      }
      return ret;
}

int main()
{
      scl(n);
      scl(q);
      cin >> s;

      build(0,"abc");
      build(1,"acb");
      build(2,"bac");
      build(3,"bca");
      build(4,"cab");
      build(5,"cba");

      while(q--){
            ll l, r;
            scl(l), scl(r);
            printf("%lld\n",quary(l,r));
      }

      return 0;
}
