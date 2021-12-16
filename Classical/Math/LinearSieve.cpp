
#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 15000007

using namespace std;

/** Linear Sieve Works in O(n)**/
vector < ll > Prime; /// Finds all the Primes in sorted order range: 2-maxn
ll mnDiv[maxn]; /// Finds minimum divisor of all the numbers
void LinearSieve()
{
      memset(mnDiv,-1,sizeof mnDiv);
      mnDiv[1] = 1;
      for (ll i=2 ; i<maxn ; i++){
            if (mnDiv[i]==-1){
                  mnDiv[i] = i;
                  Prime.push_back(i);
            }
            for (ll j = 0 ; j<Prime.size() && Prime[j]*i<maxn ; j++){
                  mnDiv[Prime[j]*i] = Prime[j];
                  if (i%Prime[j]==0)break;
            }
      }
}
int main()
{
      LinearSieve();


      return 0;
}

