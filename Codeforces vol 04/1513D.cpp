#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll A[maxn], P[maxn], vis[maxn] ,p, n;

void init()
{
      for (int i=0 ; i<=n+2 ;i++){
            P[i] = i;
            vis[i] = 0;
      }
}

ll findParent(ll a)
{
      if (P[a]==a)return a;
      return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);
      if (a != b)P[a] = b;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld %lld",&n,&p);
            init();

            vector<pair<ll,ll> >v;

            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  v.push_back({A[i],i});
            }

            sort(v.begin(),v.end());

            ll ans = 0;
            for (int j=0 ; j<n ; j++){
                  ll id = v[j].second , a = v[j].first;
                  if (a>p)break;
                  if (vis[id] == 1)continue;
                  vis[id] = 1;

                  for (int i=id-1 ; i>0 ; i--){
                        if(A[i]%a==0){
                              ans+=a;
                              makeParent(i,id);
                              if (vis[i]!=0)break;
                              else vis[i] = 1;
                        }
                        else break;
                  }

                  for (int i = id+1 ; i<=n ; i++){
                        if (A[i]%a==0){
                              ans+=a;
                              makeParent(i,id);
                              if (vis[i] != 0)break;
                              else vis[i] = 1;
                        }
                        else break;
                  }
            }

            set<ll> st;
            for (int i=1 ; i<=n ; i++){
                  st.insert(findParent(i));
            }

            ans+=(st.size()-1)*p;
            printf("%lld\n",ans);
      }

      return 0;
}
