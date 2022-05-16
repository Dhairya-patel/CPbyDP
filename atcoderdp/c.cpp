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

int n;
vector<int>a, b, c;
int dp[maxn][2][2][2];

int recur(int i, int x, int y, int z)
{
    if(i < 0)
        return -1e8;
    if(i == 0)
    {
        if(x)
            return a[i];
        if(y)
            return b[i];
        return c[i];
    }
    if(dp[i][x][y][z] != -1)
        return dp[i][x][y][z];
    if(x)
        return dp[i][x][y][z] = a[i] + max(recur(i - 1, 0, 1, 0), recur(i - 1, 0, 0, 1));
    if(y)
        return dp[i][x][y][z] = b[i] + max(recur(i - 1, 1, 0, 0), recur(i - 1, 0, 0, 1));
    return dp[i][x][y][z] = c[i] + max(recur(i - 1, 0, 1, 0), recur(i - 1, 1, 0, 0));
}

void solve()
{
    cin>>n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i]>>c[i];
    setv(dp, -1);
    cout<<max({recur(n - 1, 1, 0, 0), recur(n - 1, 0, 1, 0), recur(n - 1, 0, 0, 1)});
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