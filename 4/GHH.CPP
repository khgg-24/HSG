#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
long long c[MAXN];

void build_sieve() {
    for (int i = 2; i < MAXN; i++) {
        c[i] = 1;
    }
    for (int i = 2; i <= MAXN / 2; i++) {
        for (int j = i * 2; j < MAXN; j += i) {
            c[j] += i;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("GHH.INP", "r", stdin);
    freopen("GHH.OUT", "w", stdout);

    build_sieve();
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        
        if (c[x] >= x) { 
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}
