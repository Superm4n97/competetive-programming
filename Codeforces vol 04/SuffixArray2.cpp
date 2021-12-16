#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 400005

using namespace std;

ll P[maxn],C[maxn];

void countingSort(vector < pair < pair < ll,ll > , ll > > &vk, int n)
{
      vector < pair < pair <ll,ll> , ll > > G1[n+5],G2[n+5];

      for (int i=0 ; i<n ;i++){
            G1[vk[i].first.second].push_back(vk[i]);
      }

      for (int i=0 ; i<n ; i++){
            if(G1[i].empty())continue;

            for (int j=0 ; j<G1[i].size() ; j++){

                  pair < pair <ll,ll> , ll > _x = G1[i][j];

                  G2[_x.first.first].push_back(_x);
            }
      }

      vk.clear();

      for (int i=0 ; i<n ; i++){
            if (G2[i].empty())continue;

            for (int j = 0 ;j<G2[i].size() ; j++){

                  pair < pair <ll,ll> , ll > _x = G2[i][j];
                  vk.push_back(_x);
            }
      }
}

void BuildSuffixArray(string s)
{
      s.push_back('$');

      int n = s.size();
      int indexmapping[n+5];

      {///k==0
            vector < pair < char , int > > vk0;
            for (int i=0 ; i<n ; i++)vk0.push_back({s[i],i});
            sort(vk0.begin(),vk0.end());

            P[0] = vk0[0].second;
            indexmapping[P[0]] = 0;
            C[0] = 0;

            for (int i=1 ; i<n ; i++){

                  P[i] = vk0[i].second;
                  indexmapping[P[i]] = i;

                  if (vk0[i].first != vk0[i-1].first)C[i] = C[i-1]+1;
                  else C[i] = C[i-1];
            }
      }

      int k = 0;

      {
            while((1<<k)<n){

                  vector < pair < pair < ll, ll > , ll > > vk;

                  for (int i=0 ; i<n ; i++){

                        vk.push_back({{C[indexmapping[i]],C[indexmapping[(i+(1<<k))%n]]},i});
                  }
                  countingSort(vk,n);


                  P[0] = vk[0].second;
                  indexmapping[P[0]] = 0;
                  C[0] = 0;

                  for (int i=1 ; i<n ; i++){

                        P[i] = vk[i].second;
                        indexmapping[P[i]] = i;

                        if (vk[i].first != vk[i-1].first)C[i] = C[i-1]+1;
                        else C[i] = C[i-1];
                  }

                  //cout << "C = ";
                  //for (int i=0; i<n; i++)cout << C[i] << " ";
                  //cout << endl;

                  k++;
            }
      }
}

int main()
{
      string s;
      cin >> s;

      BuildSuffixArray(s);

      for (int i=0 ; i<=s.size() ; i++)cout << P[i] << " ";

      return 0;
}
