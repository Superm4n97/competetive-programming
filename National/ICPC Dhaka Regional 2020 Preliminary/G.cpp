#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define base 163
#define mod 1000000021
#define inf 1000000021

using namespace std;

ll n , dp[maxn] , Hash[maxn] , lim = 350, P[maxn];
vector<string> heavy;
vector<ll> H;
string text;

struct node
{
      ll endmark;
      node* next[28];

      node()
      {
            endmark = 0;
            for (int i=0 ; i<27 ; i++)next[i] = NULL;
      }
};

node * root;

ll amodb(ll a, ll b)
{
      ll temp = a/b;
      return a - b*temp;
}

void insertTrie(string st)
{
      node* curr = root;

      for (int i = 0 ; i<st.size(); i++){
            ll id = st[i]-'a';

            //show(id);

            if (curr->next[id] == NULL)curr->next[id] = new node();

            curr = curr -> next[id];
      }
      curr -> endmark = 1;
}


void deleteTrie(node *curr)
{
      for (int i=0 ; i<27 ; i++){
            if (curr->next[i] != NULL)
                  deleteTrie(curr->next[i]);
      }
      delete(curr);
}

ll createHash(string s)
{
      ll ret = s[0];
      for (int i=1 ; i<s.size() ; i++){
            ret = amodb(ret*base+s[i],mod);
      }
      return ret;
}

void processHeavy()
{
      for (int i=0 ; i<heavy.size() ; i++){
            H.push_back(createHash(heavy[i]));
      }
}

void motherString()
{
      Hash[0] = text[0];
      for (int i=1 ; i<text.size() ; i++){
            Hash[i] = amodb(Hash[i-1]*base+text[i],mod);
      }
}

ll findHashText(ll L, ll R)
{
      if (L==0)return Hash[R];
      ll temp = amodb(Hash[L-1]*P[R-L+1],mod);
      temp = amodb(Hash[R]-temp+mod,mod);
      return temp;
}

ll rec(ll pos)
{
      if (dp[pos] != -1)return dp[pos];
      if (pos==text.size())return 0;
      if (pos>text.size())return inf;

      ll ret = inf;

      for (int i=0 ; i<heavy.size() ; i++){
            ll L = pos, R = pos+heavy[i].size()-1;

            if (R>text.size())continue;


            if (findHashText(L,R) == H[i]){
                  ret = min(ret,rec(R+1)+1);
            }
      }


      node* curr = root;
      for (int i=pos ; i<text.size() ; i++){
            ll id = text[i] - 'a';

            if (curr->next[id] == NULL)break;

            curr = curr->next[id];

            if (curr->endmark == 1){
                  ret = min(ret,rec(i+1)+1);
            }
      }

      return dp[pos] = ret;
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<maxn ; i++)P[i] = amodb(P[i-1]*base,mod);

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%lld",&n);


            root = new node();
            memset(dp,-1,sizeof dp);
            heavy.clear();
            H.clear();
            memset(Hash,0,sizeof Hash);

            for (int i=0 ; i<n;i++){
                  string s;
                  cin >> s;

                  if (s.size()<lim)insertTrie(s);
                  else {
                        heavy.push_back(s);
                  }
            }
            processHeavy();

            cin >> text;

            motherString();

            ll ans = rec(0);



            if (ans>=inf)printf("Case %d: impossible\n",_t);
            else printf("Case %d: %lld\n",_t,ans);

            deleteTrie(root);
      }


      return 0;
}
