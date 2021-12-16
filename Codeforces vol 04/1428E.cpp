#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n, k , A[maxn] , cnt = 0 , ans = 0;
priority_queue < pair <ll,pair<ll,ll> > > pq;
/**
5 2
temp = 2 3
**/
ll findProfit(ll a, ll part)
{
      ll temp = a/part , high = a%part;
      ll low = part - high;

      ll x = temp*temp*low , y = (temp+1)*(temp+1)*high;
      return x+y;
}

int main()
{
      cin >> n >> k;

      cnt = n;
      for (int i=0 ;i<n ; i++){

            ll a;
            cin >> a;

            if (a==1){
                  ans+=1;
            }
            else {
                  ll x = findProfit(a,1) - findProfit(a,2);
                  pq.push({x,{1,a}});
            }
      }

      while(cnt<k){

            ll profit = pq.top().first , part = pq.top().second.first , a = pq.top().second.second;
            pq.pop();

            if (part+1==a){
                  ans += a;
            }
            else {
                  ll new_profit = findProfit(a,part+1) - findProfit(a,part+2);
                  pq.push({new_profit,{part+1,a}});
            }

            cnt++;
      }

      while(!pq.empty()){

            ll profit = pq.top().first , part = pq.top().second.first , a = pq.top().second.second;
            pq.pop();
            ans+=findProfit(a,part);
      }

      cout << ans << "\n";

      return 0;
}
