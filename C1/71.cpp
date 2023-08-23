#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int &x: A)
        cin >> x;
    
    vector<int> divisors;
    for (int i = 1; i * 1LL * i <= n; i++) {
        if (n % i == 0) {
            if (i != n / i)
                divisors.push_back(n / i);
            divisors.push_back(i);
        }
    }

    bool ok = false;
    for(int d: divisors) {
        if (n / d < 3) continue;
        vector<int> offset_count(d);
        for (int i = 0; i < n; i++) {
            offset_count[i % d] += A[i];
        }
        for (int x: offset_count)
            ok |= x == n / d;
        if (ok) break;
    }

    cout << (ok ? "YES\n" : "NO\n");
}