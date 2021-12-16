#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "  << x << endl
#define maxn 200005

using namespace std;

ll P[maxn] , mx[maxn] , n,m;

ll findParent(ll a)
{
      if (P[a]==a)return a;
      return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);

      if (a!=b){

            if (a>b)swap(a,b);
            P[b] = a;
            mx[a] = max(mx[a],mx[b]);
      }

      return;
}

int main()
{
      for (int i=0 ; i<maxn ; i++)P[i] = mx[i] = i;

      cin >> n >> m;

      for (int i=1 ; i<=m ; i++){

            ll a,b;
            cin >> a >> b;
            makeParent(a,b);
      }

      ll parent = 1,MX = mx[1] , curr = 1 , ans = 0;

      while(curr<=mx[parent]){

            if (curr>n)break;

            if (curr==mx[parent]){

                  curr = mx[parent]+1;
                  parent = mx[parent]+1;
                  MX = mx[parent];
            }
            else {

                  ll a = findParent(curr);
                  if (a!=parent){

                       ans++;
                       makeParent(a,parent);
                       MX = mx[parent];
                  }
                  curr++;
            }
      }

      cout << ans << endl;

      return 0;
}
