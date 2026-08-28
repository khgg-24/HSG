#include <bits/stdc++.h>
using namespace std;

vector <int> is_prime;

void sang_nto(long long N) {
    is_prime.assign(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void ktra(long long A, long long B) {
    long long start = ceil(sqrt(A));
    long long end = sqrt(B);
    long long dem = 0;
    sang_nto(end);
    
    for (long long i = start; i <= end; i++) {
        if (is_prime[i]) {
            dem++;
        }
    }

    cout << dem << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("CP.INP", "r", stdin);
    freopen("CP.OUT", "w", stdout);

    long long a, b;
    cin >> a >> b;

    ktra(a, b);

    return 0;
}