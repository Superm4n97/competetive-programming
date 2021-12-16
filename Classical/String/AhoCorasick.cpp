#include<bits/stdc++.h>
#define show(x) cout << #x " : " << x << endl
#define maxn 300006
#define ll long long int

using namespace std;

/**for every pattern buildTrie() is called, after trie[]
is build buildFailure() is called once, then matching()
is called with TEXT string, it finds all the occurrence
of the patterns and saves it in cnt[] array. Last of all
we called findOccurrence() with a single PATTERN and it
returns the occurrence of PATTERN in TEXT string in O(N)**/
ll trie[maxn][30], failure[maxn] , parent[maxn],totalNode;
ll endPoint [maxn] , cnt[maxn] , level[maxn];
void init()
{
///initialize for every case
      memset(trie,-1,sizeof trie);
      memset(failure,0,sizeof failure);
      memset(parent,0,sizeof parent);
      memset(cnt,0,sizeof cnt);
      memset(endPoint ,-1,sizeof endPoint );
      totalNode = 1;
}
void buildTrie(string pattern, ll id)
{
/*called for every query string, id is pattern id,
which is saved at the end of the pattern*/
      ll curr = 0;
      level[0] = 0;
      for (ll i=0 ; i<pattern.size() ; i++){
            ll eg = pattern[i] - 'a';
            if (trie[curr][eg]==-1){
                  trie[curr][eg] = totalNode;
                  parent[totalNode] = curr;
                  level[totalNode] = level[curr]+1;
                  totalNode++;
            }
            curr = trie[curr][eg];
      }
      endPoint [curr] = id;
}
void buildFailure()
{
///called once for every test case
      queue<ll> q;

      failure[0] = 0;
      for (ll i=0 ; i<27 ; i++){
            if (trie[0][i] != -1){
                  q.push(trie[0][i]);
                  failure[trie[0][i]] = 0;
            }
      }

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (ll i=0 ; i<27 ; i++){
                  ll v = trie[u][i];
                  if (v != -1){
                        ll pf = failure[u];
                        while(true){
                              if(trie[pf][i] != -1){
                                    failure[v] = trie[pf][i];
                                    break;
                              }
                              if (pf==0){
                                    failure[v] = 0;
                                    break;
                              }
                              pf = failure[pf];
                        }
                        q.push(v);
                  }
            }
      }
}
void matching(string text)
{
      vector <ll> endPoint sFound;
      priority_queue<pair<ll,ll> > pq;
      ll cur = 0 ;
      bool vis[totalNode+5];
      memset(vis,false,sizeof vis);
      vis[0] = true;

      for (ll i=0; i<text.size() ; i++){
            ll temp = text[i]-'a';
            while(true){
                  if (trie[cur][temp] != -1){
                  //a new node is found in the text string
                        cur = trie[cur][temp];
                        cnt[cur]++;
                        if (vis[cur]==false){
                              pq.push({level[cur],cur});
                              vis[cur] = true;
                        }
                        /*a hole pattern is found when
                        endPoint[cur] != -1*/
                        break;
                  }
                  if (cur==0)break;

                  cur = failure[cur];
            }
      }

      while(!pq.empty()){
            ll u = pq.top().second;
            pq.pop();

            cnt[failure[u]]+=cnt[u];

            if (vis[failure[u]]==false){
                  pq.push({level[failure[u]],failure[u]});
                  vis[failure[u]] = true;
            }
      }
}

ll findOccurrence(string pattern)
{
      ll cur = 0;
      for (ll i=0 ; i<pattern.size() ; i++){
            ll temp = pattern[i] - 'a';
            cur = trie[cur][temp];
            if (cur==-1)return 0;
      }
      return cnt[cur];
}

int main()
{
      ll tc;
      scanf("%lld",&tc);

      for (ll _t = 1 ; _t<=tc ; _t++){
            init();
            ll n;
            cin >> n;

            string T,s[n+3];
            cin >> T;

            for (ll i=1 ; i<=n ; i++){
                  cin >> s[i];
                  buildTrie(s[i],i);
            }
            buildFailure();
            matching(T);

            printf("Case %lld:\n",_t);
            for (ll i=1 ; i<=n ; i++){
                  printf("%lld\n",findOccurrence(s[i]));
            }
      }

      return 0;
}
