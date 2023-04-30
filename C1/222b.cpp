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
    vector<int>a(n), b(n);
    for(int i=0;i < n;i++)
        cin>>a[i], cin>>b[i];
    string str1, str2;
    for(int i=0;i<n;i++)
        str1.pb('0'), str2.pb('0');
    //  k = 0
    for(int i=0, j=0;i < n && j < n && i + j < n;)
    {
        if(a[i] < b[j])
        {
            str1[i] = '1';
            if(i + 1 + j < n)
            {
                str2[j] = '1';
                j++;
            }
            i++;
        }
        else
        {
            str2[j] = '1';
            if(i + 1 + j < n)
            {
                str1[i] = '1';
                i++;
            }
            j++;
        }
    }
    //  k = n / 2
    for(int i=0,j=0;i + j < n && i < n && j < n;)
    {
        if(a[i] < b[j])
            str1[i] = '1', i++;
        else
            str2[j] = '1', j++;
    }
    cout<<str1<<endl<<str2;
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