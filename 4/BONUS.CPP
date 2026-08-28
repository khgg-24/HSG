#include <bits/stdc++.h>
using namespace std;

long long solve_sub1(const vector<int>& a) {
    int n = a.size();
    long long total_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        int current_max = a[i];
        int current_min = a[i];
        
        for (int j = i; j < n; ++j) {
            current_max = max(current_max, a[j]);
            current_min = min(current_min, a[j]);
            total_sum += (current_max - current_min) * 1LL;
        }
    }
    
    return total_sum;
}
long long solve_sub2(const vector<int>& a) {

    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);

    int n;
    cin >> n;
    vector <int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    if (n <= (1e3)) {
        cout << solve_sub1(A) << "\n";
    }
    else {
        cout << solve_sub2(A) << "\n";
    }
    
    return 0;
}
