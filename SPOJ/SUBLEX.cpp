/** LCP is the longest common prefix match to the previous suffix array**/
/** Suffix Array and Longest Common Prefix(LCP) - NLogN**/

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 400005

using namespace std;

/**
abcab
5 3 0 4 1 2
2 1 0 0 0 0
#     5
ab    3
abcab 0
b     4
bcab  1
cab   2

abcab
a
ab
abc
abca
abcab
b
bc
bca
bcab
c
ca
cab

**/
///SA is the suffix array (1 based)
int SA[maxn] , C[maxn] , LCP[maxn] , N , prevSuffix[maxn];

void buildLCP(string s)///LCP is build on the basis of SA[]
{
      prevSuffix[SA[0]] = -1;

      for (int i=1 ; i<N ; i++)prevSuffix[SA[i]] = SA[i-1];

      for (int i=0 , L = 0; i<N ; i++){

            if (prevSuffix[i]==-1){
                  LCP[i] = 0;
                  break;
            }

            while(s[i+L] == s[prevSuffix[i]+L])L++;

            LCP[i] = L;

            L = max(L-1 , 0);
      }
}
void countingSort(vector < pair < pair <ll,ll> , ll > >  &vk)
{
      vector <ll> CNT(N+3) , POS(N+3);
      vector < pair < pair <ll,ll> , ll > > vk_new(N);

      for (int i=0 ; i<N ; i++){
            CNT[vk[i].first.first]++;
      }

      POS[0] = 0;
      for (int i=1 ; i<N ; i++){

            POS[i] = POS[i-1] + CNT[i-1];
      }

      for (int i=0 ; i<N ; i++){

            vk_new[POS[vk[i].first.first]] = vk[i];
            POS[vk[i].first.first]++;
      }

      vk = vk_new;

      return;
}
void buildSuffixArray(string s)
{
      string lcpstring = s;
      s.push_back('$');N = s.size();

      int indexMapping[N+5];
      memset(indexMapping,0,sizeof indexMapping);

      {///k==0
            vector < pair < char, ll > > vk0;
            for (int i=0 ; i<N ; i++)vk0.push_back({s[i],i});
            sort(vk0.begin(),vk0.end());

            SA[0] = vk0[0].second;
            indexMapping[SA[0]] = 0;
            C[0] = 0;

            for (int i=1 ; i<N ; i++){

                  SA[i] = vk0[i].second;
                  indexMapping[SA[i]] = i;

                  if(vk0[i].first != vk0[i-1].first)C[i] = C[i-1]+1;
                  else C[i] = C[i-1];
            }
      }

      {     ///k>0
            int k = 0;

            while((1<<k) <= N){

                  vector < pair < pair <ll,ll> , ll > > vk;
                  for (int i=0 ; i<N ; i++){

                        ll b = C[i] , a = C[indexMapping[(SA[i] - (1<<k) + N ) % N]];
                        vk.push_back({{a,b},(SA[i] - (1<<k) + N ) % N});
                  }

                  countingSort(vk);

                  SA[0] = vk[0].second;
                  indexMapping[SA[0]] = 0;
                  C[0] = 0;

                  for (int i=1 ; i<N ; i++){

                        SA[i] = vk[i].second;
                        indexMapping[SA[i]] = i;

                        if (vk[i].first != vk[i-1].first)C[i] = C[i-1]+1;
                        else C[i] = C[i-1];
                  }

                  k++;
            }
      }
      buildLCP(lcpstring);
}
int main()
{
      string s;
      cin >> s;
      buildSuffixArray(s);

      ll tc , n = s.size() , x , y;
      scanf("%lld",&tc);

      while(tc--){
            ll a;
            scanf("%lld",&a);

            for (int i=1 ; i<=n ; i++){
                  ll id = SA[i];
                  ll dis = (n-id) - LCP[id];

                  if (dis<a) a-= dis;
                  else {
                        x = id;
                        y = (n-1) - (dis-a);
                        break;
                  }
            }
            for (int i=x ; i<=y ; i++)printf("%c",s[i]);
            printf("\n");
      }

      return 0;
}
