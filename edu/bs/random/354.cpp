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

bool good(int len, int n, int k, string &str)
{
    int a = 0, b = 0;
    for(int i=0;i<len;i++)
        str[i] == 'a' ? a++ : b++;
    if(min(a, b) <= k)
        return true;
    for(int i=1, j=len;j<n;i++, j++)
    {
        str[i - 1] == 'a' ? a-- : b--;
        str[j] == 'a' ? a++ : b++;
        if(min(a, b) <= k)
            return true;
    }
    return false;
}

void solve()
{
    int n, k;
    string str;
    cin>>n>>k>>str;
    int l = 0, r = str.lnt() + 1, mid;
    while(l + 1 < r)
    {
        mid = (l + r) / 2;
        if(good(mid, n, k, str))
            l = mid;
        else
            r = mid;
    }
    cout<<l;
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

-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/