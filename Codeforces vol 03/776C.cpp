#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

map < ll, ll > mp;
ll A[maxn];
vector < ll > pw;

int main()
{
      ll n,k;
      cin >> n >> k;

      for (ll i = 1;  i<=n ; i++)scanf("%I64d",&A[i]);

      if (k==1){
            pw.push_back(1);
      }
      else if (k==-1){
            pw.push_back(1);
            pw.push_back(-1);
      }
      else {
            ll temp = 1;
            while(temp<=1000000000000005){
                  pw.push_back(temp);
                  temp*=k;
            }
      }

      ll sum = 0 , ans = 0;
      mp[sum] = 1;
      for (int i=1 ; i<=n ; i++){
            sum+=A[i];
            mp[sum]++;
            for (int j=0 ; j<pw.size() ;j++){
                  ll need = sum - pw[j];
                  ans+=mp[need];
            }
      }

      cout << ans << endl;


      return 0;
}
