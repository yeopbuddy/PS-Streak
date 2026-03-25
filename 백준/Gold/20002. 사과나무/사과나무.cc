#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int32_t N;
    
    cin >> N;

    vector<vector<int32_t>> Apple(N, vector<int32_t>(N));

    for (int32_t n = 0; n < N; n++) 
    {
        for (int32_t m = 0; m < N; m++)
        {
            cin >> Apple[n][m];
        }
    }


    for (int32_t n = 1; n < N; n++) 
    {
        Apple[n][0] += Apple[n - 1][0];
        Apple[0][n] += Apple[0][n - 1];
    }

    for (int32_t n = 1; n < N; n++)
    {
        for (int32_t m = 1; m < N; m++)
        {
            Apple[n][m] += (Apple[n][m - 1] + Apple[n - 1][m] - Apple[n - 1][m - 1]);
        }
    }

    int32_t ans = -1023;
    
    for (int32_t n1 = 0; n1 < N; n1++)
    {
        for (int32_t m1 = 0; m1 < N; m1++)
        {
            int32_t nm = 1;
            while (n1 + nm <= N && m1 + nm <= N) {

                ans = max(ans, Apple[n1 + nm - 1][m1 + nm - 1] - (n1 >= 1 ? Apple[n1 - 1][m1 + nm - 1] : 0) - (m1 >= 1 ? Apple[n1 + nm - 1][m1 - 1] : 0) + (n1 >= 1 && m1 >= 1 ? Apple[n1 - 1][m1 - 1] : 0));

                ++nm;
            }
        }
    }

    cout << ans;

    return 0;
}