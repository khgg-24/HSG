#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime;

void sieve(int n) {
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

int tong_chu_so(int s) {
    int d = 0;

    while (s > 0) {
        d += s % 10;
        s /= 10;
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("DOCAO.INP", "r", stdin);
    freopen("DOCAO.OUT", "w", stdout);

    int N, M, c = 0;
    cin >> N >> M;
    sieve(N);

    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            if (tong_chu_so(i) == M) {
                cout << i << "\n";
                c++;
            }
        }
    }

    cout << c << "\n";
    
    return 0;
}
