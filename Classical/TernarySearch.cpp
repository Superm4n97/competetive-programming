#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll n, pa,pr,pm , A[maxn];

ll calculation(ll h)
{
      ll up = 0 , down = 0;
      for (int i=1 ; i<=n ; i++){
            if (A[i]>=h)up+=(A[i]-h);
            else down+=(h-A[i]);
      }
      if (up>=down)return down*pm + (up-down)*pr;
      return up*pm + (down-up)*pa;
}
int main()
{
      cin >> n >> pa >> pr >> pm;
      if (pm>pa+pr)pm = pa+pr;
      ll b = 10000000010,e = -1 , ans = 1000000000000000018;
      for (int i=1 ; i<= n ; i++){
            cin >> A[i];
            b = min(A[i],b);
            e = max(A[i],e);
      }

      while(b<=e){
            ll mid1 = b+(e-b)/3 , mid2 = e - (e-b)/3;
            ll res1 = calculation(mid1) , res2 = calculation(mid2);
            ans = min(ans,min(res1,res2));
            ///jeta optimal ans er kache thakbe na seta ke shift korbo
            if (res1>res2)b = mid1+1;//searching for minimum ans
            else e = mid2-1;
      }

      cout << ans << endl;


      return 0;
}
