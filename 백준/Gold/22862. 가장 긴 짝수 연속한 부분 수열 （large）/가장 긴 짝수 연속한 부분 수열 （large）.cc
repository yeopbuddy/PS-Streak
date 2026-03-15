// https://www.acmicpc.net/problem/22862
#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int N, K;
    cin >> N >> K;

    vector<int> seq(N);
    
    for(int i = 0; i < N; i++) cin >> seq[i];
    
    int lp = 0;
    int rp = 0;
    int ck = ((seq[rp] % 2 == 0) ? 0 : 1);
    int ml = !ck;
    
    while(rp < N - 1){ // 현재 횟수가 최대 횟수보다 작거나 같도록 유지한다.
        ck += ((seq[++rp] % 2 == 0) ? 0 : 1);
        while(ck > K){ // 만약 rp를 증가시켰을때, 현재 횟수가 최대 횟수보다 커질 경우
            ck -= ((seq[lp++] % 2 == 0) ? 0 : 1); // lp도 증가시킨다
        }
        ml = (ml > rp - lp + 1 - ck ? ml : rp - lp + 1 - ck);
    }

    cout << ml;

    return 0;
}