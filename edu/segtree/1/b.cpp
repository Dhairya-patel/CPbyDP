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

struct segtree
{
    int sze;
    vector<int>v;

    void init(int n)
    {
        sze = 1;
        while(sze < n)  sze *= 2;
        v.assign(sze * 2, INT_MAX);
    }

    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < arr.sz())
                v[x] = arr[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        v[x] = min(v[2 * x + 1], v[2 * x + 2]);
        return;
    }

    void build(vector<int> &arr)
    {
        build(arr, 0, 0, sze);
    }

    void set(int i, int val, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            v[x] = val;
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < mid)
            set(i, val, 2 * x + 1, lx, mid);
        else
            set(i, val, 2 * x + 2, mid, rx);
        v[x] = min(v[2 * x + 1], v[2 * x + 2]);
        return;
    }

    void set(int i, int val)
    {
        set(i, val, 0, 0, sze);
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        if(lx >= r || rx <= l)
            return INT_MAX;
        if(lx >= l && rx <= r)
            return v[x];
        int mid = (lx + rx) / 2;
        return min(get(l, r, 2 * x + 1, lx, mid), get(l, r, 2 * x + 2, mid, rx));
    }

    int get(int l, int r)
    {
        return get(l, r, 0, 0, sze);
    }
};

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    segtree st;
    st.init(n);
    st.build(v);

    for(int i=0;i<m;i++)
    {
        int op;
        cin>>op;
        if(op == 1)
        {
            //  set
            int ind, val;
            cin>>ind>>val;
            st.set(ind, val);
        }
        else if(op == 2)
        {
            //  min
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