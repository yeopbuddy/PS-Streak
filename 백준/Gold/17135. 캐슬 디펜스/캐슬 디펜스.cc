// https://www.acmicpc.net/problem/17135

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Archer[3][2];
int CmpFlag;

bool Compare(pair<int, int> p1, pair<int, int> p2){
    
    int d1, d2;
    int p1x = p1.first;
    int p1y = p1.second;
    int p2x = p2.first;
    int p2y = p2.second;
    
    if(CmpFlag == 1){
        d1 = abs(p1x - Archer[0][0]) + abs(p1y - Archer[0][1]);
        d2 = abs(p2x - Archer[0][0]) + abs(p2y - Archer[0][1]);
        if(d1 == d2){
            return p1y < p2y;
        }return d1 < d2;
    }else if(CmpFlag == 2){
        d1 = abs(p1x - Archer[1][0]) + abs(p1y - Archer[1][1]);
        d2 = abs(p2x - Archer[1][0]) + abs(p2y - Archer[1][1]);
        if(d1 == d2){
            return p1y < p2y;
        }return d1 < d2;
    }else{
        d1 = abs(p1x - Archer[2][0]) + abs(p1y - Archer[2][1]);
        d2 = abs(p2x - Archer[2][0]) + abs(p2y - Archer[2][1]);
        if(d1 == d2){
            return p1y < p2y;
        }return d1 < d2;
    }
}

int main(){
    
    int N, M, D;
    cin >> N >> M >> D;
    
    vector<vector<int>> Map(N, vector<int>(M));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }

    int Ans = 0;

    for(int i = 0; i < M; i++){
        for(int j = i + 1; j < M; j++){
            for(int k = j + 1; k < M; k++){
                for(int l = 0; l < 3; l++) Archer[l][0] = N;
                Archer[0][1] = i;
                Archer[1][1] = j;
                Archer[2][1] = k; // 궁수 셋업
                int elim = 0; // 제거하는 적의 수 저장할 변수 선언
                vector<vector<int>> Array = Map; // 배열 복사
                // for(int x = 0; x < 3; x++){
                //     cout <<"Ar" << x + 1 << " - " << Archer[x][0] << " " << Archer[x][1] << "\n";
                // }
                while(true){ // 여기서 WHILE문 시작 TRUE
                    bool End = true; // 종료 조건 검사 / BREAK
                    for(int x = 0; x < N; x++){
                        for(int y = 0; y < M; y++){
                            if(Array[x][y] == 1) End = false;
                        }
                    }
                    
                    if(End) break;
                    // 공격, 이동
                    vector<pair<int, int>> Ar1; // 궁수 1이 공격할 좌표
                    vector<pair<int, int>> Ar2; // 궁수 2가 공격할 좌표
                    vector<pair<int, int>> Ar3; // 궁수 3이 공격할 좌표
                    
                    for(int x = 0; x < N; x++){
                        for(int y = 0; y < M; y++){
                            if(Array[x][y] == 1){
                                if (abs(x - Archer[0][0]) + abs(y - Archer[0][1]) <= D) Ar1.push_back({x, y});
                                if (abs(x - Archer[1][0]) + abs(y - Archer[1][1]) <= D) Ar2.push_back({x, y});
                                if (abs(x - Archer[2][0]) + abs(y - Archer[2][1]) <= D) Ar3.push_back({x, y});
                            }
                        }
                    }
                    
                    CmpFlag = 1; sort(Ar1.begin(), Ar1.end(), Compare);
                    CmpFlag = 2; sort(Ar2.begin(), Ar2.end(), Compare);
                    CmpFlag = 3; sort(Ar3.begin(), Ar3.end(), Compare);
                    
                    // 공격
                    if(!Ar1.empty()){
                        // cout << "Ar1 not Emp!\n";
                        if(Array[Ar1[0].first][Ar1[0].second] == 1) elim++;
                        Array[Ar1[0].first][Ar1[0].second] = 0;
                    }
                    if(!Ar2.empty()){
                        // cout << "Ar2 not Emp!\n";
                        if(Array[Ar2[0].first][Ar2[0].second] == 1) elim++;
                        Array[Ar2[0].first][Ar2[0].second] = 0;
                    }
                    if(!Ar3.empty()){
                        // cout << "Ar3 not Emp!\n";
                        if(Array[Ar3[0].first][Ar3[0].second] == 1) elim ++;
                        Array[Ar3[0].first][Ar3[0].second] = 0;
                    }
                    // 이동
                    for(int x = N - 1; x >= 0; x--){
                        for(int y = 0; y < M; y++){
                            if(Array[x][y] == 1){
                                if(x == N - 1){
                                    Array[x][y] = 0;
                                }else{
                                    Array[x][y] = 0;
                                    Array[x + 1][y] = 1;
                                }
                            }
                        }
                    }
                }
                Ans = max(Ans, elim); // Ans max값 최신화
            }
        }
    }
    
    cout << Ans;

    return 0;
}