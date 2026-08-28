#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime;

void sieve_prime(int n) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void sub1(int N, int M, vector<int>& a) {
    sieve_prime(N * 10000);
    while (M--) {
        int X, Y;
        cin >> X >> Y;
        int sum = 0;

        for (int i = X; i <= Y; i++) {
            sum += a[i];
        }
        if (sum < 2)
            cout << 0 << '\n';
        else
            cout << is_prime[sum] << '\n';
    }
}

void sub2(int N, int M, vector<int>& a) {
    vector<int> pre(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    sieve_prime(N * 10000);

    while (M--) {
        int X, Y;
        cin >> X >> Y;
        int sum = pre[Y] - pre[X - 1];
        
        if (sum < 2)
            cout << 0 << '\n';
        else
            cout << is_prime[sum] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<int> a(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    if (M <= 100000) {
        sub1(N, M, a);
    }
    else {
        sub2(N, M, a);
    }

    return 0;
}