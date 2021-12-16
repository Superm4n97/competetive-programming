#include<bits/stdc++.h>
#define ll long long int
#define maxn 400005

using namespace std;

ll S[4*maxn];
ll A[maxn] , n;

void build(ll node, ll b, ll e)
{
      if (b==e){
            {/**Initial Value assign**/
                  S[node] = A[b];
            }
            return;
      }

      ll mid = (b+e)/2;
      build(node*2 , b, mid);
      build(node*2+1 , mid+1, e);

      { /**Merging two childes**/
            S[node] = max(S[node*2] , S[node*2+1]);
      }

      return;
}

void update(ll node, ll b, ll e, ll index , ll value)
{
      if(b>index || e<index)return;

      if (b==e){
            {/**Update position**/
                  S[node] = value;
            }
            return;
      }

      ll mid = (b+e)/2;
      update(node*2,b,mid,index,value);
      update(node*2+1,mid+1,e,index,value);

      { /**Merging two childes**/
            S[node] = max(S[node*2],S[node*2+1]);
      }
      return;
}

ll query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x){
            /**Base Value of extra segments**/
            return -1;
      }

      if(b>=x && e<=y){
            return S[node];
      }

      ll mid = (b+e)/2;
      ll t1 = query(node*2,b,mid ,x,y);
      ll t2 = query(node*2+1,mid+1,e,x,y);

      {/**main calculation**/

            return max(t1,t2);
      }
}

int main()
{
      cin >> n;
      for (int i = 1; i<=n ; i++)cin >> A[i];

      build(1,1,n);

      while(true){

            ll type;
            cin >> type;

            if (type == 1){
                  ll x,y;
                  cin >> x >> y;

                  cout << query(1,1,n,x,y) << endl;
            }
            else {
                  ll index , val;
                  cin >> index >> val;

                  update(1,1,n,index,val);
            }
      }

      return 0;
}
