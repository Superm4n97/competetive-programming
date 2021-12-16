#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll sum_of_digits(ll n)
{
      ll cnt = 0;
      while(n){
            cnt+=(n%10);
            n/=10;
      }
      return cnt;
}

void split(ll n, ll &a , ll &b)
{
      ll pw = 1 , m = n/10;
      while(m){
            pw*=10;
            m/=10;
      }

      if (pw==n){
            a = 1;
            b = 9;
            a*=(pw/10);
            b*=(pw/10);
      }
      else {
            a = pw;
            b = n-pw;
      }
      return;
}

void solve(ll s, ll n)
{
      ll ones = 0;
      priority_queue<pair<ll,ll> >pq;
      pq.push({sum_of_digits(s),-s});

      while(pq.size()+ones<n){
            ll u = -pq.top().second;
            pq.pop();
            if (u==1){
                  ones++;
                  continue;
            }
            ll a, b;
            split(u,a,b);
//            cout << u << " "<< a << " " << b << endl;
            pq.push({sum_of_digits(a),-a});
            pq.push({sum_of_digits(b),-b});
      }
      while(!pq.empty()){
            cout << -pq.top().second << " ";
            pq.pop();
      }
      for (int i=0 ; i<ones ; i++)cout << "1 ";
      cout << endl;

      return;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll s, n;
            cin >> s >> n;
            solve(s,n);
      }

      return 0;
}
