#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;

ll A[maxn] , B[maxn] , C[maxn] , sum_c = 0 , sum_b = 0 , n;

ll findResult()
{
      ll x = (A[1]+sum_b) , y = (A[n]+sum_c);
      ll a = x/2 , b = y/2;

      if (x%2 && x>0)a++;
      if (y%2 && y>0)b++;

      return max(a,b);
}

void indexUpdate(ll id , ll x)
{
      if (id==1 || id==n+1)return;

      ll pre_b = B[id] , pre_c = C[id];

      if (B[id]){
            B[id]+=x;
            if (B[id]<0){
                  C[id] = -B[id];
                  B[id] = 0;
            }
      }
      else {
            x*=-1;
            C[id]+=x;
            if (C[id]<0){
                  B[id] = -C[id];
                  C[id] = 0;
            }
      }
      sum_b = sum_b-pre_b+B[id];
      sum_c = sum_c-pre_c+C[id];
}

void queryProcess(ll l, ll r, ll x)
{
      if (l==r){
            indexUpdate(l,x);
            indexUpdate(r+1,-x);
            if(l==1)A[1]+=x;
            else if (l==n)A[n]+=x;
      }
      else {
            indexUpdate(l,x);
            indexUpdate(r+1,-x);
            if (l==1)A[1]+=x;
            if (r==n)A[n]+=x;
      }
}

int main()
{
      cin >> n;
      for (int i=1 ; i<=n ; i++){

            cin >> A[i];

            if (i>1){
                  if (A[i]>A[i-1]){
                        B[i] = A[i] - A[i-1];
                  }
                  else {
                        C[i] = A[i-1]-A[i];
                  }

                  sum_b+=B[i];
                  sum_c+=C[i];
            }
      }

      cout << findResult() << endl;

      ll tc;
      cin >> tc;

      while(tc--){

            ll l,r,x;
            cin >> l >> r >> x;

            queryProcess(l,r,x);
            cout << findResult() << endl;
      }

      return 0;
}
