#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, T, n, m;
    int px, py, pd, ps, nx, ny, nd, ns;
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    cin >> N >> M >> T;
    
    vector<vector<int>> Castle(N, vector<int>(M));
    vector<vector<vector<int>>> Resque(N, vector<vector<int>>(M, vector<int>(2, 1e6)));
    
    for(n = 0; n < N; n++)
    {
        for(m = 0; m < M; m++)
        {
            cin >> Castle[n][m];
        }
    }

    deque<tuple<int, int, int, int>> dq;
    dq.push_back({0, 0, 0, 0});
    Resque[0][0][0] = 0;
    
    while(!dq.empty())
    {
        tie(px, py, pd, ps) = dq.front();
        dq.pop_front();
        
        if(pd == T || (px == N - 1 && py == M - 1))
        {
            continue;
        }
        
        for(int i = 0; i < 4; i++)
        {
            nx = px + dx[i];
            ny = py + dy[i];
            nd = pd + 1;
            
            if(0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if(Castle[nx][ny] == 0 && Resque[nx][ny][ps] > nd)
                {
                    Resque[nx][ny][ps] = nd;
                    dq.push_back({nx, ny, nd, ps});
                }
                else if(Castle[nx][ny] == 1 && ps == 1 && Resque[nx][ny][ps] > nd)
                {
                    Resque[nx][ny][ps] = nd;
                    dq.push_back({nx, ny, nd, ps});
                }
                else if(Castle[nx][ny] == 2 && ps == 0 && Resque[nx][ny][ps] > nd)
                {
                    Resque[nx][ny][ps] = nd;
                    Resque[nx][ny][ps + 1] = nd;
                    dq.push_back({nx, ny, nd, ps + 1});
                }
            }
        }
    }

    if(Resque[N - 1][M - 1][0] == 1e6 && Resque[N - 1][M - 1][1] == 1e6)
    {
        cout << "Fail";
    }
    else
    {
        cout << min(Resque[N - 1][M - 1][0], Resque[N - 1][M - 1][1]);
    }

    return 0;
}