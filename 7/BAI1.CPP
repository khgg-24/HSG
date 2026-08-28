#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);

    long long N;
    cin >> N;
    long long dem = 0;

    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            if (i * i == N)
                dem++;
            else
                dem += 2;
        }
    }
    
    cout << dem << "\n";

    return 0;
}