#include <vector>
#include <deque>
#define INIT_VAL 16384;
using namespace std;

int solution(vector<vector<int>> as32_maps)
{
    int s32_answer = -1;
    
    // maps의 0을 모두 -1로 처리(도달 불가능하도록)
    // (0, 0)에서 시작해서 (n, m)까지 bfs로 이동하며, 거리를 maps에 기록하여 방문처리
    // 모두 수행했는데 maps[n][m] == 0이면 -1, 아니면 maps[n][m] 반환
    
    int s32_width = as32_maps[0].size();
    int s32_height = as32_maps.size();
    
    int s32_x;
    int s32_y;
    
    deque<pair<int, int>> as64_dq;
    
    int as32_dx[4] = {0,0,1,-1};
    int as32_dy[4] = {1,-1,0,0};
    
    int s32_px;
    int s32_py;
    
    int s32_i;
    
    int s32_nx;
    int s32_ny;
    
    for(s32_x = 0; s32_x < s32_height; s32_x++)
    {
        for(s32_y = 0; s32_y < s32_width; s32_y++)
        {
            if(as32_maps[s32_x][s32_y] == 1)
            {
                as32_maps[s32_x][s32_y] = INIT_VAL;
            }
            else
            {
                as32_maps[s32_x][s32_y] = -1;
            }
        }
    }
    
    as64_dq.push_back({0, 0});
    as32_maps[0][0] = 1;
    
    while(!as64_dq.empty())
    {
        s32_px = as64_dq.front().first;
        s32_py = as64_dq.front().second;
        
        as64_dq.pop_front();
        
        if(s32_px == s32_height - 1 && s32_py == s32_width - 1)
        {
            s32_answer = as32_maps[s32_px][s32_py];
            break;
        }
        
        for(s32_i = 0; s32_i < 4; s32_i++)
        {
            s32_nx = s32_px + as32_dx[s32_i];
            s32_ny = s32_py + as32_dy[s32_i];
            
            if(0 <= s32_nx && s32_nx < s32_height && 0 <= s32_ny && s32_ny < s32_width && 
               as32_maps[s32_nx][s32_ny] != -1 && as32_maps[s32_nx][s32_ny] > 
                as32_maps[s32_px][s32_py] + 1)
            {
                as64_dq.push_back({s32_nx, s32_ny});
                as32_maps[s32_nx][s32_ny] = as32_maps[s32_px][s32_py] + 1;
            }
        }
    }
    
    return s32_answer;
}