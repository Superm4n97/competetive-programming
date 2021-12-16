#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll P[35];

int main()
{
      P[0] = 1;
      for (int i=1 ; i<35 ; i++)P[i] = P[i-1] * 2;

      ll tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+4];
            for (int i=1 ; i<=n ; i++)cin >>A[i];

            ll ans = 0;

            for (ll j=33 ; j>=0 ; j--){

                  ll a = 0 , rest = 0 ,  b = 0 , total = 0;
                  for (ll i = 1 ; i<=n ; i++){

                        if (P[j]&A[i])total++;
                        else rest++;
                  }

                  a = b = total/2;
                  if (total%2)a++;

                  a%=2;
                  b%=2;
                  rest%=2;

                  if (a==b)continue;
                  if (a || (!a && b && rest)){
                        ans = 1;
                        break;
                  }
                  else {
                        ans = -1;
                        break;
                  }
            }

            if (ans==0)cout << "DRAW\n";
            else if (ans==-1)cout << "LOSE\n";
            else cout << "WIN\n";
      }

      return 0;
}
