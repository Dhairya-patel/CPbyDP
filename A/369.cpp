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
    string str;
    char mat[n][5];
    bool f = false;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        for(int j=0;j<5;j++)
            mat[i][j] = str[j];
        if(!f)
        {
            if(str[0] == str[1] && str[0] == 'O')
            {
                f = true;
                mat[i][0] = mat[i][1] = '+';
            }
            else if(str[3] == str[4] && str[3] == 'O')
            {
                f = true;
                mat[i][3] = mat[i][4] = '+';
            }
        }
    }
    if(!f)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
            cout<<mat[i][j];
        cout<<endl;
    }
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