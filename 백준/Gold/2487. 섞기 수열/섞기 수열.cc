// https://www.acmicpc.net/problem/2487

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long get_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long get_lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / get_gcd(a, b)) * b;
}

int main() {
    
    int n; cin >> n;
    vector<int> vec(n + 1);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++) cin >> vec[i];

    long long ans = 1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int curr = i;
            int cnt = 0;
            while (!vis[curr]) {
                vis[curr] = true;
                curr = vec[curr];
                cnt++;
            }
            ans = get_lcm(ans, (long long)cnt);
        }
    }

    cout << ans << endl;

    return 0;
}
