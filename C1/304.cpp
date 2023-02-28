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

ll factorial(ll x)
{
    ll f = 1;
    while(x > 1)
    {
        f *= x;
        x--;
    }
    return f;
}

void solve()
{
    int n, a, b;
    ll cnt = 0;
    cin>>n;
    queue<int>q1, q2, u1, u2;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        int x;
        cin>>x;
        q1.push(x);
        u1.push(x);
    }
    cin>>b;
    for(int i=0;i<b;i++)
    {
        int x;
        cin>>x;
        q2.push(x);
        u2.push(x);
    }
    int s1 = q1.size(), s2 = q2.size();
    ll mx = factorial(s1 + s2);
    while(!q1.empty() && !q2.empty())
    {
        int x = q1.front(), y = q2.front();
        q1.pop(), q2.pop();
        if(x > y)
            q1.push(y), q1.push(x);
        else
            q2.push(x), q2.push(y);
        cnt++;
        if(cnt > mx)
        {
            cout<<"-1";
            return;
        }
    }
    cout<<cnt<<" "<<(q1.empty() ? "2" : "1");
    return;
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