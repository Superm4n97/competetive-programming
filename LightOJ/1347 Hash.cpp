#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long int
#define base 163
#define mod 1000000021
#define maxn 5005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m,k, H1[maxn] , H2[maxn] , H3[maxn] , P[maxn];

ll amodb(ll a, ll b)
{
      ll temp = a/b;
      return a - b*temp;
}


void createHash(string s1, string s2, string s3)
{
      H1[0] = s1[0];
      H2[0] = s2[0];
      H3[0] = s3[0];
      for (int i=1 ; i<s1.size() ; i++)H1[i] = amodb(H1[i-1]*base+s1[i],mod);
      for (int i=1 ; i<s2.size() ; i++)H2[i] = amodb(H2[i-1]*base+s2[i],mod);
      for (int i=1 ; i<s3.size() ; i++)H3[i] = amodb(H3[i-1]*base+s3[i],mod);
      return;
}

bool check(ll len)
{
      unordered_map<ll,ll> mp;
      for (int i = len-1 ; i<n ; i++){
            ll hs = H1[i];
            if (i>=len){
                  ll temp = amodb(H1[i-len]*P[len],mod);
                  hs-=temp;
                  if (hs<0)hs+=mod;
            }
            mp[hs] = 1;
      }
      for (int i=len-1 ; i<m; i++){
            ll hs = H2[i];
            if (i>=len){
                  ll temp = amodb(H2[i-len]*P[len],mod);
                  hs-=temp;
                  if (hs<0)hs+=mod;
            }
            if (mp[hs]==1)mp[hs] = 2;
      }
      for (int i=len-1 ; i<k; i++){
            ll hs = H3[i];
            if (i>=len){
                  ll temp = amodb(H3[i-len]*P[len],mod);
                  hs-=temp;
                  if (hs<0)hs+=mod;
            }
            if (mp[hs]==2)return true;
      }
      return false;
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<maxn ; i++)P[i] = amodb(P[i-1]*base,mod);

      int tc;
      cin >> tc;

      for (int _t = 1 ; _t<=tc; _t++){

            string s1,s2,s3;
            cin >> s1 >> s2 >> s3;

            n = s1.size() , m = s2.size() , k = s3.size();

            createHash(s1,s2,s3);

            ll b = 0 , e = min(n,min(m,k)) , ans = 0;
            while(b<=e){

                  ll mid = (b+e)/2;
                  if (check(mid)){
                        ans = max(ans,mid);
                        b = mid+1;
                  }
                  else e = mid-1;
            }
            cout << "Case "<<_t<<": "<< ans << "\n";
      }

      return 0;
}
