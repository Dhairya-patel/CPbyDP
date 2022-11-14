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
#define maxn 3000+5
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
vector<double>v;
double dp[maxn][maxn];

double recur(int i, int cnt)
{
    if(i < 0)
    {
        if(cnt >= v.sz() / 2 + 1)
            return 1;
        return 0;
    }
    if(dp[i][cnt] != (double)-1)
        return dp[i][cnt];
    return dp[i][cnt] = (v[i] * recur(i - 1, cnt + 1)) + (((double)1 - v[i]) * recur(i - 1, cnt));
}

void solve()
{
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = -1;
    prec(12);
    cout<<recur(n - 1, 0);
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