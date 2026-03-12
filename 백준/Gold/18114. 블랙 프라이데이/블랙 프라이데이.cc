// https://www.acmicpc.net/problem/18114
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N, C;
    cin >> N >> C;
    
    vector<int> items(N);
    
    for(int i = 0; i < N; i++) cin >> items[i];
    
    sort(items.begin(), items.end());
    
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        if(items[i] >= C){
            ans = (items[i] == C ? ans + 1 : ans);
            break;
        }else{
            int lp = i + 1; int rp = N - 1;
            while(lp < rp){ // 3개 고르기
                int cur = items[i] + items[lp] + items[rp];
                if(cur > C) --rp;
                else if(cur < C) ++lp;
                else{
                    ++ans; break;
                }
            }
            for(int j = i + 1; j < N; j++){ // 2개 고르기
                int cur = items[i] + items[j];
                if(cur >= C){
                    ans = (cur == C ? ans + 1 : ans);
                    break;
                }
            }
        }
    }
    
    cout << (ans == 0 ? 0 : 1);
}