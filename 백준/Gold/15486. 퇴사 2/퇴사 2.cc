// 언제쓸지모르는스트릭
// https://www.acmicpc.net/problem/15486

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N; cin >> N;
    
    int Ans = 0;
    
    vector<vector<int>> Meeting(2, vector<int>(N));
    vector<int> Dp(N + 1, 0);
    
    for(int i = 0; i < N; i++){
        cin >> Meeting[0][i] >> Meeting[1][i];
    }
    
    for(int i = 0; i < N; i++){
        if(i + Meeting[0][i] <= N){
            Dp[i + Meeting[0][i]] = max(Dp[i + Meeting[0][i]], Meeting[1][i] + Dp[i]);
        }
        Dp[i + 1] = max(Dp[i + 1], Dp[i]);
        Ans = max(Dp[i + 1], Ans);
    }
    
    cout << Ans;
}