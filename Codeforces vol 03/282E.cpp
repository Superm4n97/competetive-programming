#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll n , A[maxn] , L[maxn] , R[maxn], P[65] , ans = 0;

struct node
{
      ll node_min;
      node* next[2];

      node(ll id){
            next[0] = next[1] = NULL;
            node_min = id;
      }
};
node* root = new node(0LL);

void build(ll x, ll id)
{
      ll ar[65];
      memset(ar,0,sizeof ar);
      for (int i=0 ; i<63 ; i++){
            ar[i] = x%2;
            x/=2;
      }

      node* ptr = root;
      for (ll i = 62 ; i>=0 ; i--){
            ll bit = ar[i];
            if(ptr->next[bit]==NULL)ptr->next[bit] = new node(id);
            ptr = ptr->next[bit];
      }
      return;
}

ll findXor(ll x, ll id)
{
      ll temp = x;
      ll ar[65];
      memset(ar,0,sizeof ar);
      for (int i=0 ; i<63 ; i++){
            ar[i] = x%2;
            x/=2;
      }

      ll ret = 0;

      node* ptr = root;
      for (ll i = 62 ; i>=0 ; i--){
            ll bit = ar[i];
            if (ptr->next[1-bit]!=NULL){
                  if (ptr->next[1-bit]->node_min > id){
                        ret+=P[i];
                        ptr = ptr->next[1-bit];
                        continue;
                  }
            }
            if (ptr->next[bit] != NULL){
                  if (ptr->next[bit]->node_min > id){
                        ptr = ptr->next[bit];
                        continue;
                  }
            }

            break;
      }

      return ret;
}

int main()
{
      P[0] = 1;
      for (ll i = 1 ; i<63 ; i++)P[i] = P[i-1]*2;

      scanf("%I64d",&n);
      for (ll i=1 ; i<=n ; i++) scanf("%I64d",&A[i]);

      for (ll i=1 ; i<=n ; i++)L[i] = L[i-1]^A[i];
      for (ll i=n ; i>=1 ; i--)R[i] = R[i+1]^A[i];

      for (ll i=n+1 ; i>=1 ; i--)build(R[i],i);
      for (ll i=0 ; i<=n ; i++)ans = max(ans,findXor(L[i],i));

      printf("%I64d\n",ans);

      return 0;
}
