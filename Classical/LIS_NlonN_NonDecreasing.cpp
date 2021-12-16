#include<bits/stdc++.h>
#define ll long long int
#define maxn 500005
#define inf 100000000000014
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[maxn] , fix[maxn] , nxt[maxn];

int LongestNonDecreasingSequecne_NlogN(vector <ll> org)
{
      if (org.empty())return 0;

      vector <ll> len;
      len.push_back(0);
      len.push_back(org[0]);

      for (int i=1 ; i<org.size() ; i++){

            ll sz_len = len.size();
            if (len[1]>org[i])len[1] = org[i];
            else if (len[sz_len-1] <= org[i])len.push_back(org[i]);
            else {

                  ll b = 1 , e = sz_len-1 , res = -1;
                  while(b<=e){

                        ll mid = (b+e)/2;
                        if (len[mid] <= org[i]){

                              res = max(res,mid);
                              b = mid+1;
                        }
                        else e = mid-1;
                  }
                  len[res+1] = org[i];
            }
      }

      return len.size()-1;
}

int main()
{


      return 0;
}
