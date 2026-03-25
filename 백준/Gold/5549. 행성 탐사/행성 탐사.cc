#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int32_t N, M, K;
    
    cin >> N >> M >> K;

    vector<vector<char>> Map(N, vector<char>(M));

    for (int32_t n = 0; n < N; n++) 
    {
        for (int32_t m = 0; m < M; m++) 
        {
            cin >> Map[n][m];
        }
    }

    vector<vector<vector<int32_t>>> PrefixMap(N, vector<vector<int32_t>>(M, vector<int32_t>(3, 0)));

    if (Map[0][0] == 'J') 
    {
        ++PrefixMap[0][0][0];
    }
    else if (Map[0][0] == 'O') 
    {
        ++PrefixMap[0][0][1];
    }
    else 
    {
        ++PrefixMap[0][0][2];
    }

    for (int32_t n = 1; n < N; n++) 
    {
        if (Map[n][0] == 'J')
        {
            ++PrefixMap[n][0][0];
        }
        else if (Map[n][0] == 'O')
        {
            ++PrefixMap[n][0][1];
        }
        else
        {
            ++PrefixMap[n][0][2];
        }
        for (int32_t t = 0; t < 3; t++) 
        {
            PrefixMap[n][0][t] += PrefixMap[n - 1][0][t];
        }
    }

    for (int32_t m = 1; m < M; m++) {
        if (Map[0][m] == 'J')
        {
            ++PrefixMap[0][m][0];
        }
        else if (Map[0][m] == 'O')
        {
            ++PrefixMap[0][m][1];
        }
        else
        {
            ++PrefixMap[0][m][2];
        }
        for (int32_t t = 0; t < 3; t++)
        {
            PrefixMap[0][m][t] += PrefixMap[0][m - 1][t];
        }
    }

    for (int32_t n = 1; n < N; n++)
    {
        for (int32_t m = 1; m < M; m++)
        {
            if (Map[n][m] == 'J')
            {
                ++PrefixMap[n][m][0];
            }
            else if (Map[n][m] == 'O')
            {
                ++PrefixMap[n][m][1];
            }
            else
            {
                ++PrefixMap[n][m][2];
            }
            for (int32_t t = 0; t < 3; t++)
            {
                PrefixMap[n][m][t] += (PrefixMap[n][m - 1][t] + PrefixMap[n - 1][m][t] - PrefixMap[n - 1][m - 1][t]);
            }
        }
    }

    int32_t a, b, c, d;
    
    for (int32_t k = 0; k < K; k++)
    {    
        cin >> a >> b >> c >> d;
        for (int32_t t = 0; t < 3; t++)
        {
            cout << (PrefixMap[c - 1][d - 1][t]) - (a >= 2 ? PrefixMap[a - 2][d - 1][t] : 0) - (b >= 2 ? PrefixMap[c - 1][b - 2][t] : 0) + (a >= 2 && b >= 2 ? PrefixMap[a - 2][b - 2][t] : 0) << " ";
        }
        cout << "\n";
    } 
    return 0;
}