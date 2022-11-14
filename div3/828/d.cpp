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
    int n, have = 0, ans = 0;
    cin>>n;
    vector<ll>v(n), p;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        ll x = v[i];
        int cnt = 0, ind = i + 1;
        while(x % 2LL == 0LL)
        {
            x /= 2LL;
            have++;
        }
        while(ind % 2 == 0)
        {
            ind /= 2;
            cnt++;
        }
        p.pb(cnt);
    }
    if(have >= n)
    {
        cout<<"0"<<endl;
        return;
    }
    sort(allr(p));
    for(int i=0;i < p.sz();i++)
    {
        have += p[i];
        ans++;
        if(have >= n)
        {
            cout<<ans<<endl;
            return;
        }
    }
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