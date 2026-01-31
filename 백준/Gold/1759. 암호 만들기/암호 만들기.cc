#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;

vector<char> password;
vector<char> tmp;

void solve(int idx, int lev, int con, int vow){
    
    if(lev == L){
        if(con >= 2 && vow >= 1){
            for(char t : tmp) cout << t;
            cout << "\n";
        }
        return;
    }
    if(idx < C){
        // 현재 idx 요소를 선택하고 넘어가는 경우
        tmp.push_back(password[idx]);
        if(password[idx] == 'a' || password[idx] == 'e' || password[idx] == 'i' || password[idx] == 'o' || password[idx] == 'u'){
            solve(idx + 1, lev + 1, con, vow + 1);
        }else{
            solve(idx + 1, lev + 1, con + 1, vow);
        }
        tmp.pop_back();
        // 현재 idx 요소를 선택하지 않고 넘어가는 경우
        solve(idx + 1, lev, con, vow);   
    }
}

int main(){
    
    cin >> L >> C;
    
    password.resize(C);
    
    for(int c = 0; c < C; c++) cin >> password[c];
    
    sort(password.begin(), password.end());
    
    solve(0, 0, 0, 0);
    
    return 0;
}