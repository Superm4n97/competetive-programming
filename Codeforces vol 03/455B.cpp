#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll tree[maxn][27], endMark[maxn],win[maxn] , lose[maxn] , totalNode = 1 , n , k;

void clean()
{
      memset(tree,-1,sizeof tree);
      memset(endMark,0,sizeof endMark);
      memset(win,-1,sizeof win);
      memset(lose,-1,sizeof lose);
}

void insertTrie(string s)
{
      ll cur = 0;
      for (int i=0 ; i<s.size() ; i++){
            ll temp = s[i] - 'a';
            if (tree[cur][temp]==-1){
                  tree[cur][temp] = totalNode;
                  totalNode++;
            }
            cur = tree[cur][temp];
      }
      endMark[cur] = 1;
}

ll recWIN(ll node)
{
      if (win[node] != -1)return win[node];
      ll ret = 0;

      for (int i=0 ; i<26 ; i++){
            if (tree[node][i] != -1){
                  if (recWIN(tree[node][i])==0)ret = 1;
            }
      }
      return win[node] = ret;
}

ll recLOSE(ll node)
{
      if (lose[node] != -1)return lose[node];

      ll ret = 0 , cnt = 0;
      for (int i=0 ; i<26 ; i++){
            if (tree[node][i] != -1){
                  if (recLOSE(tree[node][i])==0)ret = 1;
                  cnt++;
            }
      }
      if (cnt == 0)ret = 1;
//      show(node);
//      show(ret);
      return lose[node] = ret;
}

int main()
{
      clean();
      scanf("%I64d %I64d",&n,&k);
      for (int i=0 ; i<n ; i++){
            string s;
            cin >> s;
            insertTrie(s);
      }

      ll w = recWIN(0) , l = recLOSE(0);

//      show(w);
//      show(l);

      if (w==1 && l==0){
            if (k&1)cout << "First\n";
            else cout << "Second\n";
      }
      else if (w==0 && l==1)cout << "Second\n";
      else if (w==1 && l==1)cout << "First\n";
      else cout << "Second\n";


      return 0;
}
/*
3 3
abasdfabab
abaaasdfdsf
asdfaba

4 2
aaaa
bbbb
ccccc
dumbavumba

2 1
ab
acd
*/
