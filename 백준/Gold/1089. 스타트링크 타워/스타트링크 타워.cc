#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {

    bool num[10][5][3];
    memset(num, false, sizeof(num));

    for (int i = 0; i < 5; i++)num[0][i][0] = num[0][i][2] = num[1][i][2] = num[3][i][2] = num[4][i][2] = num[6][i][0] = num[7][i][2] = num[8][i][0] = num[8][i][2] = num[9][i][2] = true;
    for (int j = 0; j < 3; j++)num[0][0][j] = num[0][4][j] = num[2][0][j] = num[2][2][j] = num[2][4][j] = num[3][0][j] = num[3][2][j] = num[3][4][j] = num[4][2][j] = num[5][0][j] = num[5][2][j] = num[5][4][j] = num[6][0][j] = num[6][2][j] = num[6][4][j] = num[7][0][j] = num[8][0][j] = num[8][2][j] = num[8][4][j] = num[9][0][j] = num[9][2][j] = num[9][4][j] = true;
    num[2][1][2] = num[2][3][0] = num[4][0][0] = num[4][1][0] = num[5][1][0] = num[5][3][2] = num[6][3][2] = num[9][1][0] = true;

    int N; cin >> N;

    bool possible = true;
    char arr[5][35];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 * N - 1; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> lights(N);

    for (int n = 0; n < N; n++) {
        vector<int> light;
        for (int nums = 0; nums < 10; nums++) {
            bool ok = true;
            for (int i = 0; i < 5; i++) {
                for (int j = 4 * n; j < 4 * n + 3; j++) {
                    if(!num[nums][i][j - 4 * n] && arr[i][j] == '#') ok = false;
                    if (!ok) break;
                }
                if (!ok) break;
            }
            if (ok) light.push_back(nums);            
        }
        if (light.empty()) possible = false;
        lights[n] = light;
    }

    if (!possible) {
        cout << -1;
    }
    else {
        double avg = 0.0;
        double pow10 = 1.0;

        for (int i = N - 1; i >= 0; i--) {
            double cursum = 0;
            for (int digit : lights[i]) {
                cursum += digit;
            }
            avg += (cursum / (double)lights[i].size()) * pow10;
            pow10 *= 10.0;
        }

        cout << avg;
    }

    return 0;
}