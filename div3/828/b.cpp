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
    int n, q;
    cin>>n>>q;
    vector<ll>v(n);
    ll ce = 0, co = 0, se = 0, so = 0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]&1)
            so += v[i], co++;
        else
            se += v[i], ce++;
    }
    for(int i=0;i<q;i++)
    {
        int type, val;
        cin>>type>>val;
        if(type == 0)
        {
            if(val&1)
            {
                // counts will get exchanged odd + even
                so += se + (ce * val);
                co += ce;
                ce = se = 0;
            }
            else
            {
                se += (ce * val);
            }
        }
        else
        {
            if(val&1)
            {
                //  counts will get exchanged odd + odd
                se += so + (co * val);
                ce += co;
                co = so = 0;
            }
            else
            {
                so += (co * val);
            }
        }
        cout<<se + so<<endl;
    }
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