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
    int n;
    cin>>n;
    vector<int>v(n), a(n, 0), b(n, 0);
    vector<bool>vis(n + 1, false);
    map<int, int>hh;
    for(int i=0;i<n;i++)
        cin>>v[i], hh[v[i]] = i;
    int curr = 1, cnt = 0;
    for(auto x : hh)
    {
        if(curr <= x.ff)
        {
            a[x.ss] = curr;
            b[x.ss] = x.ff;
            curr++;
            vis[x.ff] = true;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
        if(x.ff == n)
            cnt++;
    }
    if(cnt < 0 || cnt > )
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            q.push(i);
    for(int i=0;i<n;i++)
    {
        if(a[i] == 0)
            a[i] = v[i];
        if(b[i] == 0)
            b[i] = q.front(), q.pop();
    }
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(max(a[i], b[i]) != v[i] || a[i] > n || b[i] > n)
        {
            cout<<"NO"<<endl;
            return;
        }
        sum += a[i];
    }
    if(sum != (n * (n + 1)) / 2)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<endl;
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