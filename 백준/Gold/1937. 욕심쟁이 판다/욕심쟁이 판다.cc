#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool Compare(tuple<int, int, int> t1, tuple<int, int, int> t2){
    return get<2>(t1) < get<2>(t2);
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int N; cin >> N;
    
    int Ans = 0;
    
    vector<vector<int>> Bamboo(N, vector<int>(N));
    vector<vector<int>> Dp(N, vector<int>(N, 1));
    vector<tuple<int, int, int>> Coords;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Bamboo[i][j];
            Coords.push_back(make_tuple(i, j, Bamboo[i][j]));
        }
    }
    
    sort(Coords.begin(), Coords.end(), Compare);

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    for(int i = 0; i < Coords.size(); i++){
        int px = get<0>(Coords[i]);
        int py = get<1>(Coords[i]);
        int p_val = get<2>(Coords[i]);

        for(int k = 0; k < 4; k++){
            int nx = px + dx[k];
            int ny = py + dy[k];

            if(0 <= nx && nx < N && 0 <= ny && ny < N){
                if(Bamboo[nx][ny] > p_val){
                    if(Dp[nx][ny] < Dp[px][py] + 1){
                        Dp[nx][ny] = Dp[px][py] + 1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Ans < Dp[i][j]) Ans = Dp[i][j];
        }
    }

    cout << Ans;

    return 0;
}