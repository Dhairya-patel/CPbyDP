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

bool good(ll x, string &str, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll ru)
{
    ll b = 0, s = 0, c = 0, needb = 0, needs = 0, needc = 0;
    for(int i=0;i<str.sz();i++)
    {
        if(str[i] == 'B')
            b++;
        else if(str[i] == 'S')
            s++;
        else
            c++;
    }
    needb = ((x * b) - nb) * pb;
    needs = ((x * s) - ns) * ps;
    needc = ((x * c) - nc) * pc;
    needb = max(needb, 0LL), needs = max(needs, 0LL), needc = max(needc, 0LL);
    return needb + needs + needc <= ru;
}

void solve()
{
    string str;
    ll nb, ns, nc, pb, ps, pc, ru;
    cin>>str>>nb>>ns>>nc>>pb>>ps>>pc>>ru;
    ll l = -1, r = 1e13, mid;
    while(l + 1 < r)
    {
        mid = (l + r) / 2LL;
        if(good(mid, str, nb, ns, nc, pb, ps, pc, ru))
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

-> if A task description is long, MUST READ it properly
-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/