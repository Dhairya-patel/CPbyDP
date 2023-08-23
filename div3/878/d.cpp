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

bool good(ll t, int n, vector<ll> &v)
{
    int l = 1, r = n - 2;
    for(int i=1;i<n;i++)
        if(v[i] - v[0] > 2LL * t)
        {
            l = i;
            break;
        }
    for(int i=n-2;i>=0;i--)
        if(v[n - 1] - v[i] > 2LL * t)
        {
            r = i;
            break;
        }
    if(l > r)
        return true;
    if(v[r] - v[l] <= 2LL * t)
        return true;
    return false;
}

void solve()
{
    int n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(all(v));
    if(n <= 3)
    {
        cout<<"0"<<endl;
        return;
    }
    ll l = -1, r = 1e9 + 1, mid;
    while(l + 1 < r)
    {
        mid = (l + r) / 2LL;
        if(good(mid, n, v))
            r = mid;
        else
            l = mid;
    }
    cout<<r<<endl;
}

int main()
{
    fio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin>>t;
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