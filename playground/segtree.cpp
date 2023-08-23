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

struct segtree {

    int s;
    vector<int> mn;

    void init(int n)
    {
        s = 1;
        while(s < n)
            s *= 2;
        mn.resize(s * 2, inf);
    }

    void build(vector<int> &v, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < (int) v.sz())
                mn[x] = v[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
        return;
    }

    void build(vector<int> &v)
    {
        build(v, 0, 0, s);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            mn[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m)
            set(i, v, 2 * x + 1, lx, m);
        else    
            set(i, v, 2 * x + 2, m, rx);
        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
        return;
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, s);
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        if(rx <= l || lx >= r)
            return inf;
        if(lx >= l && rx <= r)
            return mn[x];
        int m = (lx + rx) / 2;
        return min(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }

    int get(int l, int r)
    {
        return get(l, r, 0, 0, s);
    }

};

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    segtree st;
    st.init(n);
    st.build(v);
    while(m--)
    {
        int op;
        cin>>op;
        if(op == 1)
        {
            //  set element
            int i, val;
            cin>>i>>val;
            st.set(i, val);
        }
        else if(op == 2)
        {
            // get min element in the segment
            int l, r;
            cin>>l>>r;
            cout<<st.get(l, r)<<endl;
        }
    }
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