// https://www.acmicpc.net/problem/7490

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, N;
vector<vector<char>> Oper;

void Make(vector<char> Cur, int c, int l){
    if(c == l - 1){
        Oper.push_back(Cur);
        return;
    }
    Cur.push_back(' ');
    Make(Cur, c + 1, l);
    Cur.pop_back();
    Cur.push_back('+');
    Make(Cur, c + 1, l);
    Cur.pop_back();
    Cur.push_back('-');
    Make(Cur, c + 1, l);
    Cur.pop_back();
    return;
}

void Set(){
    Oper.clear();
    vector<char> St;
    Make(St, 0, N);
}

int main(){
    
    cin >> T;
    
    for(int t = 0; t < T; t++){
        
        cin >> N;
        
        vector<char> Nums(N);
        Nums[0] = '1';
        
        Set();
        
        for(int i = 1; i < N; i++) Nums[i] = Nums[i - 1] + 1;
        
        for(int i = 0; i < Oper.size(); i++){
            string s = "";
            for(int j = 0; j < N - 1; j++){
                s += Nums[j];
                if(Oper[i][j] != ' ') s += Oper[i][j];
            } s += Nums[N - 1];
            // cout << s << "\n";
            int Num1 = -999999999;
            int Num2 = -999999999;
            char Op = ' ';
            // cout << s << "\n";
            for(char c : s){
                if(c == '+' || c == '-'){
                    if(Num1 != -999999999 && Num2 != -999999999){
                        if(Op == '+'){
                            Num1 += Num2;
                        }else{
                            Num1 -= Num2;
                        }
                        Num2 = -999999999;
                    } Op = c;
                }else{
                    if(Num1 == -999999999){
                        Num1 = c - '0';
                    }else if(Num1 != -999999999 && Op == ' '){
                        Num1 *= 10;
                        Num1 += c - '0';
                    }else if(Num2 == -999999999){
                        Num2 = c - '0';
                    }else{
                        Num2 *= 10;
                        Num2 += c - '0';
                    }
                }
                // cout << Num1 << " " << Op << " " << Num2 << "\n";
            }if(Op != ' '){
                if(Op == '+'){
                    Num1 += Num2;
                }else{
                    Num1 -= Num2;
                }
            }
            // if(Num1 == 0) cout << s << " = " << Num1 << "\n";
            if(Num1 == 0){
                for(int c = 0; c < s.size() - 1; c++){
                    cout << s[c];
                    if('1' <= s[c] && s[c] <= '9' && '1' <= s[c + 1] && s[c + 1] <= '9') cout << " ";
                }
                cout << s[s.size() - 1] << "\n";
            }
        }
        cout << "\n";
    }
    
    return 0;
}