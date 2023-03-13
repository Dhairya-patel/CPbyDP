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

int get(int x)
{
    for(int i=0;i<32;i++)
        if(x&(1<<i))
            return pow(2, i);
    return 0;
}

void solve()
{
    int sum, limit, mx_sum = 0;
    vector<pii>v;
    vector<int>ans;
    cin>>sum>>limit;
    for(int i=1;i<=limit;i++)
    {
        int x = get(i);
        mx_sum += x;
        v.pb({x, i});
    }
    if(mx_sum < sum)
    {
        cout<<"-1";
        return;
    }
    for(int i=v.sz()-1;i>=0;i--)
    {
        if(v[i].ff <= sum)
        {
            sum -= v[i].ff;
            ans.pb(v[i].ss);
        }
    }
    if(sum == 0)
    {
        cout<<ans.sz()<<endl;
        for(int i=0;i<ans.sz();i++)
            cout<<ans[i]<<" ";
        return;
    }
    cout<<"-1";
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