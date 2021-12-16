#include<bits/stdc++.h>
#define show(x) cout << #x " : " << x << endl
#define maxn 300006
#define ll long long int

using namespace std;

ll trie[maxn][30], failure[maxn] , parent[maxn],totalNode;
ll endPoll[maxn] , cnt[maxn] , level[maxn];
void init()
{
///initialize for every case
      memset(trie,-1,sizeof trie);
      memset(failure,0,sizeof failure);
      memset(parent,0,sizeof parent);
      memset(cnt,0,sizeof cnt);
      memset(endPoll,-1,sizeof endPoll);
      totalNode = 1;
}
void buildTrie(string pattern, ll id)
{
///called for every query string
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
      endPoll[curr] = id;
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
      vector <ll> endPollsFound;
      priority_queue<pair<ll,ll> > pq;
      ll cur = 0 ;
      bool vis[totalNode+5];
      memset(vis,false,sizeof vis);
      vis[0] = true;

      for (ll i=0; i<text.size() ; i++){
            ll temp = text[i]-'a';
            while(true){
                  if (trie[cur][temp] != -1){
                  ///a new node is found in the text string
                        cur = trie[cur][temp];
                        cnt[cur]++;
                        if (vis[cur]==false){
                              pq.push({level[cur],cur});
                              vis[cur] = true;
                        }
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

ll findOccurance(string pattern)
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
                  printf("%lld\n",findOccurance(s[i]));
            }
      }

      return 0;
}
/**
1
14
hisshedher
h
i
s
e
d
r
dh
ed
er
hi
he
is
ss
edh

1
9
hisshedher
shw
dh
ed
er
hi
he
is
ss
edh

1
8
hisshedher
h
e
d
r
dh
ed
er
edh

1
3
hisshedher
h
dh
edh

**/
