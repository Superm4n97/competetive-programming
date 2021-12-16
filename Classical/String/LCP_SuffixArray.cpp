#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 400005

using namespace std;

/**
-call only buildSuffixArray(s) buildLCP(s) in main function
-LCP is the longest common prefix match to the previous suffix array
-Suffix Array and Longest Common Prefix(LCP) - NLogN
-string er i index theke shuru korle ta SA[] array er previous kototuk
match korbe ta thakbe LCP[i] te**/
int SA[maxn] , C[maxn] , LCP[maxn] , N , prevSuffix[maxn];///SA is the suffix array
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
      buildLCP(s);

      for (int i=0 ; i<N ; i++)printf("%d ",LCP[i]);

      return 0;
}
/**

**/
