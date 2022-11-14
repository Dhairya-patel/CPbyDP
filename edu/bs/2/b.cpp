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
#define prec(x) cout << setprecision(x);
#define fio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool good(double x, int k, vector<int> &v)
{
    int cnt = 0;
    for(int i=0;i<v.sz();i++)
        cnt += (v[i] / x);
    return cnt >= k;
}

void solve()
{
    int n, k, mx = -1;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i], mx = max(mx, v[i]);
    double l = 0, r = mx + 1, mid;
    prec(7);
    for(int i=0;i<100;i++)
    {
        mid = (l + r) / (double)2;
        if(good(mid, k, v))
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