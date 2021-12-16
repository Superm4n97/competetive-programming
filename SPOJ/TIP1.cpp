#include<bits/stdc++.h>
#define ll long long int
#define maxn 10000007
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll phi[maxn], cper[maxn];

ll amodb(ll a, ll b)
{
      ll temp = a/b;
      return a-temp*b;
}

bool isPermutation(ll a)
{
      ll mp[12];
      memset(mp,0,sizeof mp);

      ll b = a;
      while(b){
            ll temp = amodb(b,10);
            mp[temp]++;
            b/=10;
      }
      ll c = phi[a];
      while(c){
            ll temp = amodb(c,10);
            if (mp[temp]==0)return false;
            mp[temp]--;
            c/=10;
      }
      for (int i=0 ; i<10 ; i++){
            if (mp[i])return false;
      }return true;
}

void EularTotient()
{
      for (int i=1 ; i<maxn ;i++)phi[i] = i;
      for (int i=2 ; i<maxn ; i++){
            if (phi[i]==i){
                  for (int j=i ; j<maxn ; j+=i){
                        phi[j]/=i;
                        phi[j]*=(i-1);
                  }
            }
      }
      return;
}

void cumulativePermutation()
{
      ll ids[]={21,63,291,2817,2991,4435,20617,45421,69271,75841,162619,176569,284029,400399,474883,732031,778669,783169,1014109,1288663,1504051,1514419,1924891,1956103,2006737,2044501,2094901,2239261,2710627,2868469,3582907,3689251,4198273,4696009,5050429,5380657,5886817,6018163,6636841,7026037,7357291,7507321,8316907,8319823};
      cper[0] = cper[1] = -1;
      //show(ids[43]);
      for (int i=0 ; i<=43 ; i++)cper[ids[i]] = ids[i];
      for (int i=2 ; i<maxn ; i++){
            if (cper[i]==0)cper[i] = cper[i-1];
      }
      return;
}

//cper[i]/phi[cper[i]] >= i/phi[i]

int main()
{
      EularTotient();
      cumulativePermutation();

      ll tc;
      scanf("%lld",&tc);
      while(tc--){
            ll a;
            scanf("%lld",&a);
            if (cper[a-1]==-1)printf("No solution.\n");
            else printf("%lld\n",cper[a-1]);
      }

      return 0;
}
