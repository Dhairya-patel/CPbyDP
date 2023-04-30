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
    string str;
    cin>>n>>str;
    if(n&1)
    {
        cout<<"-1"<<endl;
        return;
    }
    int hh[26] = {0};
    for(int i=0;i<n;i++)
        hh[str[i] - 'a']++;
    for(int i=0;i<26;i++)
    {
        if(hh[i] > n/2)
        {
            cout<<"-1"<<endl;
            return;
        }
        hh[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        if(str[i] == str[n - i - 1])
            hh[str[i] - 'a']++;
    }
    int ans = 0, mx = 0;
    for(int i=0;i<26;i++)
        hh[i] /= 2, mx = max(mx, hh[i]), ans += hh[i];
    cout<<max(mx, (ans + 1) / 2)<<endl;
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

-> if A task description is long, MUST READ it properly
-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/