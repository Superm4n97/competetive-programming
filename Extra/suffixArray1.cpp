#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll P[maxn], C[maxn];

void suffixArray(string s)
{
      s.push_back('$');

      ll N = s.size();

      {///k=0
            vector < pair < char , ll > > vk0;
            for (int i=0; i<N ; i++)vk0.push_back({s[i],i});

            sort(vk0.begin(),vk0.end());

            P[0] = vk0[0].second;
            C[0] = 0;

            for (int i=1 ; i<N ; i++){
                  P[i] = vk0[i].second;
                  if (vk0[i].first==vk0[i-1].first)C[i] = C[i-1];
                  else C[i] = C[i-1]+1;
            }
      }

      ll k = 0;

      while((1<<k)<N){

            vector < pair < pair <ll,ll> , ll > > vk;
            ll indexMaping[N+5];

            for (int i=0 ; i<N ; i++)indexMaping[P[i]] = i;

            for (int i=0 ; i<N ; i++){

                  ll j = i+(1<<(k));
                  j%=N;

                  vk.push_back({{C[indexMaping[i]],C[indexMaping[j]]},i});
            }

            sort(vk.begin(),vk.end());

            P[0] = vk[0].second;
            C[0] = 0;

            for (int i=1 ; i<N ; i++){
                  P[i] = vk[i].second;

                  if (vk[i].first == vk[i-1].first)C[i] = C[i-1];
                  else C[i] = C[i-1]+1;
            }

            k++;
      }

      return;
}

int main()
{
      string s;
      cin >> s;

      suffixArray(s);

      for (int i=0;i<=s.size(); i++)cout << P[i] << " ";

      return 0;
}

/*
ababba$

6.$ababba$
5.a$ababba
0.ababba$a
2.abba$aba
4.ba$ababb
1.babba$ab
3.bba$abab

*/
