#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define base 139
#define mod 1000000021
#define maxn 100005

using namespace std;

ll H1[maxn],H2[maxn] , P[maxn];

ll amodb(ll a, ll b)
{
      ll temp = a/b;
      return a - temp*b;
}

void createHash(string s)
{
      H1[0] = s[0];
      for(int i=0 ; i<s.size() ; i++)H1[i] = amodb(H1[i-1]*base+s[i],mod);
}
void createReverseHash(string s)
{
      ll n = s.size();
      H2[n-1] = s[n-1];
      for (int i = n-2 ;i>=0 ; i--)H2[i] = amodb(H2[i+1]*base+s[i],mod);
}
ll query(ll l, ll r)
{
      if (l<0)return mod+3;
      else if (l==0)return H1[r];
      else {
            ll temp = amodb(H1[l-1]*P[r-l+1],mod);
            temp = amodb(H1[r]-temp+mod,mod);
            return temp;
      }
}

int main()
{
      P[0] = 1;
      for (int i=1 ;i<maxn ; i++)P[i] = amodb(P[i-1]*base,mod);

      string s;
      while(cin>>s){
            createHash(s);
            createReverseHash(s);
            ll n = s.size();
            ll ans = 1;

            for (ll i=n-2 , j=1; i>=0 ; i--, j++){
                  ll a = H2[i+1] , b = query(i-j+1,i) , c = query(i-j,i-1);
                  if (a==b)ans = max(ans,j*2);
                  if (a==c)ans = max(ans,j*2+1);
            }
            ans = n-ans;
            for (int i=ans-1 ; i>=0 ; i--)s.push_back(s[i]);
            cout << s << endl;
      }

      return 0;
}
