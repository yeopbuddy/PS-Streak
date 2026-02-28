#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> Origin;

void Shift(int i1, int i2) {
    vector<int> Tmp;
    for (int i = 0; i < i1; i++) {
        Tmp.push_back(Origin[i]);
    }
    Tmp.push_back(Origin[i2]);
    for (int i = i1; i < N; i++) {
        if (i == i2) continue;
        Tmp.push_back(Origin[i]);
    }
    Origin = Tmp;
}

int main() {

    cin >> N;
    
    Origin.resize(N);
    
    for (int i = 0; i < N; i++) cin >> Origin[i];
    
    cin >> S;

    for (int i = 0; i < N && S > 0; i++) {
        int max_val = Origin[i];
        int max_idx = i;

        for (int j = i + 1; j < N && j <= i + S; j++) {
            if (Origin[j] > max_val) {
                max_val = Origin[j];
                max_idx = j;
            }
        }

        if (max_idx != i) {
            S -= (max_idx - i);
            Shift(i, max_idx);
        }
    }

    for (int i = 0; i < N; i++) cout << Origin[i] << " ";

    return 0;
}