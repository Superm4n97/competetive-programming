#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll mArray[2*maxn] , msize;

void Manacher(string st)
{
      string s;
      msize = st.size()*2+1;

      for (int i=0 ; i<msize ;i++){
            if (i%2)s.push_back(st[i/2]);
            else s.push_back('#');
      }

      for (ll i=0 , l = 0 , r = -1 ; i<msize ; i++){
            ll k;
            if (i>r)k = 1;
            else k = min(mArray[l+r-i],r-i+1);

            while(i+k<msize && i-k>=0 && s[i+k]==s[i-k])k++;
            mArray[i] = k;
            if (i+k-1>r){
                  r = i+k-1;
                  l = i-k+1;
            }
      }
      return;
}

int main()
{
      ll n;
      cin >> n;
      string s;
      cin >> s;

      Manacher(s);
      ll ans = 0;
      for (int i=0;  i<msize ; i++){
            ll temp = mArray[i]/2;
            temp*=2;
            if (i%2)temp--;
            ans = max(ans,temp);
      }
      cout << ans << endl;


      return 0;
}
