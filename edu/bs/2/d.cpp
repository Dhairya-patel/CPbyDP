#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pii pair<int, int>
#define inf 1e9 
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define maxn 100000+5
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

struct assistant{ll t, z, y;};

bool check(const std::vector<assistant> &a, ll m, ll x){
    ll cnt(0);
    for(long p = 0; p < a.sz(); p++){
        ll bt = a[p].t * a[p].z + a[p].y;
        ll bn = x / bt;
        ll rn = (x % bt); rn = (rn < a[p].t * a[p].z) ? rn : a[p].t * a[p].z;
        ll num = bn * a[p].z + rn / a[p].t;
        cnt += num;
        if(cnt >= m){return true;}
    }

    return false;
}

int main(){

    ll m, n; scanf("%lld %lld", &m, &n);
    std::vector<assistant> a(n);
    for(ll p = 0; p < n; p++){scanf("%lld %lld %lld", &a[p].t, &a[p].z, &a[p].y);}
    ll left(0), right(1e18), res(0);
    while(left <= right){
        ll mid = (left + right) / 2;
        if(check(a, m, mid)){res = mid; right = mid - 1;}
        else{left = mid + 1;}
    }

    printf("%lld\n", res);
    ll rem(m);
    for(long p = 0; p < a.sz(); p++){
        ll bt = a[p].t * a[p].z + a[p].y;
        ll bn = res / bt;
        ll rn = (res % bt); rn = (rn < a[p].t * a[p].z) ? rn : a[p].t * a[p].z;
        ll num = bn * a[p].z + rn / a[p].t;
        num = (num < rem) ? num : rem;
        rem -= num;
        printf("%lld ", num);
    }
    puts("");
    
    return 0;
}