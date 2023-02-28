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
    cin>>n;
    string str, ans;
    cin>>str;
    for(int i=0;i<str.sz();i++)
    {
        switch(str[i] - '0')
        {
            case 0:
                break;
            case 1:
                break;
            case 2: 
                ans += "2";
                break;
            case 3:
                ans += "3";
                break;
            case 4:
                ans += "322";
                break;
            case 5:
                ans += "5";
                break;
            case 6:
                ans += "53";
                break;
            case 7: 
                ans += "7";
                break;
            case 8:
                ans += "7222";
                break;
            case 9:
                ans += "7332";
                break;
        }
    }
    sort(allr(ans));
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