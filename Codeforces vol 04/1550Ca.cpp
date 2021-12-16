#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n;
string s;
vector<ll> A , MT[4*maxn];
ll st[4*maxn];

void build(ll node, ll b, ll e)
{
      if (b == e){
            MT[node].push_back(A[b]);
            return;
      }

      ll mid = (b+e)/2;
      build(node*2,b,mid);
      build(node*2+1,mid+1,e);

      ll x = 0 , y = 0;
      for (int i=b ; i<=e ; i++){
            if(x>=MT[node*2].size()){
                  MT[node].push_back(MT[node*2+1][y]);
                  y++;
            }
            else if (y>=MT[node*2+1].size()){
                  MT[node].push_back(MT[node*2][x]);
                  x++;
            }
            else if (MT[node*2][x]<MT[node*2+1][y]){
                  MT[node].push_back(MT[node*2][x]);
                  x++;
            }
            else {
                  MT[node].push_back(MT[node*2+1][y]);
                  y++;
            }
      }
      return;
}

ll quary(ll node, ll b, ll e, ll x, ll y, ll val)
{
      if (b>y || e<x)return 0;
      if (b>=x && e<=y){
            ll ret = MT[node].size() , beg = 0 , ed = MT[node].size()-1;
            while(beg<=ed){
                  ll mid = (beg+ed)/2;
                  if (MT[node][mid]>=val){
                        ret = min(ret,mid);
                        ed = mid-1;
                  }
                  else beg = mid+1;
            }
            return (MT[node].size()-ret);
      }
      ll mid = (b+e)/2;
      ll t1 = quary(node*2,b,mid,x,y,val) , t2 = quary(node*2+1,mid+1,e,x,y,val);
      return t1+t2;
}

int main()
{
      cin >> n;
      cin >> s;

      queue<ll> q[30];
      for (int i=0 ; i<n ; i++){
            ll temp = s[i]-'a';
            q[temp].push(i+1);
      }
      reverse(s.begin(),s.end());

      for (int i=0 ; i<n ; i++){
            ll temp = s[i] - 'a';
            A.push_back(q[temp].front());
            q[temp].pop();
      }

      build(1,0,n-1);

      ll ans = 0;

      for (int i=1 ; i<n ; i++){
            ans+=quary(1,0,n-1,0,i-1,A[i]);
      }
      cout << ans << endl;




      return 0;
}
