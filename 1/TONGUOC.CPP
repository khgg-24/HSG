#include <bits/stdc++.h>
using namespace std;

vector<long long> sum_div;

void sieve_divisors(int n) {
    sum_div.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            sum_div[j] += i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("TONGUOC.INP", "r", stdin);
    freopen("TONGUOC.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    int MAX = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > MAX) {
            MAX = a[i];
        }
    }

    sieve_divisors(MAX);

    for (int i = 0; i < n; i++) {
        cout << sum_div[a[i]] << " ";
    }

    return 0;
}