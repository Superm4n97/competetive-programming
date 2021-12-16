#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll A[maxn] , n,k;
string s;

int main()
{
      cin >> n >> k;

      for (int i=0 ; i<n; i++)cin >> A[i];
      cin >> s;

      priority_queue < ll > pq;
      pq.push(A[0]);

      ll ans = 0;

      for (int i=1 ; i<n ; i++){
            if (s[i]!=s[i-1]){
                  ll cnt = 0;
                  while(cnt<k && !pq.empty()){

                        ans+=pq.top();
                        pq.pop();
                        cnt++;
                  }

                  while(!pq.empty())pq.pop();

                  pq.push(A[i]);
            }
            else {
                  pq.push(A[i]);
            }
      }

      ll cnt = 0;
      while(cnt<k && !pq.empty()){

            ans+=pq.top();
            pq.pop();
            cnt++;
      }

      cout << ans << endl;



      return 0;
}
