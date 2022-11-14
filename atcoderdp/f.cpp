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

int dp[maxn][maxn];
string s, t, ans;

int recur(int i, int j)
{
    if(i < 0 || j < 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == t[j])
        return dp[i][j] = max({1 + recur(i - 1, j - 1), recur(i - 1, j), recur(i, j - 1)});
    return dp[i][j] = max(recur(i - 1, j), recur(i, j - 1));
}

void trace(int i, int j)
{
    if(i < 0 || j < 0)
        return;
    if(s[i] == t[j])
    {
        int ch1 = 1 + recur(i - 1, j - 1), ch2 = recur(i - 1, j), ch3 = recur(i, j - 1);
        if(ch1 > ch2 && ch1 > ch3)
        {
            ans.pb(s[i]);
            trace(i - 1, j - 1);
            return;
        }
        if(ch2 > ch3)
            trace(i - 1, j);
        else
            trace(i, j - 1);
        return;
    }
    int ch2 = recur(i - 1, j), ch3 = recur(i, j - 1);
    if(ch2 > ch3)
        trace(i - 1, j);
    else
        trace(i, j - 1);
}

void solve()
{
    cin>>s>>t;
    setv(dp, -1);
    ans = "";
    recur(s.lnt() - 1, t.lnt() - 1);
    trace(s.lnt() - 1, t.lnt() - 1);
    reverse(all(ans));
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