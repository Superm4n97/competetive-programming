/** Suffix Array - Complexity nLog(n) **/

#include<bits/stdc++.h>
#define ll long long int
#define maxn 400005

using namespace std;

int P[maxn] , C[maxn];///P is the suffix array

void countingSort(vector < pair < pair <ll,ll> , ll > >  &vk)
{
      ll N = vk.size();
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
      s.push_back('$');

      ll N = s.size();
      int indexMapping[N+5];
      memset(indexMapping,0,sizeof indexMapping);

      {///k==0
            vector < pair < char, ll > > vk0;
            for (int i=0 ; i<N ; i++)vk0.push_back({s[i],i});
            sort(vk0.begin(),vk0.end());

            P[0] = vk0[0].second;
            indexMapping[P[0]] = 0;
            C[0] = 0;

            for (int i=1 ; i<N ; i++){

                  P[i] = vk0[i].second;
                  indexMapping[P[i]] = i;

                  if(vk0[i].first != vk0[i-1].first)C[i] = C[i-1]+1;
                  else C[i] = C[i-1];
            }
      }

      {     ///k>0
            int k = 0;

            while((1<<k) <= N){

                  vector < pair < pair <ll,ll> , ll > > vk;
                  for (int i=0 ; i<N ; i++){

                        ll b = C[i] , a = C[indexMapping[(P[i] - (1<<k) + N ) % N]];
                        vk.push_back({{a,b},(P[i] - (1<<k) + N ) % N});
                  }

                  countingSort(vk);

                  P[0] = vk[0].second;
                  indexMapping[P[0]] = 0;
                  C[0] = 0;

                  for (int i=1 ; i<N ; i++){

                        P[i] = vk[i].second;
                        indexMapping[P[i]] = i;

                        if (vk[i].first != vk[i-1].first)C[i] = C[i-1]+1;
                        else C[i] = C[i-1];
                  }

                  k++;
            }
      }
}

int main()
{
      string s;
      cin >> s;

      buildSuffixArray(s);

      for (int i=0 ; i<=s.size() ; i++)printf("%d ",P[i]);

      return 0;
}
/**

**/
