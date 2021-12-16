#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll E[100005];

int main()
{
      ll n, u;
      cin >> n >> u;


      for (int i=1 ; i<= n; i++)cin >> E[i];

      ll l = 1 , r = 1 , pre_up = -1 , pre_down = -1;

      while(l<=n-2){
            while(r<n && E[r+1] - E[l]<=u)r++;

            if (r-l+1>=3){
                  ll x = E[r] - E[l+1] , y = E[r] - E[l];

                  if (pre_up==-1)pre_up = x, pre_down = y;
                  else if (pre_up*y<pre_down*x)pre_up = x , pre_down = y;
            }

            l++;
      }

      if (pre_up==-1)cout << -1 << endl;
      else{
            double ans = (double)pre_up / (double) pre_down * 1.0;
            printf("%.15lf\n",ans);
      }


      return 0;
}


/**

pre_up / pre_down < x/y
pre_up*y < pre_down*x

**/
