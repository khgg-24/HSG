#include <bits/stdc++.h>
using namespace std;

void sub1(int N, int L, int R, vector<int>& A) {
    int min_val = 2e9 + 7;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int cur_val = A[i] + A[j];
            if (cur_val >= L && cur_val <= R) {
                min_val = min(min_val, cur_val);
            }
        }
    }

    cout << min_val;
}

void sub2(int N, int L, int R, vector<int>& A) {

    sort(A.begin(), A.end());
    int min_val = 2e9 + 7; 
    
    for (int i = 0; i < N - 1; i++) {
        int target = L - A[i];
        auto it = lower_bound(A.begin() + i + 1, A.end(), target);
        
        if (it != A.end()) {
            int cur_val = A[i] + *it;
            if (cur_val <= R) {
                min_val = min(min_val, cur_val);
            }
        }
    }

    cout << min_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;

    freopen("MUASAM.INP", "r", stdin);
    freopen("MUASAM.OUT", "w", stdout);

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (N <= 1000) {
        sub1(N, L, R, A);
    } else {
        sub2(N, L, R, A);
    }

    return 0;
}