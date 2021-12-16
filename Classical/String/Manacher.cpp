#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll mArray[maxn] , mSize;

void Manacher(string st)
{
      string s;
      mSize = st.size()*2+1;
      for (int i=0; i<mSize ; i++){
            if (i%2)s.push_back(st[i/2]);
            else s.push_back('#');
      }

      for (ll i=0 , l=0 , r=-1 ; i<mSize ; i++){

            ll k ;
            if (i>r)k=1;
            else k = min(mArray[l+r-i],r-i+1);

            while(i+k<mSize && i-k>=0 && s[i+k]==s[i-k])k++;
            mArray[i] = k;
            if (i+k-1>r){
                  l = i-k+1;
                  r = i+k-1;
            }
      }
      /**with out # character
      for (int i=0 ; i<mSize ; i++){
            if (i%2)mArray[i]/=2;
            else mArray[i] = (mArray[i]+1)/2;
      }
      **/
}

int main()
{
      string s;
      while(cin >> s){

            ll n = s.size();
            Manacher(s);

            ll ans = mSize;
            for (int i=0 ; i<mSize ; i++){
                  if (i+mArray[i]==mSize){
                        ans = min(ans , (i-mArray[i]+1)/2);
                  }
            }
            for (int i=ans-1 ; i>=0 ; i--)s.push_back(s[i]);
            cout << s << endl;
      }

      return 0;
}
