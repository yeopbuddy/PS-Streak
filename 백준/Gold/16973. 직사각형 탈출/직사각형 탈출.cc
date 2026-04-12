#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
    
    int N, M, H, W, Sx, Sy, Fx, Fy, n1, m1, n2, m2, px, py, nx, ny;

    cin >> N >> M;

    vector<vector<int>> Gridmap(N, vector<int>(M));
    vector<vector<int>> Dist(N, vector<int>(M, 1e6));

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    for(n1 = 0; n1 < N; n1++)
    {
        for(m1 = 0; m1 < M; m1++)
        {
            cin >> Gridmap[n1][m1];
        }
    }

    cin >> H >> W >> Sx >> Sy >> Fx >> Fy;

    --Sx; 
    --Sy;
    --Fx;
    --Fy;

    for(n1 = 0; n1 < N; n1++)
    {
        for(m1 = 0; m1 < M; m1++)
        {
            if(Gridmap[n1][m1] == 1)
            {
                for(n2 = max(0, n1 - H + 1); n2 <= n1; n2++)
                {
                    for(m2 = max(0, m1 - W + 1); m2 <= m1; m2++)
                    {
                        Dist[n2][m2] = -1;
                    }
                }
            }
        }
    }
    
    deque<pair<int, int>> dq;
    
    dq.push_back({Sx, Sy});
    Dist[Sx][Sy] = 0;
    
    while(!dq.empty())
    {
        px = dq.front().first;
        py = dq.front().second;
        
        dq.pop_front();
        
        for(n1 = 0; n1 < 4; n1++)
        {
            nx = px + dx[n1];
            ny = py + dy[n1];
            
            if(0 <= nx && nx < N - H + 1 && 0 <= ny && ny < M - W + 1 && Dist[nx][ny] != -1 && Dist[nx][ny] > Dist[px][py] + 1)
            {
                Dist[nx][ny] = Dist[px][py] + 1;
                dq.push_back({nx, ny});
            }
        }
        
    }
    
    if(Dist[Fx][Fy] == 1e6 || Dist[Fx][Fy] == -1)
    {
        cout << -1;
    }
    else
    {
        cout << Dist[Fx][Fy];
    }
    
    return 0;
}