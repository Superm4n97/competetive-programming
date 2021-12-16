#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll P[35];

ll rec(vector < ll > v , ll pos)
{
      if (pos<=-1)return 0;
      vector < ll > off, on;
      ll n = v.size();

      for (int i=0 ; i<n;i++){
            if (v[i]&P[pos])on.push_back(v[i]);
            else off.push_back(v[i]);
      }

      if (on.empty() || off.empty()){
            if (on.empty())return rec(off,pos-1);
            else return rec(on,pos-1);
      }
      else {
            ll t1 = rec(on,pos-1) , t2 = rec(off,pos-1);

            return min(P[pos]+t1 , P[pos]+t2);
      }
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<35 ; i++)P[i] = P[i-1] * 2;

      ll n;
      cin >> n;
      vector < ll > v;

      for (int i=0 ; i<n;i++){
            ll a;
            cin >> a;

            v.push_back(a);
      }

      cout << rec(v,31) << endl;



      return 0;
}
