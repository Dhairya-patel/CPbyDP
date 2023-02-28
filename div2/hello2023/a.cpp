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
    int n, l = 0, r = 0, rpos = INT_MAX, lpos = -1, flag = 0;
    string str;
    cin>>n>>str;
    for(int i=0;i<n;i++)
    {
        if(!flag)
        {
            // in search of R
            if(str[i] == 'R')
                flag = 1;
        }
        else if(flag == 1)
        {
            // in search of L
            if(str[i] == 'L')
                flag = 2;
        }
        else
        {
            cout<<"0"<<endl;
            return;
        }
        if(i < n - 1 && str[i] == 'L' && str[i + 1] == 'R')
            lpos = i, rpos = i + 1;
        if(str[i] == 'R')
            r++;
        else
            l++;
    }
    if(l && r)
    {
        cout<<lpos + 1<<endl;
        return;
    }
    else
    {
        cout<<"-1"<<endl;
        return;
    }
}

int main()
{
    fio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin>>t;
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