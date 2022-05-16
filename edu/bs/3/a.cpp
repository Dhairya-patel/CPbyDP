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
#define eps 1e-7
#define ff first
#define ss second 
#define sz size
#define lnt length
#define here(x) cout << #x << " is " << x << endl;
#define setv(x, v) memset(x, v, sizeof(x))
#define prec(x) cout << setprecision(x);
#define fio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool good(ld t, int n, vector<ld> &x, vector<ld> &v)
{
    ld lx, rx;
    lx = x[0] - (t * v[0]), rx = (t * v[0]) + x[0];
    for(int i=1;i<n;i++)
    {
        ld templ = x[i] - (t * v[i]), tempr = (t * v[i]) + x[i];
        if(templ > rx || tempr < lx)
            return false;
        lx = max(lx, templ);
        rx = min(rx, tempr);
        // if(rx < lx)
        //     return false;
    }
    return true;
}

void solve()
{
    int n;
    cin>>n;
    vector<ld> x(n), v(n);
    for(int i=0;i<n;i++)
        cin>>x[i]>>v[i];
    ld l = 0, r = 1e18, mid;
    while(r - l > eps)
    {
        mid = (l + r) / 2;
        // here(l);here(r);here(mid);
        if(good(mid, n, x, v))
            r = mid;
        else
            l = mid;
    }
    prec(8);
    cout<<r;
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