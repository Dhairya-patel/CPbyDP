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
    char ch;
    string str;
    cin>>n>>ch>>str;
    if(ch == 'g')
    {
        cout<<"0"<<endl;
        return;
    }
    vector<int>posr, posy, posg;
    for(int i=0;i<n;i++)
    {
        if(str[i] == 'r')
            posr.pb(i);
        else if(str[i] == 'y')
            posy.pb(i);
        else
            posg.pb(i);
    }
    if(posg.sz() == 0)
    {
        cout<<"-1"<<endl;
        return;
    }
    int ans = 0;
    if(ch == 'r')
    {
        for(int i=0;i<posr.sz();i++)
        {
            int pos = posr[i];
            // cout<<pos<<" : ";
            int l = -1, r = posg.sz(), mid;
            while(l + 1 < r)
            {
                mid = (l + r) / 2;
                if(posg[mid] >= pos)
                    r = mid;
                else
                    l = mid;
            }
            if(r != posg.sz())
            {
                ans = max(ans, posg[r] - pos);
                // cout<<r<<", "<<posg[r] - pos<<endl;
            }
            else
            {
                ans = max(ans, n - pos + posg[0]);
                // cout<<r<<", "<<n - pos + posg[0]<<endl;
            }
        }
    }
    else
    {
        for(int i=0;i<posy.sz();i++)
        {
            int pos = posy[i];
            int l = -1, r = posg.size(), mid;
            while(l + 1 < r)
            {
                mid = (l + r) / 2;
                if(posg[mid] >= pos)
                    r = mid;
                else
                    l = mid;
            }
            if(r != posg.sz())
            {
                ans = max(ans, posg[r] - pos);
                // cout<<r<<", "<<r - pos<<endl;
            }
            else
            {
                ans = max(ans, n - pos + posg[0]);
                // cout<<r<<", "<<n - pos + r<<endl;
            }
        }
    }
    cout<<ans<<endl;
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