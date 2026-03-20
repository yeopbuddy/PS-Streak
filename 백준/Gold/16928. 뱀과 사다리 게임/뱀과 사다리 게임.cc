#include <iostream>
#include <deque>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;


    int a, b;
    int warp[101];
    int mindist[101];

    for (int i = 1; i <= 100; i++) {
        warp[i] = i;
        mindist[i] = 1e9;
    }

    for (int i = 0; i < N + M; i++) {
        cin >> a >> b;
        warp[a] = b;
    }

    mindist[1] = 0;
    deque<pair<int, int>> dq;
    dq.push_back({ 1, 0 });

    while (!dq.empty()) {

        int pn = dq.front().first;
        int pt = dq.front().second;
        dq.pop_front();

        for (int i = 1; i <= 6; i++) {
            int nn = pn + i;
            int nt = pt + 1;
            if (nn > 100) continue;
            if (warp[nn] != nn) { // 뱀, 사다리의 경우
                if (mindist[nn] > nt) mindist[nn] = nt;
                if (mindist[warp[nn]] > nt) {
                    mindist[warp[nn]] = nt;
                    dq.push_back({ warp[nn], nt });
                }
            }
            else if (mindist[nn] > nt) {
                mindist[nn] = nt;
                dq.push_back({ nn, nt });
            }
        }

    }

    cout << mindist[100];

    return 0;
}