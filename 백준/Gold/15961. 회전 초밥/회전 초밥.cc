#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N, D, K, C;
    cin >> N >> D >> K >> C;

    vector<int> sushi(N);
    vector<int> number(D + 1, 0);

    for (int i = 0; i < N; i++) cin >> sushi[i];

    int c_kind = 0;

    for (int i = 0; i < K; i++) {
        if (number[sushi[i]] == 0) c_kind++;
        number[sushi[i]]++;
    }

    int m_kind = c_kind;
    if (number[C] == 0) m_kind = c_kind + 1;

    for (int i = 0; i < N; i++) {
        int oidx = i;
        number[sushi[oidx]]--;
        if (number[sushi[oidx]] == 0) c_kind--;

        int iidx = (i + K) % N;
        if (number[sushi[iidx]] == 0) c_kind++;
        number[sushi[iidx]]++;

        int total = c_kind;
        if (number[C] == 0) total++;

        if (m_kind < total) {
            m_kind = total;
        }

        if (m_kind == K + 1) break;
    }

    cout << m_kind << "\n";

    return 0;
}