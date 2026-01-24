#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    
    int T; cin >> T;
    
    for(int t = 0; t < T; t++){
        string cmd; cin >> cmd;
        int n; cin >> n;
        string s = "";
        char c;
        deque<int> dq;
        while(true){
            cin >> c;
            if(c == ']'){
                if(s.size() > 0) dq.push_back(stoi(s));
                break;
            }else if(c == ','){
               dq.push_back(stoi(s));
               s = "";
            }else if('0' <= c && c <= '9'){
                s += c;
            }
        }
        bool err = false;
        bool reversed = false;
        for(char cm : cmd){
            if(cm == 'R'){
                reversed = !reversed;
            }else{
                if(dq.empty()){
                    err = true;
                    break;
                }
                if(!reversed){
                    dq.pop_front();
                }else{
                    dq.pop_back();
                }
            }
        }
        if(err){
            cout << "error\n";
        }else{
            cout << '[';
            if(!reversed){
                for(int d = 0; d < (int)dq.size() - 1; d++){
                    cout << dq[d] << ",";
                }
                if(!dq.empty()) cout << dq[dq.size() - 1];
            }else{
                for(int d = (int)dq.size() - 1; d > 0; d--){
                    cout << dq[d] << ",";
                }
                if(!dq.empty()) cout << dq[0];
            }
            cout << "]\n";
        }
    }

    return 0;
}