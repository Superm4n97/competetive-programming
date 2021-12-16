#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,k;
      cin >> n >> k;

      if (k>n){
            cout << "NO" << endl;
            return 0;
      }

      ll tut = n;
      priority_queue < ll > pq;

      for (ll i = 30 ; i>=0 ; i--){
            ll temp = (1<<i);

            if (temp<=tut){
                  pq.push(temp);
                  tut-=temp;
            }
      }

      if (k<pq.size()){
            cout << "NO" << endl;
            return 0;
      }

      while(true){

            if (pq.size()==k)break;

            ll temp = pq.top();
            pq.pop();

            pq.push(temp/2);
            pq.push(temp/2);
      }
      cout << "YES" << endl;
      while(!pq.empty()){
            cout << pq.top() << " ";
            pq.pop();
      }
      cout << endl;


      return 0;
}
