#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int Score = 0;
int N, M;

vector<vector<int>> GameBoard;
vector<pair<int, int>> MaxGroup;

void Setup(){
    GameBoard.resize(N, vector<int>(N));
}

void Input(){
    cin >> N >> M;
    Setup();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> GameBoard[i][j];
        }
    }
}

void Eliminate(){
    for(pair<int, int> p : MaxGroup){
        GameBoard[p.first][p.second] = -2; // -2를 공백으로 가정
    } Score += (MaxGroup.size() * MaxGroup.size());
    MaxGroup.clear();
}

void Rotate(){
    vector<vector<int>> Temp(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Temp[i][j] = GameBoard[j][N - i - 1];
        }
    }
    GameBoard = Temp;
}

void Gravity(){
    vector<vector<int>> Temp(N, vector<int>(N, -2));
    for(int i = 0; i < N; i++){ 
        vector<int> Sub;
        int CheckPoint = 0;
        for(int j = 0; j < N; j++){ 
            if(GameBoard[j][i] != -2 && GameBoard[j][i] != -1){
                Sub.push_back(GameBoard[j][i]);
            }
            if(GameBoard[j][i] == -1){ // -1이 아래에 존재하면 그 전까지, 없으면 맨 아래까지 떨어진다.
                for(int k = 0; k < Sub.size(); k++){
                    Temp[j - k - 1][i] = Sub[Sub.size() - k - 1];
                }
                Temp[j][i] = -1;
                CheckPoint = j + 1;
                Sub.clear();
            }
        }
        if(!Sub.empty()){
            for(int k = 0; k < Sub.size(); k++){
                Temp[N - 1 - k][i] = Sub[Sub.size() - k - 1];
            }
        }
    }
    GameBoard = Temp;
}

vector<pair<int, int>> FindMaxGroup(){
    vector<pair<int, int>> Max;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    // BFS를 통해 가장 큰 그룹 찾기
    // 크기가 가장 큰, 포함된 무지개 블록의 수가 가장 많은, 기준 블록의 행이 가장 큰, 열이 가장 큰
    int MaxSize = 0;
    int Rainbow = 0;
    int MaxRow = -1;
    int MaxCol = -1;
    
    vector<vector<bool>> Visit(N, vector<bool>(N, false));
    vector<pair<int, int>> RVisit;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(1 <= GameBoard[i][j] && !Visit[i][j]){
                Visit[i][j] = true;
                vector<pair<int, int>> cur;
                deque<pair<int, int>> dq; // x, y
                dq.push_back({i, j});
                cur.push_back({i, j});
                int CurRainbow = 0;
                int CurMaxRow = i;
                int CurMaxCol = j;
                while(!dq.empty()){
                    int px = dq.front().first;
                    int py = dq.front().second;
                    dq.pop_front();
                    for(int k = 0; k < 4; k++){
                        int nx = px + dx[k];
                        int ny = py + dy[k];
                        if(0 <= nx && nx < N && 0 <= ny && ny < N && (GameBoard[nx][ny] == 0 || GameBoard[nx][ny] == GameBoard[i][j]) && !Visit[nx][ny]){
                            if(GameBoard[nx][ny] != 0){
                                CurMaxRow = min(CurMaxRow, nx);
                                CurMaxCol = min(CurMaxCol, ny);
                            }else{
                                CurRainbow++;
                                RVisit.push_back({nx, ny});
                            } Visit[nx][ny] = true;
                            dq.push_back({nx, ny});
                            cur.push_back({nx, ny});
                        }
                    }
                }
                if(MaxSize < cur.size()){
                    Max = cur;
                    MaxSize = cur.size();
                    Rainbow = CurRainbow;
                    MaxRow = CurMaxRow;
                    MaxCol = CurMaxCol;
                }else if(MaxSize == cur.size() && Rainbow < CurRainbow){
                    Max = cur;
                    Rainbow = CurRainbow;
                    MaxRow = CurMaxRow;
                    MaxCol = CurMaxCol;
                }else if(MaxSize == cur.size() && Rainbow == CurRainbow && MaxRow < CurMaxRow){
                    Max = cur;
                    MaxRow = CurMaxRow;
                    MaxCol = CurMaxCol;
                }else if(MaxSize == cur.size() && Rainbow == CurRainbow && MaxRow == CurMaxRow && MaxCol < CurMaxCol){
                    Max = cur;
                    MaxRow = CurMaxRow;
                    MaxCol = CurMaxCol;
                }
                for(pair<int, int> p : RVisit){
                    Visit[p.first][p.second] = false;
                }
            }
        }
    }
    return Max;
}

bool Endcheck(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(GameBoard[i][j] != -1 && GameBoard[i][j] != -2 && GameBoard[i][j] != 0) return false;
        }
    } return true;
}

void Print(){
    cout << "==========\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << GameBoard[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "==========\n";
}

int main(){
    Input();
    while(true){ 
        // Print();
        MaxGroup = FindMaxGroup();
        if(MaxGroup.size() <= 1) break;
        Eliminate();
        // Print();
        Gravity();
        // Print();
        Rotate();
        // Print();
        Gravity();
        // Print();
    }
    cout << Score;
    return 0;
}