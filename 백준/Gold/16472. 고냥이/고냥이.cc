#include <iostream>
#include <string>

using namespace std;

int N;
string S;

int status[26];

bool checkst(){
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if (status[i] > 0) ++cnt;
        if(cnt > N) return false;
    } return true;
}

int main(){
    
    cin >> N >> S;
    
    size_t SL = S.size();
    
    int lp = 0;
    int rp = 0;
    int ml = rp - lp + 1;
    
    ++status[S[lp] - 'a'];
    
    while(rp < SL - 1){ // 현재 상태는 checkst가 true인 것으로 유지한다.
        ++status[S[++rp] - 'a']; // rp를 증가시킬 때 checkst가 false가 되면, 이게 true가 될 수 있을때까지 lp를 증가시킨다.
        while(!checkst()) --status[S[lp++] - 'a']; // 아닐 경우, rp를 증가시킨다.
        ml = (ml > rp - lp + 1 ? ml : rp - lp + 1);
    }
    
    cout << ml;

    return 0;
}