#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005

using namespace std;

ll n, A[maxn];

void simulate(ll type, ll i, ll j)
{
      if (type==1)A[i] = A[i]+A[j];
      else A[j] = A[j]-A[i];
      return;
}

void large(ll x, ll y)
{
      cout << "2 " << x << " " << y << endl;
      simulate(2,x,y);
      cout << "1 " << x << " " << y << endl;
      simulate(1,x,y);
      cout << "2 " << x << " " << y << endl;
      simulate(2,x,y);
      cout << "1 " << x << " " << y << endl;
      simulate(1,x,y);
      cout << "2 " << x << " " << y << endl;
      simulate(2,x,y);
      cout << "1 " << x << " " << y << endl;
      simulate(1,x,y);
      /*
      9 1
      9 -8
      1 -8
      1 -9
      -8 -9
      -8 -1
      -9 -1

      4 3
      4 -1 2
      3 -1 1
      3 -4 2
      -1 -4 1
      -1 -3 2
      -4 -3 1

      */
}
void small(ll x, ll y)
{
      cout << "1 " << x << " " << y << endl;
      simulate(1,x,y);      cout << "2 " << x << " " << y << endl;
      simulate(2,x,y);
      cout << "1 " << x << " " << y << endl;
      simulate(1,x,y);
      cout << "2 " << x << " " << y << endl;
      simulate(2,x,y);      cout << "1 " << x << " " << y << endl;
      simulate(1,x,y);
      cout << "2 " << x << " " << y << endl;
      simulate(2,x,y);
      /*
      1 2
      3 2 1
      3 -1 2
      2 -1 1
      2 -3 2
      -1 -3 1

      */
}

void Equal(ll x, ll y)
{
      cout << "2 " << x << " " << y << endl;
      simulate(2,x,y);
      cout << "2 " << x << " " << y << endl;
      simulate(2,x,y);
      cout << "1 " << x << " " << y << endl;
      simulate(1,x,y);
      cout << "1 " << x << " " << y << endl;
      simulate(1,x,y);
      /*
      3 3
      3 0 2
      3 -3 2
      0 -3 1
      -3 -3 1
      */
}


int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            for (int i=1 ; i<=n ; i++)cin >> A[i];

            ll ans = 0;

            for (int i=1 ; i<n ; i+=2){
                  if (A[i]>A[i+1])ans+=6;
                  else if (A[i]<A[i+1])ans+=6;
                  else ans+=4;
            }

            cout << ans << endl;
            for (int i=1 ; i<n ; i+=2){
                  if (A[i]>A[i+1])large(i,i+1);
                  else if (A[i]<A[i+1])small(i,i+1);
                  else Equal(i,i+1);
            }

//            for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
//            cout << endl;
      }
}
