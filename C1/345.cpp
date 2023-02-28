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

bool cmpx(pii &a, pii &b)
{
    if(a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff < b.ff;
}

bool cmpy(pii &a, pii &b)
{
    if(a.ss == b.ss)
        return a.ff < b.ff;
    return a.ss < b.ss;
}

void solve()
{
    int n;
    ll ans = 0;
    cin>>n;
    vector<pii>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].ff>>v[i].ss;
    sort(all(v), cmpx);
    for(int i=0;i<n;i++)
    {
        int pos = i, tmp = 1;
        for(int j=i+1;j<n;j++)
        {
            if(v[i].ff != v[j].ff)
            {
                break;
            }
            tmp++;
            pos = j;
        }
        ans += (tmp * (tmp - 1LL)) / 2LL;
        i = pos;
    }
    sort(all(v), cmpy);
    for(int i=0;i<n;i++)
    {
        int pos = i, tmp = 1;
        for(int j=i+1;j<n;j++)
        {
            if(v[i].ss != v[j].ss)
            {
                break;
            }
            tmp++;
            pos = j;
        }
        ans += (tmp * (tmp - 1LL)) / 2LL;
        i = pos;
    }
    for(int i=0;i<n;i++)
    {
        int pos = i, tmp = 1;
        for(int j=i+1;j<n;j++)
        {
            if(v[i].ss != v[j].ss || v[i].ff != v[j].ff)
            {
                break;
            }
            if(v[i].ff == v[j].ff && v[i].ss == v[j].ss)
                tmp++;
            pos = j;
        }
        ans -= (tmp * (tmp - 1LL)) / 2LL;
        i = pos;
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