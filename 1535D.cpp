#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll K ,n, st[4*maxn],sgn[4*maxn];
string s;

ll convert(char ch)
{
      if (ch=='0')return 0;
      if (ch=='1')return 1;
      return 2;
}

ll findBits(ll a)
{
      ll ret = 0;
      while(a){
            ret++;
            a/=2;
      }
      return ret-2;
}

void build(ll node)
{
      if (2*node+1>n){
            sgn[node] = convert(s[n-node]);
            if (sgn[node]<=1)st[node] = 1;
            else st[node] = 2;
            return;
      }
      build(2*node);
      build(2*node+1);

      sgn[node] = convert(s[n-node]);

      if (sgn[node]==0)st[node] = st[node*2+1];
      else if (sgn[node]==1)st[node] = st[node*2];
      else st[node] = st[node*2]+st[node*2+1];
}

void update(ll node, ll bit, ll idx, ll flag)
{
//      show(node);
//      show(bit);
//      show(idx);
//      show(flag);
      if (bit==-1){
            sgn[node] = flag;
            if (node*2+1>n){
                  if (flag<=1)st[node] = 1;
                  else st[node] = 2;
            }
            else {
                  if (flag==0)st[node] = st[node*2+1];
                  else if (flag==1)st[node] = st[node*2];
                  else st[node] = st[node*2+1]+st[node*2];
            }
            return;
      }
      if(idx&(1LL<<bit))update(node*2+1,bit-1,idx,flag);
      else update(node*2,bit-1,idx,flag);

      if (sgn[node]==0)st[node] = st[node*2+1];
      else if (sgn[node]==1)st[node] = st[node*2];
      else st[node] = st[node*2]+st[node*2+1];
}

int main()
{
      cin >> K;
      cin >> s;
      n = s.size();

      build(1);

      ll q;
      cin >> q;
      while(q--){
            ll a;
            char ch;
            cin >> a >> ch;
            a--;
            ll nd = n-a;
            update(1,findBits(nd),nd,convert(ch));
            cout << st[1] << "\n";
      }

      return 0;
}

/*
3
0110?11
1
5 1
*/
