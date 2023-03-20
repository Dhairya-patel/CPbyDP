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
    vector<ll>arr;
    int s;

    void init(int n)
    {
        s = 1;
        while(s < n)
            s *= 2;
        arr.assign(s * 2, 0LL);
    }

    void build(vector<int> &v, int i, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            //  base condition - segment of length 1 that means you are leaf node to seg tree
            if(lx < v.sz())
                arr[i] = v[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(v, 2 * i + 1, lx, mid);   //  build for left subtree
        build(v, 2 * i + 2, mid, rx);   //  build for right subtree
        arr[i] = arr[2 * i + 1] + arr[2 * i + 2];   //  sum of left subtree + right subtree = value of current node
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
            //  base condition
            arr[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);
        arr[x] = arr[2 * x + 1] + arr[2 * x + 2];   //  update the sum for current node
        return;
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, s);
    }

    //  lx - rx => current segment
    //  l - r => target segment/input segment
    ll sum(int l, int r, int x, int lx, int rx)
    {
        if(rx <= l || r <= lx)  //  current segment not in target segment
            return 0LL;
        if(lx >= l && r >= rx)  //  current segment completely in target segment
            return arr[x];
        //  current segment partially in target segment
        int mid = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);
    }

    ll sum(int l, int r)
    {
        return sum(l, r, 0, 0, s);
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
            //  operstion to set val
            int ind, val;
            cin>>ind>>val;
            st.set(ind, val);
        }
        else if(op == 2)
        {
            //  operation to get the sum for l - r
            int l, r;
            cin>>l>>r;
            cout<<st.sum(l, r)<<endl;
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