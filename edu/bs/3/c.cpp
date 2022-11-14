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

bool good(ll mx, ll n, ll cows, vector<ll> &v)
{
    ll pl = 0, last = v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i] - last >= mx)
        {
            if(last == v[0])
                pl++;
            pl++, last = v[i];
        }
    }
    return pl >= cows;
}

void solve()
{
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    ll l = 0, r = v[n - 1] - v[0] + 2, mid;
    while(l + 1 < r)
    {
        mid = (l + r) / 2;
        if(good(mid, n, k, v))
            l = mid;
        else
            r = mid;
    }
    cout<<l;
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