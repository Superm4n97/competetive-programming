#include<bits/stdc++.h>
#define ll long long int

using namespace std;

struct node
{
      ll bit[2];
      node* next[2];
      node()
      {
            next[0] = next[1] = NULL;
      }
};
node* root;
ll n , P[40];

void build(ll x)
{
      ll dig[35] , temp = x;
      for (int i = 0 ; i<35 ; i++){
            dig[i] = temp%2;
            temp/=2;
      }

      node* ptr = root;

      for (int i=34 ; i>=0 ; i--){
            if (ptr->next[dig[i]]==NULL)ptr->next[dig[i]] = new node();
            ptr = ptr->next[dig[i]];
      }
      return;
}

ll findmax(ll x)
{
      ll dig[35] , temp = x;
      for (int i = 0 ; i<35 ; i++){
            dig[i] = temp%2;
            temp/=2;
      }

      ll ans = 0;
      node* ptr = root;
      for (int i=34 ; i>=0 ; i--){
            if (ptr->next[1-dig[i]] != NULL){
                  ans+=P[i];
                  ptr = ptr->next[1-dig[i]];
            }
            else ptr = ptr->next[dig[i]];
      }
      return ans;
}

ll findmin(ll x)
{
      ll dig[35] , temp = x;
      for (int i = 0 ; i<35 ; i++){
            dig[i] = temp%2;
            temp/=2;
      }

      ll ans = 0;
      node* ptr = root;
      for (int i=34 ; i>=0 ; i--){
            if (ptr->next[dig[i]] != NULL){
                  ptr = ptr->next[dig[i]];
            }
            else {
                  ptr = ptr->next[1-dig[i]];
                  ans += P[i];
            }
      }
      return ans;
}

void DEL(node* ptr)
{
      if (ptr->next[0]!=NULL)DEL(ptr->next[0]);
      if (ptr->next[1]!=NULL)DEL(ptr->next[1]);
      delete(ptr);
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<35 ; i++)P[i] = P[i-1]*2;

      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){

            root = new node();

            scanf("%lld",&n);
            ll A[n+5] , cxor[n+5];
            memset(cxor,0,sizeof cxor);

            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  cxor[i] = cxor[i-1]^A[i];
            }
            build(0);
            ll mx,mn;
            for (int i=1 ; i<=n ; i++){
                  if (i==1)mx = findmax(cxor[i]) , mn = findmin(cxor[i]);
                  else mx = max(mx,findmax(cxor[i])) , mn = min(mn,findmin(cxor[i]));
                  build(cxor[i]);
            }
            printf("Case %d: %lld %lld\n",_t,mx, mn);
            DEL(root);
      }


      return 0;
}
