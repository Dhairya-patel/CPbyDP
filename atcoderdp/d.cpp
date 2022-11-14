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

ll n, W;
vector<ll>v, w;
ll dp[105][maxn];

ll recur(int i, int wi)
{
    if(i < 0 || wi <= 0)
        return 0;
    if(dp[i][wi] != -1)
        return dp[i][wi];
    //pick it or not
    if(wi - w[i] >= 0)
        return dp[i][wi] = max(v[i] + recur(i - 1, wi - w[i]), recur(i - 1, wi));
    //don't pick
    return dp[i][wi] = recur(i - 1, wi);
}

void solve()
{
    cin>>n>>W;
    v.resize(n), w.resize(n);
    for(int i=0;i<n;i++)
        cin>>w[i]>>v[i];
    setv(dp, -1);
    cout<<recur(n - 1, W);
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