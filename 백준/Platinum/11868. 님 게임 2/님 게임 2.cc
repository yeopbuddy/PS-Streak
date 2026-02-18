// 님 게임(마지막 턴이 승리) -> 그런디 수들을 구해 xor 연산
// https://www.acmicpc.net/problem/11868

#include <iostream>

using namespace std;

int main(){
    
    int n, a, v;
    cin >> n >> v;
    a = v;
    for(int i = 1; i < n; i++){
        cin >> v;
        a ^= v;
    }
    cout << (a == 0 ? "cubelover" : "koosaga");

    return 0;
}