#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;

    cin >> N;

    vector<vector<char>> Map(N, vector<char>(N));
    vector<vector<vector<int>>> Num(N, vector<vector<int>>(N, vector<int>(2, 0)));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Map[i][j];

            if (((i + j) % 2) == 0)
            {
                Num[i][j][0] = Map[i][j] - '0';
                Num[i][j][1] = Map[i][j] - '0';
            }
        }
    }

    for (int i = 0; i < N; i++) {

        if (i + 2 >= N)
        {
            break;
        }

        if (Map[i + 1][0] == '+')
        {
            Num[i + 2][0][0] += Num[i][0][0];
            Num[i + 2][0][1] += Num[i][0][1];
        }
        else if (Map[i + 1][0] == '*')
        {
            Num[i + 2][0][0] *= Num[i][0][0];
            Num[i + 2][0][1] *= Num[i][0][1];
        }
        else
        {
            Num[i + 2][0][0] = Num[i][0][0] - Num[i + 2][0][0];
            Num[i + 2][0][1] = Num[i][0][1] - Num[i + 2][0][1];
        }
    }

    for (int j = 0; j < N; j++) {
        if (j + 2 >= N)
        {
            break;
        }

        if (Map[0][j + 1] == '+')
        {
            Num[0][j + 2][0] += Num[0][j][0];
            Num[0][j + 2][1] += Num[0][j][1];
        }
        else if (Map[0][j + 1] == '*')
        {
            Num[0][j + 2][0] *= Num[0][j][0];
            Num[0][j + 2][1] *= Num[0][j][1];
        }
        else
        {
            Num[0][j + 2][0] = Num[0][j][0] - Num[0][j + 2][0];
            Num[0][j + 2][1] = Num[0][j][1] - Num[0][j + 2][1];
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {

            if (((i + j) % 2) != 0)
            {
                continue;
            }

            int val1_max = -1023;
            int val2_max = -1023;
            int val3_max = -1023;
            int val4_max = -1023;

            int val1_min = 1024;
            int val2_min = 1024;
            int val3_min = 1024;
            int val4_min = 1024;

            if (j - 2 >= 0)  // 1. 좌2
            {
                if (Map[i][j - 1] == '+')
                {
                    val1_max = Num[i][j - 2][0] + Num[i][j][0];
                    val1_min = Num[i][j - 2][1] + Num[i][j][1];
                }
                else if (Map[i][j - 1] == '*')
                {
                    val1_max = Num[i][j - 2][0] * Num[i][j][0];
                    val1_min = Num[i][j - 2][1] * Num[i][j][1];
                }
                else
                {
                    val1_max = Num[i][j - 2][0] - Num[i][j][0];
                    val1_min = Num[i][j - 2][1] - Num[i][j][1];
                }
            }
            if (i - 2 >= 0) // 2. 상2
            {
                if (Map[i - 1][j] == '+')
                {
                    val2_max = Num[i - 2][j][0] + Num[i][j][0];
                    val2_min = Num[i - 2][j][1] + Num[i][j][1];
                }
                else if (Map[i - 1][j] == '*')
                {
                    val2_max = Num[i - 2][j][0] * Num[i][j][0];
                    val2_min = Num[i - 2][j][1] * Num[i][j][1];
                }
                else
                {
                    val2_max = Num[i - 2][j][0] - Num[i][j][0];
                    val2_min = Num[i - 2][j][1] - Num[i][j][1];
                }
            }
            if (i - 1 >= 0 && j - 1 >= 0) // 3, 4. 좌1 상1 / 상1 좌1
            {
                if (Map[i][j - 1] == '+')
                {
                    val3_max = Num[i - 1][j - 1][0] + Num[i][j][0];
                    val3_min = Num[i - 1][j - 1][1] + Num[i][j][1];
                }
                else if (Map[i][j - 1] == '*')
                {
                    val3_max = Num[i - 1][j - 1][0] * Num[i][j][0];
                    val3_min = Num[i - 1][j - 1][1] * Num[i][j][1];
                }
                else
                {
                    val3_max = Num[i - 1][j - 1][0] - Num[i][j][0];
                    val3_min = Num[i - 1][j - 1][1] - Num[i][j][1];
                }
                if (Map[i - 1][j] == '+')
                {
                    val4_max = Num[i - 1][j - 1][0] + Num[i][j][0];
                    val4_min = Num[i - 1][j - 1][1] + Num[i][j][1];
                }
                else if (Map[i - 1][j] == '*')
                {
                    val4_max = Num[i - 1][j - 1][0] * Num[i][j][0];
                    val4_min = Num[i - 1][j - 1][1] * Num[i][j][1];
                }
                else
                {
                    val4_max = Num[i - 1][j - 1][0] - Num[i][j][0];
                    val4_min = Num[i - 1][j - 1][1] - Num[i][j][1];
                }
            }
            Num[i][j][0] = max(max(val1_max, val2_max), max(val3_max, val4_max));
            Num[i][j][1] = min(min(val1_min, val2_min), min(val3_min, val4_min));
        }
    }
    cout << Num[N - 1][N - 1][0] << " " << Num[N - 1][N - 1][1];
}