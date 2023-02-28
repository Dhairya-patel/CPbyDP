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
    int n, k;
    cin>>k>>n;
    // k => len of v ; n => max num in v
    vector<ll>v(k);
    ll curr = 1, cnt = 0, ind = -1;
    for(int i=0;i<k;i++)
    {
        if(i)
            v[i] = v[i - 1] + curr, curr++;
        else
            v[i] = curr;
    }
    for(int i=k - 1;i>=0;i--)
    {
        if(v[i] <= n)
            break;
        cnt++;
        ind = i;
    }
    if(ind == -1LL)
    {
        for(int i=0;i<k;i++)
            cout<<v[i]<<" ";
        cout<<endl;
        return;
    }
    vector<ll>ans;
    curr = n;
    for(int i=ind - 1;i>=0;i--)
    {
        if(i)
        {
            if(cnt > 0)
            {
                while(curr != v[i] && i - 1 >= 0 && curr > v[i - 1] && cnt > 0)
                {
                    ans.pb(curr);
                    curr--, cnt--;
                }
            }
        }
        ans.pb(v[i]);
        curr = v[i] - 1;
    }
    for(int i=k-1;i>=0;i--)
        cout<<ans[i]<<" ";
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