#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pii pair<int, int>
#define inf INT_MAX
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define maxn 100000+5
#define eps 1e-10
#define ff first
#define ss second 
#define sz size
#define lnt length
#define here(x) cout << #x << " is " << x << endl;
#define setv(x, v) memset(x, v, sizeof(x))
#define prec(x) cout << fixed << setprecision(x);
#define fio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve()
{
    vector<string>v;
    string str;
    vector<int>adj[3], s;
    vector<int>ind(3, 0);
    for(int i=0;i<3;i++)
    {
        cin>>str;
        if(str[1] == '<')
            adj[str[2] - 'A'].pb(str[0] - 'A'), ind[str[0] - 'A'] = ind[str[0] - 'A'] + 1;
        else
            adj[str[0] - 'A'].pb(str[2] - 'A'), ind[str[2] - 'A'] = ind[str[2] - 'A'] + 1;
    }
    queue<int>que;
    vector<bool>vis(3, false);
    for(int i=0;i<3;i++)
    {
        if(ind[i] == -1)
        {
            cout<<"Impossible";
            return;
        }
        if(ind[i] == 0)
            que.push(i);
        // cout<<ind[i]<<" ";
    }
    // cout<<endl;
    while(!que.empty())
    {
        int cv = que.front();
        // cout<<cv<<" ";
        que.pop();
        vis[cv] = true;
        s.pb(cv);
        for(int i=0;i<adj[cv].sz();i++)
        {
            if(!vis[adj[cv][i]])
            {
                ind[adj[cv][i]]--;
                if(ind[adj[cv][i]] == 0)
                    que.push(adj[cv][i]);
            }
        }
    }
    if(s.sz() == 3)
    {
        for(int i=2;i>=0;i--)
        {
            if(s[i] == 0)
                cout<<"A";
            else if(s[i] == 1)
                cout<<"B";
            else
                cout<<"C";
        }
        return;
    }
    cout<<"Impossible";
}

int main()
{
    fio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

/*

-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/