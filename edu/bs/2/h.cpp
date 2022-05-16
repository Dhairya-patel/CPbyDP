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

bool good(ll t, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll needb, ll needs, ll needc, ll r)
{
    ll needcost = (max(0LL, (t * needb) - nb) * pb) + (max(0LL, (t * needs) - ns) * ps) + (max(0LL, (t * needc) - nc) * pc);
    return needcost <= r;
}

void solve()
{
    string str;
    ll nb, ns, nc, pb, ps, pc, needb = 0, needs = 0, needc = 0, ru;
    cin>>str>>nb>>ns>>nc>>pb>>ps>>pc>>ru;
    for(int i=0;i<str.lnt();i++)
    {
        if(str[i] == 'B')   needb++;
        else if(str[i] == 'S')  needs++;
        else                needc++;
    }
    ll l = 0, r = 1e13, mid;
    while(l + 1 < r)
    {
        mid = (l + r) / 2;
        if(good(mid, nb, ns, nc, pb, ps, pc, needb, needs, needc, ru))
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