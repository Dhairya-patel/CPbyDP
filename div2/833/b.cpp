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

//max occurance of a ch <= no of distinct ch in diverse strings
//max no. of distinct ch = 10 (0...9)
//max no. of occurance of a ch = 10
//max len of div str = 100, so need to check till 100

void solve()
{
    int n, ans = 0;
    string str;
    cin>>n>>str;
    for(int i=0;i<n;i++)
    {
        int mxoc = 0, dist = 0;
        int cnt[10] = {0};
        for(int j=i;j < i+100 && j < n;j++)
        {
            cnt[str[j] - '0']++;
            if(cnt[str[j] - '0'] > 10)
                break;
            if(cnt[str[j] - '0'] == 1)
                dist++;
            mxoc = max(mxoc, cnt[str[j] - '0']);
            if(dist >= mxoc)
                ans++;
        }
    }
    cout<<ans<<endl;
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