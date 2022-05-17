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

bool cmp(pii &a, pii &b)
{
    return a.ss > b.ss;
}

void solve()
{
    int n, m;
    cin>>n>>m;
    ll ans = 0;
    vector<pii> v(m);
    for(int i=0;i<m;i++)
        cin>>v[i].ff>>v[i].ss;
    sort(all(v), cmp);
    for(int i=0;i<m;i++)
    {
        if(n >= v[i].ff)
            n -= v[i].ff, ans += v[i].ff * v[i].ss;
        else
            ans += n * v[i].ss, n = 0;
    }
    cout<<ans;
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