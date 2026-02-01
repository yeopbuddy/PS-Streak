#include <iostream>
#include <deque>
#include <string>

using namespace std;

// 4자리 소수 여부를 판단할 bool 배열 생성
// 4자리 소수들에 방문 처리 및 변환 횟수를 지정할 int 배열 생성
// bool 배열로 소수 판단 전처리, 매번 int 배열 초기화
// BFS
int T, A, B;

bool Isprime[10000];

int Attempt[10000];

void setup(){
    
    for(int i = 2; i < 10000; i++) Isprime[i] = true;
    
    for(int i = 2; i < 10000; i++){
        for(int j = 2 * i; j < 10000; j += i){
            Isprime[j] = false;
        }
    }
}

void solve(){
    
    for(int i = 1000; i < 10000; i++) Attempt[i] = 1e9;
    
    deque<pair<int, int>> dq;
    dq.push_back({A, 0});
    Attempt[A] = 0;
    
    while(!dq.empty()){
        int pn = dq.front().first;
        int pt = dq.front().second;
        
        if(pn == B) break;
        
        dq.pop_front();
        
        string sn = to_string(pn);
        
        for(int i = 0; i < 4; i++){ // 천의 자리 수 ~ 일의 자리 수 변경
            for(int j = 0; j < 10; j++){
                int nn;
                if(i == 0){ // 천의 자리 수
                    nn = j * 1000 + (sn[1] - '0') * 100 + (sn[2] - '0') * 10 + (sn[3] - '0');
                }else if(i == 1){ // 백의 자리 수
                    nn = (sn[0] - '0') * 1000 + j * 100 + (sn[2] - '0') * 10 + (sn[3] - '0');
                }else if(i == 2){ // 십의 자리 수
                    nn = (sn[0] - '0') * 1000 + (sn[1] - '0') * 100 + j * 10 + (sn[3] - '0');
                }else{ // 일의 자리 수
                    nn = (sn[0] - '0') * 1000 + (sn[1] - '0') * 100 + (sn[2] - '0') * 10 + j;
                }
                if(1000 <= nn && Isprime[nn] && Attempt[nn] > pt + 1){
                    // cout << nn << " " << pt + 1 << "\n";
                    Attempt[nn] = pt + 1;
                    dq.push_back({nn, pt + 1});
                }
            }
        }
    }
    
    if(Attempt[B] == 1e9) cout << "Impossible\n";
    else cout << Attempt[B] << "\n";
}

int main(){
    
    setup();
    
    cin >> T;
    
    for(int t = 0; t < T; t++){
        
        cin >> A >> B; 
        
        solve();
    }

    return 0;
}