#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008

using namespace std;

vector < pair < int , pair < int ,int > >  > vp1, vp2;
int n;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        int a,b;
        scdd(a,b);
        if (a>b)vp1.pb(mk(a,mk(b,i+1)));
        else vp2.pb(mk(a,mk(b,i+1)));
    }
    if (vp1.size()>vp2.size()){
        srt(vp1);
        cout << vp1.size() << endl;
        for (int i=0;i<vp1.size();i++)cout << vp1[i].second.second << " ";
        cout << endl;
    }
    else {
        rsrt(vp2);
        cout << vp2.size() << endl;
        for (int i=0;i<vp2.size();i++)cout << vp2[i].second.second << " ";
        cout << endl;
    }

    return 0;
}
