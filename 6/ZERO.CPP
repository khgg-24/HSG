#include <bits/stdc++.h>
using namespace std;

void sub1(long long n) {
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long Q = 0;
    for (long long l = 0; l < n; l++) {
        long long sum = 0;
        for (long long r = l; r < n; r++) {
            sum += a[r];

            if (sum == 0) {
                Q = max(Q, r - l + 1);
            }
        }
    }
    
    cout << Q << "\n";
}

void sub2(long long n) {
    map<long long, long long> mp;
    long long sum = 0;
    long long Q = 0;
    mp[0] = 0;
    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        sum += x;
        if (mp.count(sum)) {
            Q = max(Q, i - mp[sum]);
        }
        else {
            mp[sum] = i;
        }
    }

    cout << Q << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("ZERO.INP", "r", stdin);
    freopen("ZERO.OUT", "w", stdout);

    long long N;
    cin >> N;
    if (N <= 3000) {
        sub1(N);
    }
    else {
        sub2(N);
    }

    return 0;
}