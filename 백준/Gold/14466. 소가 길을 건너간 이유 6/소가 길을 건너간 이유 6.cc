#include <iostream>
#include <deque>
#include <tuple>

using namespace std;

int N, K, R, R1, C1, R2, C2;    

bool CrossWalk[101][101][4]; // up, down, right, left

int Cow[2][101];
int Link[101][101];

int main(){
    
    cin >> N >> K >> R;
    
    for(int r = 0; r < R; r++){
        cin >> R1 >> C1 >> R2 >> C2;
        if(R1 == R2)
            if(C1 < C2) CrossWalk[R2][C2][3] = CrossWalk[R1][C1][2] = true;
            else CrossWalk[R2][C2][2] = CrossWalk[R1][C1][3] = true;
        else
            if(R1 < R2) CrossWalk[R2][C2][0] = CrossWalk[R1][C1][1] = true;
            else CrossWalk[R2][C2][1] = CrossWalk[R1][C1][0] = true;
    }
    
    for(int k = 0; k < K; k++){
        cin >> Cow[0][k] >> Cow[1][k];
    }
    
    int Cowidx = 0;
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            Link[i][j] = -1;
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(Link[i][j] == -1){
                deque<tuple<int, int, int>> dq;
                dq.push_back({i, j, Cowidx});
                Link[i][j] = Cowidx;
                while(!dq.empty()){
                    int px, py, pi;
                    tie(px, py, pi) = dq.front();
                    dq.pop_front();
                    for(int k = 0; k < 4; k++){
                        int nx = px + dx[k];
                        int ny = py + dy[k];
                        if(0 < nx && nx <= N && 0 < ny && ny <= N && Link[nx][ny] == -1 && !CrossWalk[px][py][k]){
                            Link[nx][ny] = Cowidx;
                            dq.push_back({nx, ny, Cowidx});
                        }
                    }
                } ++Cowidx;
            }
        }
    }
    
    int Answer = 0;
    
    for(int k1 = 0; k1 < K; k1++){
        for(int k2 = k1 + 1; k2 < K; k2++){
            if(Link[Cow[0][k1]][Cow[1][k1]] != Link[Cow[0][k2]][Cow[1][k2]]) Answer++;
        }
    }

    cout << Answer;

    return 0;
}