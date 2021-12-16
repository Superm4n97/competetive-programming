#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int n;
      cin >> n;

      int b = 1 , e = n , ans = 0;
      while(b<=e){
            int l = -1, r = -1 , mid = (b+e)/2;

            cout << "? " << mid << endl;
            fflush(stdout);

            int a;
            cin >> a;

            if (mid==1)l = 1;
            else {
                  cout << "? " << mid-1 << endl;
                  fflush(stdout);
                  ll temp ;
                  cin >> temp;
                  if (temp>a)l = 1;
            }
            if (mid==n)r = 1;
            else {
                  cout << "? " << mid+1 << endl;
                  fflush(stdout);
                  ll temp ;
                  cin >> temp;
                  if (temp>a)r = 1;
            }

            if (l==1 && r==1){
                  ans = mid;
                  break;
            }

            if (l==1 && r==-1)b = mid+1;
            else e = mid-1;
      }

      cout << "! " << ans << endl;

      return 0;
}
