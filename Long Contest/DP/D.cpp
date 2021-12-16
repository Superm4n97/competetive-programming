#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

struct node
{
      int mx_palin;
      char ch;
} dp[1005][1005];
string s,ans;
ll n , odd;

void clean(ll x)
{
      ans = "";
      for (int i=0 ; i<x+3 ; i++){
            for (int j=0 ; j<x+3 ; j++){
                  dp[i][j].mx_palin = -1;
            }
      }
}

node compareDuo(node t1, node t2)
{
      if (t1.mx_palin>t2.mx_palin)return t1;
      if (t1.mx_palin<t2.mx_palin)return t2;
      t1.ch = min(t1.ch,t2.ch);
      return t1;
}

node compare(node t1, node t2, node t3)
{
      t1 = compareDuo(t1,t2);
      t1 = compareDuo(t1,t3);
      return t1;
}

bool equals(node t1, node t2)
{
      if (t1.mx_palin!=t2.mx_palin || t1.ch!=t2.ch)return false;
      return true;
}

node rec(ll x, ll y)
{
      if (dp[x][y].mx_palin != -1)return dp[x][y];
      if (x==y){
            dp[x][y].mx_palin = 1;
            dp[x][y].ch = s[x];
            return dp[x][y];
      }
      if (x+1==y && s[x]==s[y]){
            dp[x][y].mx_palin = 2;
            dp[x][y].ch = s[x];
            return dp[x][y];
      }

      if (s[x]==s[y]){
            node t1 = rec(x+1,y),t2 = rec(x+1,y-1),t3 = rec(x,y-1);
            t2.mx_palin += 2;
            t2.ch = s[x];
            return dp[x][y] = compare(t1,t2,t3);
      }
      else {
            node t1 = rec(x+1,y) , t2 = rec(x,y-1);
            if (t1.mx_palin>t2.mx_palin)dp[x][y] = t1;
            else if (t1.mx_palin<t2.mx_palin) dp[x][y] = t2;
            else{
                  dp[x][y] = t1;
                  dp[x][y].ch = min(t1.ch,t2.ch);
            }
            return dp[x][y];
      }
}

void path(ll x, ll y)
{
      if (x==y){
            ans.push_back(s[x]);
            return;
      }
      if (x+1==y && s[x]==s[y]){
            ans.push_back(s[x]);
            ans.push_back(s[x]);
            return;
      }

      if (s[x]==s[y]){
            node t1=rec(x+1,y),t2=rec(x+1,y-1),t3=rec(x,y-1);
            t2.mx_palin += 2;
            t2.ch = s[x];
            node optimal = compare(t1,t2,t3);
            ll p,q;

            if (equals(optimal,t1))path(x+1,y);
            else if (equals(optimal,t3))path(x,y-1);
            else {
                  ans.push_back(s[x]);
                  path(x+1,y-1);
                  ans.push_back(s[y]);
            }
      }
      else {
            if (dp[x+1][y].mx_palin==dp[x][y].mx_palin && dp[x+1][y].ch==dp[x][y].ch)path(x+1,y);
            else path(x,y-1);
      }
}

int main()
{
      //while(getline(cin,s)){
      while(cin >> s){
            if (s.empty()){
                  cout << endl;
                  continue;
            }

            n = s.size();
            clean(n);

            node temp = rec(0,n-1);
            path(0,n-1);

            cout << ans << "\n";
      }

      return 0;
}
/*
d
c
e
f
b
a
a
l
ydy
zz
e
oho
ufu
glxlg
b
tut
d
dkskd
l
ll
qbq
n
c
anekdkena
ioaoi
ahcha
bpqjjqpb
wvykyvw
tt
ycqrqcy
b
ddd
ilacccali
fpfrrrfpf
vftfv
purzrup
qdq
brlnlrb
aiuuia
kffk
nrzhmmhzrn
hthvhth
xepeyyepex
jxncnxj
kk
foaedsknksdeaof
mctgeiegtcm
gcomjkkjmocg
sjjs
alhgdghla
gjg
zcqcz
epcptkebektpcpe
fzraoarzf
dtpyyptd
c
waw
bnknb
viv
jvxxpmpxxvj
b
s

*/
