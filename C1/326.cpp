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

bool ok(ll x)
{
    int c = 0;
    while(x % 2LL == 0LL)
    {
        c++;
        x /= 2LL;
        if(c > 1)
            return false;
    }
    for(ll i=3;i*i<=x;i+=2LL)
    {
        if(x % i == 0LL)
        {
            c = 0;
            while(x % i == 0LL)
            {
                c++;
                x /= i;
                if(c > 1)
                    return false;
            }
        }
    }
    return true;
}

void solve()
{
    ll x, ans;
    cin>>x;
    vector<ll>v;
    for(ll i=1;i*i<=x;i++)
    {
        if(x % i == 0LL)
        {
            if(i == x/i)
                v.pb(i);
            else
                v.pb(i), v.pb(x / i);
        }
    }
    sort(all(v));
    for(int i=0;i<v.sz();i++)
    {
        // cout<<v[i]<<" "<<ok(v[i])<<endl;
        if(ok(v[i]))
            ans = v[i];
    }
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

-> if A task description is long, MUST READ it properly
-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/