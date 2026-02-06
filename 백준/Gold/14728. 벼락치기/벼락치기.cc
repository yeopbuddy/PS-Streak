#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> dp(T + 1, 0);

    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = T; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[T];
    return 0;
}