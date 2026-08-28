#include <bits/stdc++.h>
using namespace std;

vector <long long> sum_div;

void sieve_divisors(int n) {
    sum_div.assign(n + 1, 0);
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            sum_div[j] += i;
        }
    }
}

void kqua(vector <int> &a) {
    long long MAX = *max_element(a.begin(), a.end());
    sieve_divisors(MAX);
    int dem = 0;
    vector <int> ans;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == sum_div[a[i]]) {
            dem++;
            ans.push_back(a[i]);
        }
    }

    cout << dem << "\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("QUA.INP", "r", stdin);
    freopen("QUA.OUT", "w", stdin);

    int N;
    cin >> N;
    vector <int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    kqua(A);

    return 0;
}
