#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, M, n, m;

    cin >> N >> M;

    vector<vector<char>> Road(N, vector<char>(M));
    vector<vector<string>> Way(N, vector<string>(M));

    for (n = 0; n < N; n++)
    {
        for (m = 0; m < M; m++)
        {
            cin >> Road[n][m];
        }
    }

    for (m = 0; m < M; m++)
    {
        if (Road[0][m] == '_')
        {
            if (m - 1 >= 0 && Road[1][m - 1] == '_' && Way[1][m - 1].empty())
            {
                Way[1][m - 1] = to_string(m + 1) + "L";
            }
            if (Road[1][m] == '_' && Way[1][m].empty())
            {
                Way[1][m] = to_string(m + 1) + "F";
            }
            if (m + 1 < M && Road[1][m + 1] == '_' && Way[1][m + 1].empty())
            {
                Way[1][m + 1] = to_string(m + 1) + "R";
            }
        }
    }


    for (n = 1; n < N - 1; n++)
    {
        for (m = 0; m < M; m++)
        {
            if (Road[n][m] == '_' && !Way[n][m].empty())
            {
                if (m - 1 >= 0 && Road[n + 1][m - 1] == '_' && Way[n + 1][m - 1].empty())
                {
                    Way[n + 1][m - 1] = Way[n][m] + "L";
                }
                if (Road[n + 1][m] == '_' && Way[n + 1][m].empty())
                {
                    Way[n + 1][m] = Way[n][m] + "F";
                }
                if (m + 1 < M && Road[n + 1][m + 1] == '_' && Way[n + 1][m + 1].empty())
                {
                    Way[n + 1][m + 1] = Way[n][m] + "R";
                }
            }
        }
    }

    for (m = 0; m < M; m++)
    {
        if (!Way[N - 1][m].empty())
        {
            bool enter = false;
            n = 0;

            while (n != Way[N - 1][m].size())
            {
                if ('0' <= Way[N - 1][m][n] && Way[N - 1][m][n] <= '9')
                {
                    cout << Way[N - 1][m][n];
                }
                else
                {
                    if (!enter)
                    {
                        cout << "\n";
                        enter = true;
                    }
                    cout << Way[N - 1][m][n];
                }
                ++n;
            }
            return 0;
        }
    }

    cout << "impossible";

    return 0;
}