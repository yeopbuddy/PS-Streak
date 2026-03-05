#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++){
        int n, m, k;
        cin >> n >> m >> k;
        vector<long long> moneys(n);
        for(int i = 0; i < n; i++) cin >> moneys[i];
        int cnt = 0;
        int cur = 0;
        for(int i = 0; i < m; i++) cur += moneys[i];
        if (cur < k) cnt++;
        for(int i = 1; i < n && m != n; i++){
            cur -= moneys[i - 1];
            cur += moneys[(i + m - 1) % n];
            if (cur < k) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}