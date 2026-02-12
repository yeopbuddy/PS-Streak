#include <iostream>

using namespace std;

bool grid[101][101];

// 0이 오른쪽, 1이 위쪽, 2가 왼쪽, 3이 아래쪽

int dragoncurve[11][4][1024];

int curvelen[11];

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

void Preprocessing(){
    
    curvelen[0] = 1;
    
    for(int i = 1; i < 11; i++) curvelen[i] = curvelen[i - 1] * 2;
    
    // 0세대 드래곤 커브
    for(int i = 0; i < 4; i++) dragoncurve[0][i][0] = i;
        
    for(int i = 1; i < 11; i++){ // 세대
        for(int j = 0; j < 4; j++){ // 방향
            int idx = 0;
            for(int k = 0; k < curvelen[i - 1]; k++){ // 이전 세대 그대로
                dragoncurve[i][j][idx++] = dragoncurve[i - 1][j][k];
            }
            for(int k = curvelen[i - 1] - 1; k >= 0; k--){ // 이전 세대에서 변환. 우 -> 상, 상 -> 좌, 좌 -> 하, 하 -> 우
                dragoncurve[i][j][idx++] = (dragoncurve[i - 1][j][k] + 1) % 4;
            }
        }
    }
}

int main(){
    
    Preprocessing();

    int N, x, y, d, g;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> x >> y >> d >> g;
        
        grid[y][x] = true;
        
        for(int j = 0; j < curvelen[g]; j++){
            x += dy[dragoncurve[g][d][j]]; y += dx[dragoncurve[g][d][j]];
            grid[y][x] = true;
        }
        
        // cout << "\n==========\n";
        // for(int a = 0; a < 10; a++){
        //     for(int b = 0; b < 10; b++){
        //         cout << grid[b][a] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n==========\n";
    }
    
    int ans = 0;
    
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) ans++;
        }
    }

    cout << ans;

    return 0;
}