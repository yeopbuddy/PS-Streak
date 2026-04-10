#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int N, M, n, m, pc, px, py, nx, ny;
    
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // {비용, x, y}

    cin >> N >> M;

    vector<vector<int>> GridMap(N, vector<int>(M));
    vector<vector<int>> Cost(N, vector<int>(M, 1e7));

    for (n = 0; n < N; n++)
    {
        for (m = 0; m < M; m++)
        {
            cin >> GridMap[n][m];
        }
    }

    if (GridMap[0][0] == -1 || GridMap[N - 1][M - 1] == -1)
    {
        cout << -1;
        return 0;
    }

    Cost[0][0] = GridMap[0][0];
    pq.push({ Cost[0][0], 0, 0 });

    while (!pq.empty())
    {
        pc = get<0>(pq.top());
        px = get<1>(pq.top());
        py = get<2>(pq.top());
        
        pq.pop();

        if (pc > Cost[px][py]) continue; 

        for (int i = 0; i < 4; i++)
        {
            nx = px + dx[i];
            ny = py + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && GridMap[nx][ny] >= 0 && Cost[nx][ny] > Cost[px][py] + GridMap[nx][ny])
            {
                Cost[nx][ny] = Cost[px][py] + GridMap[nx][ny];
                pq.push({ Cost[nx][ny], nx, ny });
            }
        }
    }

    cout << (Cost[N - 1][M - 1] == (int)1e7 ? -1 : Cost[N - 1][M - 1]);
    return 0;
}