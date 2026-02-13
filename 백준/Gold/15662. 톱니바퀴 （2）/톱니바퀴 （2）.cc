#include <iostream>
#include <deque>

using namespace std;

int main() {

    int t, k, n, d;

    cin >> t;

    deque<deque<char>> dq(t, deque<char>(8));

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> dq[i][j];
        }
    }

    cin >> k;

    for (int i = 0; i < k; i++) {

        cin >> n >> d;

        int lp = n - 2;
        int rp = n; // 2 pointer

        deque<pair<int, int>> rot;
        rot.push_back({ n - 1, d });

        int dd = -d;

        while (lp >= 0) {
            if (dq[lp][2] != dq[lp + 1][6])
                rot.push_back({ lp--, dd });
            else break;
            dd *= -1;
        }

        dd = -d;

        while (rp < t) {
            if (dq[rp - 1][2] != dq[rp][6])
                rot.push_back({ rp++, dd });
            else break;
            dd *= -1;
        }

        for (size_t j = 0; j < rot.size(); j++) {

            char h = dq[rot[j].first][0];
            char b = dq[rot[j].first][7];

            if (rot[j].second == 1) {
                dq[rot[j].first].pop_back();
                dq[rot[j].first].push_front(b);
            }
            else {
                dq[rot[j].first].pop_front();
                dq[rot[j].first].push_back(h);
            }

            int bp = -404;
        }

        // cout << "\n==========\n";
        // for (int i = 0; i < t; i++) {
        //     for (int j = 0; j < 8; j++) {
        //         cout << dq[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n==========\n";
    }

    int ans = 0;

    for (int i = 0; i < t; i++) {
        if (dq[i][0] == '1') ++ans;
    }

    cout << ans;

    return 0;
}