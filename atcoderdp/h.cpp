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
#define maxn 1000+5
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

ll h, w, dp[maxn][maxn];
char mat[maxn][maxn];

ll recur(int i, int j)
{
    if(i < 1 || i > h || j < 1 || j > w)
        return 0;
    if(mat[i][j] == '#')
        return 0;
    if(i == 1 && j == 1)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j] % mod;
    return dp[i][j] = (recur(i, j - 1) + recur(i - 1, j)) % mod;
}

void solve()
{
    cin>>h>>w;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            cin>>mat[i][j];
    setv(dp, -1);
    cout<<recur(h, w) % mod;
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