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

bool dp[maxn][5], vis[maxn][5];

bool recur(int i, int f, int n, vector<int> &v, vector<int> &a)
{
    if(i >= n)
    {
        if(a.sz() < 3)
            return false;
        // cout<<"here: "<<endl;
        // for(int j=0;j<a.sz();j++)
        //     cout<<a[j]<<" ";
        // cout<<endl;
        int space = a[1] - a[0];
        if(n - a[a.sz() - 1] + a[0] != space)
            return false;
        return true;
    }
    if(vis[i][f])
        return dp[i][f];
    bool ans = false;

    if(v[i] == 0)
    {
        ans = ans | recur(i + 1, f, n, v, a);
        vis[i][f] = true;
        return dp[i][f] = ans;
    }

    if(f == 0)
    {
        a.pb(i);
        ans = ans | recur(i + 1, 1, n, v, a);
        if(!a.empty())
            a.pop_back();
        ans = ans | recur(i + 1, 0, n, v, a);
    }
    else if(f == 1)
    {
        a.pb(i);
        ans = ans | recur(i + 1, 2, n, v, a);
        if(!a.empty())
            a.pop_back();
        ans = ans | recur(i + 1, 1, n, v, a);
    }
    else
    {
        
        int diff = a[1] - a[0];
        // cout<<i<<" -->  "<<diff<<" : "<<a[1]<<", "<<a[0]<<endl;
        if(i - a.back() > diff)
        {
            while(a.sz() > 1)
                a.pop_back();
            a.pb(i);
            ans = ans | recur(i + 1, 2, n, v, a);
            if(!a.empty())
                a.pop_back();
            ans = ans | recur(i + 1, 1, n, v, a);
        }
        else if(i - a.back() == diff)
        {
            a.pb(i);
            ans = ans | recur(i + 1, 3, n, v, a);
        }
        else
        {
            ans = ans | recur(i + 1, 2, n, v, a);
        }
    
    }
    // cout<<a.sz()<<endl;
    vis[i][f] = true;
    return dp[i][f] = ans;
}

void solve()
{
    setv(dp, false);
    setv(vis, false);
    int n;
    cin>>n;
    vector<int>v(n), a;
    for(int i=0;i<n;i++)
        cin>>v[i];
    bool f = recur(0, 0, n, v, a);
    if(f)
        cout<<"YES";
    else
        cout<<"NO";
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