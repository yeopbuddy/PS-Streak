#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    int N, K;
    cin >> N >> K;
    
    vector<int> slens(N);
    
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        slens[i] = s.size();
    }
    
    // setup
    int clens[21];
    for(int i = 0; i < 21; i++) clens[i] = 0;
    
    for(int i = 1; i <= K && i < N; i++) clens[slens[i]]++;
    
    long long Ans = 0;
    
    // cal
    for(int i = 0; i < N; i++){
        Ans += clens[slens[i]];
        if(i + 1 < N) clens[slens[i + 1]]--;
        if(i + K + 1 < N) clens[slens[i + K + 1]]++;
    }
    
    cout << Ans;
    
    return 0;
}