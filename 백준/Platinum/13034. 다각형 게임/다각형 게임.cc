// https://www.acmicpc.net/problem/13034
// 점 N개인 상태를 하나의 게임으로 본다.
// 선분을 그으면 게임이 두 개의 독립된 더 작은 게임으로 쪼개진다.
// 쪼개진 게임들을 XOR 하고, 그 결과들의 MEX를 구하여 현재 상태의 그런디 수를 채워 나간다.

#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int n; cin >> n;
    
    int dp[1024];
    
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    
    for(int i = 3; i <= 1000; i++){
        priority_queue<int, vector<int>, greater<>> pq;
        for(int j = 0; j < i - 2; j++) pq.push(dp[j] ^ dp[i - j - 2]);
        int val = 0;
        while(!pq.empty()){
            int pt = pq.top();
            pq.pop();
            if(pt < val) continue;
            if(pt > val) break;          
            val++;                 
        }
        dp[i] = val;               
    }
    
    cout << (dp[n] == 0 ? 2 : 1);
    
    return 0;
}