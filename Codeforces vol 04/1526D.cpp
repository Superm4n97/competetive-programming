#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x);

using namespace std;

string s;
ll cnt[5], n;
ll way[30][5];

int char2int(char ch)
{
      if (ch=='A')return 0;
      if (ch=='N')return 1;
      if (ch=='O')return 2;
      if (ch=='T')return 3;
}
char int2char(ll i)
{
      if (i==0)return 'A';
      if (i==1)return 'N';
      if (i==2)return 'O';
      if (i==3)return 'T';
}
bool checkRight(ll a, ll b, ll c, ll d)
{
      if (a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)return true;
      return false;
}
void init()
{
      ll temp = 0;
      for (int i=0 ; i<4 ; i++){
            for (int j=0 ; j<4 ; j++){
                  for (int k=0 ; k<4 ; k++){
                        for (int l=0 ; l<4 ; l++){
                              if (checkRight(i,j,k,l)){
                                    way[temp][0] = i;
                                    way[temp][1] = j;
                                    way[temp][2] = k;
                                    way[temp][3] = l;
                                    temp++;
                              }
                        }
                  }
            }
      }
      return;
}

ll sol(ll way_no)
{
      ll pre_cnt[5];
      memset(pre_cnt,0,sizeof pre_cnt);

      ll inv = 0;
      for (int i=0 ; i<n ; i++){
            ll temp = char2int(s[i]);
            for (int j=0 ; j<4 ; j++){
                  if (temp==way[way_no][j])break;
                  inv+=(cnt[way[way_no][j]]-pre_cnt[way[way_no][j]]);
            }
            pre_cnt[temp]++;
      }
      return inv;
}

int main()
{
      init();

      ll tc;
      scl(tc);
      while(tc--){
            cin >> s;
            vector<ll> v;

            memset(cnt,0,sizeof cnt);
            n = s.size();

            for (int i=0 ; i<n ; i++){
                  cnt[char2int(s[i])]++;
            }
            ll ans = 0 , id;
            for (int i=0; i<24 ; i++){
                  ll temp = sol(i);
                  if (temp>ans){
                        ans = temp;
                        id = i;
                  }
            }

            for (int i=0 ; i<4 ; i++){
                  ll x = way[id][i];
                  for (int j=0 ; j<cnt[x] ; j++){
                        cout << int2char(x);
                  }
            }
            cout << endl;
      }


      return 0;
}
/*
abc
acb
cba

anton
antno
annot
nnota

abbbbbb->ba
aaaaaab->ba
aaabbbb->ba

OAANTTON

TNNTAOOA
AAOOTTNN
*/
