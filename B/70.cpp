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
    string str = "";
    while(n >= 7)
    {
        str += "ROYGBIV";
        //decision of sub based on how much u r adding, don't get confuse between sub and div
        n -= 7;     //num of letters appended into resulting str
    }
    if(n == 0)
    {
        cout<<str;
        return;
    }
    if(n < 4)
    {
        if(n == 1)
            str += "G";
        else if(n == 2)
            str += "GB";
        else
            str += "GBI";
    }
    else
    {
        if(n == 4)
            str += "ROYG";
        else if(n == 5)
            str += "ROYGB";
        else
            str += "ROYGBI";
    }
    cout<<str;
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

-> read the explanations below (MUST FOR GREEDY PROBS)
-> stuck with implementation ? => DO ROUGH WORK

*/