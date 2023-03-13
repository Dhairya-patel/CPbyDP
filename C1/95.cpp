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
#define maxn 30+5
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

ll ncr[maxn][maxn] = {0};

void init()
{
    for(int i=0;i<maxn;i++)
        ncr[0][i] = 0, ncr[i][0] = 1, ncr[i][1] = i;
    for(int i=1;i<maxn;i++)
        for(int j=1;j<maxn;j++)
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
}

void solve()
{
    ll n, m, t, ans = 0;
    cin>>n>>m>>t;
    init();
    for(ll i=4;i<=n && i<t;i++)
    {
        if(t - i >= 1 && t - i <= m)
        {
            ll ch1 = ncr[n][i], ch2 = ncr[m][t - i];
            ans += (ch1 * ch2);
        }
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

-> if A task description is long, MUST READ it properly
-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/