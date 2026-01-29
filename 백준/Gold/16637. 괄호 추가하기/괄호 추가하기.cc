#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n; string s;

long long ans = -1e17;

vector<int> idxs;

void cal(){
    bool pass = false;
    int cur = 0;
    int oidx = 0;
    if(n == 1) cur = s[0] - '0';
    else{
        for(int i = 0; i < n; i += 2){
            if(pass){
                pass = false; continue;
            }
            if(i == 0){
                if(idxs[oidx] == i){
                    if(s[i + 1] == '+'){
                        cur = (s[i] - '0') + (s[i + 2] - '0');
                    }else if(s[i + 1] == '-'){
                        cur = (s[i] - '0') - (s[i + 2] - '0');
                    }else{
                        cur = (s[i] - '0') * (s[i + 2] - '0');
                    }
                    pass = true; oidx += 2;
                }else{
                    cur = s[i] - '0';
                }
            }else{
                if(oidx < idxs.size() && idxs[oidx] == i){
                    int tmp = s[i] - '0';
                    if(s[i + 1] == '+'){
                        tmp += (s[i + 2] - '0');
                    }else if(s[i + 1] == '-'){
                        tmp -= (s[i + 2] - '0');
                    }else{
                        tmp *= (s[i + 2] - '0');
                    }
                    if(s[i - 1] == '+'){
                        cur += tmp;
                    }else if(s[i - 1] == '-'){
                        cur -= tmp;
                    }else{
                        cur *= tmp;
                    }
                    pass = true; oidx += 2;
                }else{
                    if(s[i - 1] == '+'){
                        cur += (s[i] - '0');
                    }else if(s[i - 1] == '-'){
                        cur -= (s[i] - '0');
                    }else{
                        cur *= (s[i] - '0');
                    }
                }
            }
        }   
    }
    ans = ans > cur ? ans : cur;
}

void gen(int cur, bool open){
    if(cur > n){
        if(!open){
            cal();
        }
        return;
    }
    if(open){
        idxs.push_back(cur - 1);
        gen(cur + 2, false);
        idxs.pop_back();
    }else{
        if(cur < n){
            idxs.push_back(cur - 1);
            gen(cur + 2, true);
            idxs.pop_back();
        }
    }
    gen(cur + 2, open);
}

int main(){
    // 수식의 길이를 기반으로 괄호를 넣을 수 있는 위치들을 계산
        // 먼저 계산할 수 있는 것들을 계산
    cin >> n >> s;
    gen(1, false);
    cout << ans;
    return 0;
}