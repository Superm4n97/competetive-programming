#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define inf 100000000000000017

using namespace std;

struct stc
{
      ll value , id , lazy;
};
ll n , A[maxn] , ans[maxn] , clck = 1;
stc S[4*maxn];

stc combine(stc a, stc b)
{
      if (a.value<b.value)return a;
      if (a.value>=b.value)return b;
}

void relax(ll node)
{
      S[node].value -= S[node].lazy;

      S[node*2].lazy += S[node].lazy;
      S[node*2+1].lazy += S[node].lazy;

      S[node].lazy = 0;
}

void build(ll node, ll b, ll e)
{
      if (b==e){
            S[node].value = A[b];
            S[node].id = b;
            S[node].lazy = 0;

            return;
      }

      ll mid = (b+e)/2;

      build(node*2,b,mid);
      build(node*2+1,mid+1,e);

      S[node] = combine(S[node*2] , S[node*2+1]);
      S[node].lazy = 0;

      return;
}

void pointUpdate(ll node, ll b, ll e, ll index)
{

      if (b==e){
            S[node].value-=S[node].lazy;
            S[node].lazy = 0;
      }
      else relax(node);

      if (b>index || e<index)return;

      if (b==e && b==index){
            S[node].value = inf;
            S[node].lazy = 0;

            return;
      }

      ll mid = (b+e)/2;

      pointUpdate(node*2,b,mid,index);
      pointUpdate(node*2+1,mid+1,e,index);

      S[node] = combine(S[node*2],S[node*2+1]);
      S[node].lazy = 0;

      return;
}

void rangeUpdate(ll node, ll b, ll e, ll x, ll y, ll sub)
{

      if (b==e){
            S[node].value -= S[node].lazy;
            S[node].lazy = 0;
      }
      else relax(node);

      if (e<x || b>y)return;

      if (b>=x && e<=y){

            S[node].lazy+=sub;
            if (b==e){
                  S[node].value-=S[node].lazy;
                  S[node].lazy = 0;
            }
            else relax(node);

            return;
      }

      ll mid = (b+e)/2;

      rangeUpdate(node*2,b,mid,x,y,sub);
      rangeUpdate(node*2+1,mid+1,e,x,y,sub);

      S[node] = combine(S[node*2],S[node*2+1]);

      return;
}

int main()
{
      cin >> n;
      for (int i=1 ; i<=n ; i++)cin >> A[i];

      build(1,1,n);

      while(clck<=n){

            ll index = S[1].id;
            ans[index] = clck;

            pointUpdate(1,1,n,index);

            if (index<n)rangeUpdate(1,1,n,index+1,n ,clck);


            /*
            show(clck);
            show(index);

            show(S[3].value);
            show(S[3].lazy);
            show(S[3].id);
            cout << endl;
            show(S[6].value);
            show(S[6].lazy);
            show(S[6].id);
            cout << endl;
            show(S[7].value);
            show(S[7].lazy);
            show(S[7].id);
            cout << endl;
            */

            clck++;
      }

      for (ll i = 1 ; i<=n ; i++)cout << ans[i] << " ";
      cout << endl;



      return 0;
}
