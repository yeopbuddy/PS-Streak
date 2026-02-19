// 님 게임(마지막 턴이 승리) -> 그런디 수들을 구해 xor 연산
// 이길 수 있도록 선택할 수 있는 경우의 수
// 최종 그런디 수(각 그런디 수들의 XOR)를 구하고
// 각 요소들과 최종 그런디 수를 XOR했을 때, 최종 그런디 수보다 작은 경우만 가능(돌을 가져갈 수 있는)

// https://www.acmicpc.net/problem/16895

#include <iostream>

using namespace std;

int main(){
    
    int n;
    int g = 0;
    
    int arr[1024];
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        g ^= arr[i];
    }

    int ans = 0;
    
    for(int i = 0; i < n; i++){
        if ((g ^ arr[i]) < arr[i]) ans++;
    }

    cout << ans;
    
    return 0;
}