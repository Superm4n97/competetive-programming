#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n,i,a,b,counter=0;
    string s,t;
    cin >> n >> s >> t;
    vector<int>v[30];
    set<int>mset;
    for(i=0;i<n;i++)
    {
        if(s[i]<t[i])
        {
            a=s[i]-'a'+1;
            b=t[i]-'a'+1;
            mset.insert(a);
            mset.insert(b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(s[i]>t[i])
        {
            counter--;
            break;
        }
    }
    if(counter==-1)
    {
        cout << counter << endl;
        continue;
    }
    int visited[30];
    memset(visited,0,sizeof(visited));
    for(int x:mset)
    {
        if(visited[x]==0)
        {
            visited[x]=1;
            queue<int>Q;
            Q.push(x);
            while(!Q.empty())
            {
                a=Q.front();
                Q.pop();
                for(int x:v[a])
                {
                    if(visited[x]==0)
                    {
                        visited[x]=1;
                        counter++;
                        Q.push(x);
                    }
                }
            }
        }
    }
    cout << counter << endl;
    for(i=0;i<27;i++)
    {
        v[i].clear();
    }
    }
}
