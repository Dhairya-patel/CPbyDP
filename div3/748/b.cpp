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

map<ll, int>dp;

int recur(ll n)
{
    if(n % 25LL == 0LL)
        return 0;
    if(n < 25LL)
        return 1e8;
    int a = n%10LL, b = (n/10LL) % 10LL;
    if(a != 0 && a != 5)
        return dp[n] = 1 + recur(n/10LL);
    return dp[n] = 1 + min(recur(((n/100LL) * 10LL) + (n%10LL)), recur(n/10LL));
}

void solve()
{
    ll n;
    cin>>n;
    cout<<recur(n)<<endl;
}

int main()
{
    fio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
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