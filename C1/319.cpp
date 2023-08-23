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

bool prime[100005];

void fill()
{
    setv(prime, true);
    prime[0] = prime[1] = false;
    for(int i=2;i*i<=1e5;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=1e5;j+=i)
                prime[j] = false;
        }
    }
}

bool isprime(int x)
{
    return prime[x];
}

bool isexpo(int x)
{
    for(int i=2;i < x;i++)
    {
        if(prime[i])
        {
            int temp = x;
            while(temp % i == 0)
                temp /= i;
            if(temp == 1)
                return true;
        }
    }
    return false;
}

void solve()
{
    fill();
    int n;
    cin>>n;
    vector<int>v;
    for(int i=2;i<=n;i++)
    {
        if(isprime(i))
            v.pb(i);
        else if(isexpo(i))
            v.pb(i);
    }
    cout<<v.sz()<<endl;
    for(int i=0;i<v.sz();i++)
        cout<<v[i]<<" ";
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