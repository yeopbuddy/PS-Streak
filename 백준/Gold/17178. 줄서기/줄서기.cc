// vector를 통해 티켓 번호들을 저장
// 모두 저장했으면 순서 매기기
// queue를 통해 가능 여부 판단

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(string s1, string s2){
    char s1a = s1[0];
    char s2a = s2[0];
    
    if(s1a == s2a){
        int s1n = 0;
        int s2n = 0;
        for(size_t t = 2; t < s1.size(); t++){
            s1n *= 10;
            s1n += (s1[t] - '0');
        }
        for(size_t t = 2; t < s2.size(); t++){
            s2n *= 10;
            s2n += (s2[t] - '0');
        }
        return s1n < s2n;
    }
    
    return s1a < s2a;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<string> tickets(5*n);
    vector<string> tickets_s(5*n);
    
    for(int i = 0; i < n * 5; i++){
        cin >> tickets[i]; 
        tickets_s[i] = tickets[i];
    }
    
    sort(tickets_s.begin(), tickets_s.end(), Compare);
    
    // for(string s : tickets_s){
    //     cout << s << "\n";
    // }
    
    int turn = 0;
    vector<int> stack;
    
    for(int i = 0; i < 5 * n; i++){
        while(!stack.empty() && stack[stack.size() - 1] == turn){
            turn++; stack.pop_back();
        }
        for(int j = 0; j < 5 * n; j++){
            if(tickets[i] == tickets_s[j]){
                if(turn != j) stack.push_back(j);
                else turn++;
                break;
            }
        }
    }
    
    while(!stack.empty() && stack[stack.size() - 1] == turn){
        turn++; stack.pop_back();
    }

    cout << (stack.size() == 0 ? "GOOD" : "BAD");
    
    return 0;
}