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

int n, k;
vector<int>v;
int dp[maxn];

int recur(int i)
{
    if(i < 0)
        return 1e8;
    if(i == 0)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;
    for(int j=i-1;j>=max(0, i-k);j--)
        ans = min(ans, recur(j) + abs(v[i] - v[j]));
    return dp[i] = ans;
}

void solve()
{
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    setv(dp, -1);
    cout<<recur(n - 1);
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