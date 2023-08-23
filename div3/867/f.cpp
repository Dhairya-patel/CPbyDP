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
#define maxn 200000+5
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

vector<int>adj[maxn];
bool vis[maxn];
int dist[maxn], adist[maxn];
int mx = 0, far = -1;

void dfs(int cv, int d)
{
    vis[cv] = true;
    dist[cv] = d;
    if(mx < d)
        far = cv, mx = d;
    for(int i=0;i<adj[cv].sz();i++)
    {
        if(!vis[adj[cv][i]])
            dfs(adj[cv][i], d + 1);
    }
}

void dfs2(int cv, int d)
{
    vis[cv] = true;
    adist[cv] = d;
    // cout<<cv<<", "<<d<<endl;
    if(mx < d)
        far = cv, mx = d;
    for(int i=0;i<adj[cv].sz();i++)
    {
        // cout<<" : "<<adj[cv][i]<<" - "<<vis[adj[cv][i]]<<endl;
        if(!vis[adj[cv][i]])
        {
            // cout<<"inside"<<endl;
            dfs2(adj[cv][i], d + 1);
        }
    }
}

void reset()
{
    mx = 0, far = -1;
    setv(dist, -1);
    setv(adist, -1);
    setv(vis, false);
}

void resetWithoutA()
{
    mx = 0, far = -1;
    // setv(dist, -1);
    setv(adist, -1);
    setv(vis, false);
}

void solve()
{
    ll n, k, c;
    cin>>n>>k>>c;
    for(int i=0;i<n - 1;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    //  find diameter of the tree
    reset();
    dfs(1, 0);
    int a = far;
    ll ad = mx;
    resetWithoutA();
    dfs2(a, 0);
    // cout<<endl;
    ll ans = k * ad;
    for(int i=1;i<=n;i++)
    {
        // cout<<i<<" : "<<endl;
        // cout<<dist[i]<<" , "<<adist[i]<<" ==>  "<<(k * adist[i]) - (c * dist[i])<<endl;
        ans = max(ans, (k * adist[i]) - (c * dist[i]));
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        adj[i].clear();
}

int main()
{
    fio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin>>t;
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