// 미제레-님 게임
// 기본 님 게임(마지막 턴이 승리) -> 그런디 수들을 구해 xor 연산
// 미제레-님 게임(마지막 턴이 패배) -> 기본 로직 + 1의 더미만 주어진 경우 추가 전략

// https://www.acmicpc.net/problem/11694

#include <iostream>

using namespace std;

int main(){
    
    int n, a, v, c;
    c = 0;
    cin >> n >> v;
    a = v;
    if(v == 1) c++;
    for(int i = 1; i < n; i++){
        cin >> v;
        if(v == 1) c++;
        a ^= v;
    }
    if(n == c){
        cout << (n % 2 == 1 ? "cubelover" : "koosaga");
    } else cout << (a == 0 ? "cubelover" : "koosaga");

    return 0;
}