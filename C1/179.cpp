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

struct query
{
    ll l, r, d;
};

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<ll>v(n + 1), a(m + 2, 0), net(n + 2, 0);
    vector<query>q(m + 1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=m;i++)
        cin>>q[i].l>>q[i].r>>q[i].d;  
    for(int i=0;i<k;i++)
    {
        int l, r;
        cin>>l>>r;
        //  a[i] is the count of times query i is run
        a[l]++;
        a[r + 1]--;
    }

    for(int i=1;i<=m;i++)
        a[i] += a[i - 1];
    for(int i=1;i<=m;i++)
    {
        //  net[i] is the amount to add at the place i
        ll left = q[i].l, right = q[i].r, diff = q[i].d * a[i];
        net[left] += diff;
        net[right + 1] -= diff;
    }
    for(int i=1;i<=n;i++)
        net[i] += net[i - 1];
    for(int i=1;i<=n;i++)
    {
        cout<<v[i] + net[i]<<" ";
    }
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