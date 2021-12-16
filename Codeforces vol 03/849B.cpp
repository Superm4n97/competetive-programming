#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

map < pair < ll,ll > , ll > mp;
ll A[1005] , n , P[1005];

ll findParent(ll a)
{
      if (P[a]==a)return a;
      return P[a] =  findParent(P[a]);
}

void makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);

      if (a!=b)P[a] = b;
}

int main()
{

      //show(__gcd(8,-4));

      cin >> n ;
      for (int i=1;  i<=n ; i++)cin >> A[i];

      for (int i=0 ; i<n+3 ; i++)P[i]=i;

      ll cnt = 0;
      pair<ll,ll> slop;

      for (int i=1 ; i<=n ;i++){
            for (int j = i+1 ; j<=n ; j++){

                  ll x = j-i , y = A[j] - A[i];
                  ll g = __gcd(x,y);

                  x/=g , y/=g;
                  if (x<0)x*=-1 , y*=-1;

                  mp[{x,y}]++;

                  if (mp[{x,y}]>cnt){
                        cnt = mp[{x,y}];
                        slop = {x,y};
                  }
            }
      }

      if (cnt == n*(n-1)/2){
            cout << "No" << endl;
            return 0;
      }

      if (cnt==(n-1)*(n-2) / 2){
            cout << "Yes" << endl;
            return 0;
      }

      for (int i=1 ; i<=n ; i++){
            for (int j=i+1 ; j<=n ; j++){

                  ll x = j-i , y = A[j] - A[i];
                  ll g = __gcd(x,y);

                  x/=g , y/=g;
                  if (x<0)x*=-1 , y*=-1;

                  if (make_pair(x,y)==slop)makeParent(i,j);
            }
      }

      set < ll > st;

      for (int i=1 ; i<=n ; i++)st.insert(findParent(i));

      if (st.size()==2)cout << "Yes" << endl;
      else cout << "No" << endl;


      return 0;
}
/**

1 7   2 5


**/
