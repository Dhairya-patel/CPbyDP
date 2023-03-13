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
    string s, t;
    cin>>s>>t;
    int y = 0, w = 0;
    vector<int>pos;
    int hhs[26] = {0}, hht[26] = {0};
    for(int i=0;i<t.lnt();i++)
    {
        if(t[i] >= 'a' && t[i] <= 'z')
            hht[t[i] - 'a']++;
        else
            hhs[t[i] - 'A']++;
    }
    for(int i=0;i<s.lnt();i++)
    {
        pos.pb(i);
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(hht[s[i] - 'a'] > 0)
            {
                y++;
                hht[s[i] - 'a']--;
                pos.pop_back();
            }
        }
        else
        {
            if(hhs[s[i] - 'A'] > 0)
            {
                y++;
                hhs[s[i] - 'A']--;
                pos.pop_back();
            }
        }
    }
    for(int i=0;i<pos.sz();i++)
    {
        int temp = i;
        i = pos[i];
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(hhs[s[i] - 'a'] > 0)
            {
                w++;
                hhs[s[i] - 'a']--;
            }
        }
        else
        {
            if(hht[s[i] - 'A'] > 0)
            {
                w++;
                hht[s[i] - 'A']--;
            }
        }
        i = temp;
    }
    cout<<y<<" "<<w;
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