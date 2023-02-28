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

void solve()
{
    int n, mn = 0, mx = INT_MAX;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    bool f = true;
    for(int i=0;i<n-1;i++)
    {
        if(v[i] > v[i + 1])
        {
            f = false;
            break;
        }
    }
    if(f)
    {
        cout<<0<<endl;
        return;
    }
    f = true;
    for(int i=1;i<n;i++)
    {
        if(v[i - 1] < v[i])
        {
            f = false;
            break;
        }
    }
    if(f)
    {
        cout<<v[0]<<endl;
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        int x = (v[i] + v[i + 1]) / 2;
        int y = (v[i] + v[i + 1] + 1) / 2;
        if(v[i] < v[i + 1])
            mx = min(mx, x);
        if(v[i] > v[i + 1])
            mn = max(mn, y);
    }
    if(mn <= mx)
        cout<<mn<<endl;
    else
        cout<<"-1"<<endl;
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

-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/