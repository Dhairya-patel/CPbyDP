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

map<int, vector<int>>adj;
vector<int>ans;

void dfs(int cv, int par)
{
    ans.pb(cv);
    for(int i=0;i<adj[cv].sz();i++)
        if(adj[cv][i] != par)
            dfs(adj[cv][i], cv);
}

void solve()
{
    int n;
    cin>>n;
    map<int, int>ind;
    for(int i=0;i<n;i++)
    {
        int x, y;
        cin>>x>>y;
        ind[x]++, ind[y]++;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(auto x : ind)
    {
        if(x.ss == 1)
        {
            dfs(x.ff, -1);
            break;
        }
    }
    for(int i=0;i<ans.sz();i++)
        cout<<ans[i]<<" ";
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

-> if A task description is long, MUST READ it properly
-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/