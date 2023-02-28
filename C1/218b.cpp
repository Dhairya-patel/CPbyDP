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
    int a, b, ans = 0;
    cin>>a>>b;
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    while(a != b)
    {
        if(a > b)
        {
            if(a % 5 == 0)
                a /= 5;
            else if(a % 3 == 0)
                a /= 3;
            else if(a % 2 == 0)
                a /= 2;
            else
            {
                cout<<"-1";
                return;
            }
        }
        else
        {
            if(b % 5 == 0)
                b /= 5;
            else if(b % 3 == 0)
                b /= 3;
            else if(b % 2 == 0)
                b /= 2;
            else
            {
                cout<<"-1";
                return;
            }
        }
        ans++;
    }
    cout<<ans;
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